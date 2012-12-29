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

	void scheduleNext(long ms);
	
	void setToggleDelay(int untilOn, int untilOff);

private:
	
	boolean on;
	int pin;
	int delayUntilToggleOff;
	int delayUntilToggleOn;
	String name;
	void msg(String s, bool newline = true);
	long nextEventMillis;
	long toWholeSecond(long n);
};

#endif
