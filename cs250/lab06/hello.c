#include <p18cxxx.h>

#pragma config WDT=OFF // disable watchdog timer
#pragma config MCLRE = ON// MCLEAR Pin on
#pragma config DEBUG = ON// Enable Debug Mode
#pragma config LVP = OFF// Low-Voltage programming disabled (necessary for debugging)
#pragma config FOSC = INTOSC_EC // High Speed

void main()
{
	int i;
	int j;
	
    while (1)
	{
		TRISD = 0x0;
    	
		for (i = 0; i < 3; i++)
		{
			PORTD = 0xFF;
			for (j = 0; j < 10000; j++)
			{
				// do nothing
			}
	
			PORTD = 0x00;
			for (j = 0; j < 10000; j++)
			{
				// do nothing
			}
		}

		for (i = 0; i < 3; i++)
		{
			PORTD = 0xFF;
			for (j = 0; j < 3000; j++)
			{
				// do nothing
			}
	
			PORTD = 0x00;
			for (j = 0; j < 3000; j++)
			{
				// do nothing
			}
		}

		for (i = 0; i < 3; i++)
		{
			PORTD = 0xFF;
			for (j = 0; j < 10000; j++)
			{
				// do nothing
			}
	
			PORTD = 0x00;
			for (j = 0; j < 10000; j++)
			{
				// do nothing
			}
		}
	}
} 