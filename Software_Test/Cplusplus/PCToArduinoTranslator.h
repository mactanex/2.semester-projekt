#pragma once
class PCToArduinoTranslator
{
	enum command
	{
		TOGGLE = 0b11111111,
		TURN_OFF = 0b11110000,
		TURN_ON = 0b00001111
	};
public:
	PCToArduinoTranslator();
	void TranslateMessage(int ID, command);
	~PCToArduinoTranslator();
};

