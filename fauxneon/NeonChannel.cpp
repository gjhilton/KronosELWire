#include "NeonChannel.h"

const long DEFAULT_DELAY = 1000;
const int DEFAULT_CRACKLE_FLICKER_TIME = 600;

NeonChannel::NeonChannel(String _name, int _pin){
	name = _name;
	pin = _pin;
	on = false;
	delayUntilToggleOff = DEFAULT_DELAY;
	delayUntilToggleOn = DEFAULT_DELAY;
	nextEventMillis = 0;
	doCrackle = false;
	crackleFlickerTime = DEFAULT_CRACKLE_FLICKER_TIME;
}

void NeonChannel::begin(){
	pinMode(pin, OUTPUT);
}

void NeonChannel::loop(){
	if (nextEventMillis <= millis()){
		if (doCrackle){
			crackle();
		} else {
			toggle();
		}
	}
}

void NeonChannel::scheduleNext(long ms){
	nextEventMillis = toWholeSecond(millis()) + ms;
}

void NeonChannel::crackle(){
	if (on) {
		if (random(4) < 1){
			// - either a loooong stable period before the next cracklage
			scheduleNext(random(10000,60000));
		} else {
			// - or a short flicker delay 
			turnOff();
			scheduleNext(random(crackleFlickerTime/2));
		}
	} else {
		turnOn();
		scheduleNext(random(crackleFlickerTime));
	}
}

void NeonChannel::crackleMode(bool b){
	doCrackle = b;
	if (doCrackle) turnOn();
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

long NeonChannel::toWholeSecond(long n){
	return round(n / 1000.0) * 1000;
}

void NeonChannel::msg(String s, bool newline){
	s = name + "[" + String(pin) + ", " + (on ? "ON" : "off")  + "] -> " + s;
	if (newline) s = s + "\n";
	// Serial.print(s);
}