#include "NeonChannel.h"

NeonChannel greenarrow("Green Arrow",2);
NeonChannel karaoke("Karaoke",3);

void setup() {                
	Serial.begin(9600);
	
	karaoke.setToggleDelay(5000,1000);	
	greenarrow.crackleMode();
	
	karaoke.begin();
	greenarrow.begin();
}

void loop() {
	karaoke.loop();
	greenarrow.loop();
	delay(50);
}