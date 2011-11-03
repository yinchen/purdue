
#include <p18cxxx.h>

// Configuration flags
#pragma config PLLDIV   = 5         // (20 MHz crystal)
#pragma config CPUDIV   = OSC1_PLL2   
#pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = ON
#pragma config BORV     = 3
#pragma config VREGEN   = ON      //USB Voltage Regulator
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
#pragma config STVREN   = ON
#pragma config LVP      = OFF
#pragma config XINST    = OFF       // Extended Instruction Set

// Initialize Analog to digital converter used to read thermometer.
void
init_AD(void) {

    // Enabled AD0 and AD1
    ADCON1 = 0x0D;

    // Select AD0
    ADCON0 = 0x0;
    
    // A/D Acquisition Time Select bits 2 TADs
    ADCON2 = 0x8;

    // A/D converter module is enabled
    ADCON0bits.ADON = 1;
}

double readTemperature(void) {
    double v0;
    double tc;
    double tf;

    // Start conversion of analog to digital
    ADCON0bits.GO_DONE = 1;

    // Wait until conversion is done.
    while (ADCON0bits.GO_DONE);

    // Convert voltage to 0-5V
    v0 = 5.0*(ADRES>>6)/0x3FF; 

    // Translate from voltage to temperature in centigrade
    tc = (v0-.424)/.00625;

    // Translate from centigrade to farenheit
    tf = (tc * 1.8) +32;

    return tf;
}

double temp;

//                            0           1           2           3           4           5           6           7           8           9
unsigned char DIGIT[] = { 0B00111111, 0B00000110, 0B01011011, 0B01001111, 0B01100110, 0B01101101, 0B01111101, 0B00000111, 0B01111111, 0B01101111 };
void printTemperature(int val) {
	// Put the corresponding character in PORTD
    // Notice that to turn on the digit we need to put
    // a 1 in the bit we want to turn on.
    PORTD = DIGIT[val];
}

// Program to read temperature
void main(void) {

    init_AD();

	// Make PORTB and PORTD outputs
    TRISB = 0;
    TRISD = 0;

    // Initialize
    PORTD = 0xFF;
    PORTB = 0x00;

    while (1) {
        temp = readTemperature();

        // Print temperature
		printTemperature(9);
    }
}
