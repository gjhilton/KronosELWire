#include "NeonChannel.h"

NeonChannel greenarrow("Green Arrow",2);
NeonChannel karaoke("Karaoke",3);
NeonChannel martini("Martini",4);
NeonChannel cocktail("Cocktail",5);
NeonChannel yellowarrow("Fly in arrow",6);
NeonChannel flyin("Fly in ",7);

void setup() {                
	Serial.begin(9600);
	
	karaoke.setToggleDelay(5000,1000);
	martini.setToggleDelay(2000,3000);
	yellowarrow.setToggleDelay(1000,3000);	
	//greenarrow.crackleMode();
	
	karaoke.begin();
	greenarrow.begin();
	martini.begin();
	cocktail.begin();
	yellowarrow.begin();
	flyin.begin();
}

void loop() {
	karaoke.loop();
	greenarrow.loop();
	martini.loop();
	cocktail.loop();
	yellowarrow.loop();
	flyin.loop();
	delay(50);
}