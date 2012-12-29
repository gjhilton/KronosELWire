#ifndef __fauxneon__NeonChannel__
#define __fauxneon__NeonChannel__

#include "Arduino.h"

class NeonChannel{

public:
	
    NeonChannel(String _name, int _pin);

	void begin();
	void loop();

	void toggle();
	void turnOn();
	void turnOff();

private:
	
	boolean on;
	int pin;
	String name;
	void msg(String s, bool newline = true);
};

#endif
