#include "NeonChannel.h"

NeonChannel::NeonChannel(String _name, int _pin){
	name = _name;
	pin = _pin;
	on = false;
}

void NeonChannel::begin(){
	pinMode(pin, OUTPUT);
	msg("begin");
}

void NeonChannel::loop(){
	msg("loop");
}

void NeonChannel::toggle(){
	if (on){
		turnOn();
	} else {
		turnOff();
	}
}

void NeonChannel::turnOn(){
	digitalWrite(pin, HIGH);
	on = true;
	msg("on");
}

void NeonChannel::turnOff(){
	digitalWrite(pin, LOW);
	on = false;
	msg("off");
}

void NeonChannel::msg(String s, bool newline){
	s = name + "[" + String(pin) + ", " + (on ? "ON" : "off")  + "] -> " + s;
	if (newline) s = s + "\n";
	Serial.print(s);
}