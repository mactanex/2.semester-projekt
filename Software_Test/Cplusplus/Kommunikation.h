#pragma once
#include <iostream>
#include "Serial.h"

using namespace std;

typedef enum PROTOCOL { TOGGLE = 0b11111111, TURN_OFF = 0b11110000, TURN_ON = 0b00001111 };
class Kommunikation
{
	

public:
	Kommunikation(int,int);
	~Kommunikation();
	unsigned char * ComposeMessage(int ID,PROTOCOL);
	int send(const unsigned char *buffer, int size);
	int read( char *buffer, int size);
	bool readyToRead(int);
private:
	CSerial * handle_;
};

