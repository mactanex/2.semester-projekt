#include <iostream>
#include "Kommunikation.h"

using namespace std;

int main()
{
	char input;
	char input2;
	char * readBuffer;
	Kommunikation toggleDevice(4, 9600);

	const int size = 2;
	unsigned char data[2];
	
	unsigned char * charPtr;
	 
	//testing
	unsigned char * testCharPtr;
	unsigned char testData[2];
	testCharPtr = toggleDevice.ComposeMessage(6, TURN_OFF); //id = 6
	for (size_t i = 0; i < 2; i++)
	{
		testData[i] = *testCharPtr;
		testCharPtr++;
	}
	toggleDevice.send(testData, 2);
	//end of testing
	
	while (true)
	{
		//this software can control the led's on an arduino
		cout << "this software can control the LED's on an arduino." << endl;
		cout << "there is overall 3 commands: 't' = Toggle LED, '1' = Turn everything on, '2' = Turn everything off " << endl;

		cin >> input;
		if (input == 't')
		{
			cout << "select LED number from 0-7: ";
			cin >> input2;
			charPtr = toggleDevice.ComposeMessage(int(input2), TOGGLE);
		}
		if (input == '1')
		{
			charPtr = toggleDevice.ComposeMessage(7, TURN_ON);
		}
		if (input == '2')
		{
			charPtr = toggleDevice.ComposeMessage(7, TURN_OFF);
		}
		for (size_t i = 0; i < 2; i++)
		{
			data[i] = *charPtr;
			charPtr++;
		}
		
		
		toggleDevice.send(data, size);
			cout << "message[0]: " << data[0] << " message[1]: " << data[1] << endl;
		
	}
	return 0;
}