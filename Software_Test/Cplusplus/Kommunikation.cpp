#include "Kommunikation.h"
#include "Serial.h"
#include <bitset>
#include <stdlib.h>


Kommunikation::Kommunikation(int portNr, int baudRate)
{

	handle_ = new CSerial;
	if (handle_ -> Open(portNr, baudRate))
		cout <<"Port opened successfully" << endl;
	else
		cout << "Failed to open port!" << endl;

}

Kommunikation::~Kommunikation()
{
	delete handle_;
}

unsigned char *  Kommunikation::ComposeMessage(int ID, PROTOCOL myProtocol)
{
	unsigned char binaryCommand = myProtocol;
	unsigned char tempArr[2];
	

	unsigned char message[2];//= { (char)ID, (char) binaryCommand };
	message[0] = (ID<<4) | (binaryCommand>>4);

	message[1] =   binaryCommand<<4;




	return  message;
}

int Kommunikation::send(const unsigned char * buffer, int size)
{
		int nBytesSent = handle_ ->SendData(buffer, size);
		if (nBytesSent != size)
		{
			cout << "not all data was sent.." << endl;
		}
	return nBytesSent;
}

int Kommunikation::read(char * buffer, int size)
{
	int nBytesRead = handle_ ->ReadData(buffer, size);
	return nBytesRead;
}

bool Kommunikation::readyToRead(int sizeOfData)
{
	int dataWaiting = handle_->ReadDataWaiting();
	if (sizeOfData == dataWaiting)
	{
		//cout << "everything was received correctly!" << endl;
		return true;
	}
	else
	{
		//cout << "something went wrong receiving data" << endl;
		return false;
	}
}
