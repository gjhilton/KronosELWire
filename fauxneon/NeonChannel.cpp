#include "NeonChannel.h"

const long DEFAULT_DELAY = 1000;

NeonChannel::NeonChannel(String _name, int _pin){
	name = _name;
	pin = _pin;
	on = false;
	delayUntilToggleOff = DEFAULT_DELAY;
	delayUntilToggleOn = DEFAULT_DELAY;
	nextEventMillis = 0;
}

void NeonChannel::begin(){
	pinMode(pin, OUTPUT);
	msg("begin");
}

void NeonChannel::loop(){
	if (nextEventMillis <= millis()){
		toggle();
		msg("action");
	} else {
		msg("wait");
	}
}

void NeonChannel::scheduleNext(long ms){
	nextEventMillis = millis() + ms;
}

void NeonChannel::toggle(){
	if (on){
		turnOff();
		scheduleNext(delayUntilToggleOn);
	} else {
		turnOn();
		scheduleNext(delayUntilToggleOff);
	}
}

void NeonChannel::setToggleDelay(int untilOn, int untilOff){
	delayUntilToggleOff = untilOn;
	delayUntilToggleOn = untilOff;
}

void NeonChannel::turnOn(){
	digitalWrite(pin, HIGH);
	on = true;
}

void NeonChannel::turnOff(){
	digitalWrite(pin, LOW);
	on = false;
}

void NeonChannel::msg(String s, bool newline){
	s = name + "[" + String(pin) + ", " + (on ? "ON" : "off")  + "] -> " + s;
	if (newline) s = s + "\n";
	Serial.print(s);
}