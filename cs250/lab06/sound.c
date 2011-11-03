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

// Program to produce simple sounds
// We assume speaker is connected with capacitor to PORTE
// bit 0

void main(void) {

    // First we need to make PORTE not to be an analog input
    ADCON1 = 0x0D;

    // Now make PORTE bit 0 to be an output
    TRISEbits.TRISE0 = 0;
    PORTEbits.RE0 = 0;

    while(1) {
        unsigned int i;

// Try different values of delay and see what happens
//#define DELAY_SOUND 200
//#define DELAY_SOUND 500
//#define DELAY_SOUND 1000
#define DELAY_SOUND 2000
        for (i=0; i<DELAY_SOUND; i++) {
        }

        // Turn on and off speaker connected to bit 0 of port E
        PORTEbits.RE0 = !PORTEbits.RE0;
    }
}
