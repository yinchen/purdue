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

// Program to turn on and off all segments of the display

void main(void) {

    // Make PORTB and PORTD outputs
    TRISB = 0;
    TRISD = 0;

    // Turn on all segments
    PORTD = 0xFF;
    PORTB = 0x00;

    while(1) {
        unsigned int i,j;

        // Delay
        for (j=0; j<0x2; j++) {
            for (i=0; i<0xFFFF; i++) {
            }
        }

        // Turn on and off display
        PORTD = ~PORTD;

    }
}
