/*
 * seriel_kommunikation_arduino_delen.c
 *
 * Created: 10-04-2017 06:08:57
 *  Author: Malthe
 */ 


#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "led.h"
#include "switch.h"
#include "ArduinoFromPc.h"


int main(void)
{
	unsigned char ReceivedMessage[2]; //the message received is 2 unsigned chars, 
	unsigned char testMessage[2];
	
	testMessage[0] = 0b00111111; //test purposes: ID number 3; toggle;
	testMessage[1] = 0b11110001; //test purposes: endBit[4];
	
	
	InitUART(9600,8,'N');
	initLEDport();
	initSwitchPort();
	
	//messageDecoder(testMessage);
	

	int index = 0;
    while(1)
    {

		while (CharReady() != 0 )		
       {	
				ReceivedMessage[index]	= ReadChar();
				index++;
				
				if (index == 2)
				{
					index = 0;
					messageDecoder(ReceivedMessage);
				}				

	   }

    }
	return 0;
}
