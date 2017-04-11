/*
 * ArduinoToPc.c
 *
 * Created: 10-04-2017 14:53:04
 *  Author: Malthe
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArduinoFromPc.h"

//#include "led.h"



void messageDecoder(unsigned char message[])
{
		
	unsigned char IDBuffer = message[0] >> 4;
											
	unsigned char binaryCommand = message[0] << 4 | message[1] >> 4;
	
	sendCommand(IDBuffer,binaryCommand);
	

}


void sendCommand(unsigned char ID, unsigned char myCommand)
{
	if (myCommand == 0b11111111) //toggle
	{
		toggleLED(ID);
	}
	if (myCommand == 0b11110000) //turn off
	{
		writeAllLEDs(0b00000000);
	}
	if (myCommand == 0b00001111) //turn on
	{
		writeAllLEDs(0b11111111);
	}
	

}