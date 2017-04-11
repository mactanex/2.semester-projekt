/*
 * ArduinoToPc.h
 *
 * Created: 10-04-2017 14:53:33
 *  Author: Malthe
 */ 


#ifndef ARDUINOFROMPC_H_
#define ARDUINOFROMPC_H_

void messageDecoder(unsigned char message[]);
//unsigned char stringToBinary(char tmpSubjectStatus[])
void sendCommand(unsigned char ID, unsigned char myCommand);




#endif /* ARDUINOTOPC_H_ */