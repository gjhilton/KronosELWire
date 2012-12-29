#include "NeonChannel.h"

NeonChannel greenarrow("Green Arrow",2);
NeonChannel karaoke("Karaoke",3);

void setup() {                
	Serial.begin(9600);
	
	karaoke.begin();
	karaoke.toggle();
	greenarrow.begin();
}

void loop() {
	karaoke.loop();
	greenarrow.loop();
	delay(1000);
}