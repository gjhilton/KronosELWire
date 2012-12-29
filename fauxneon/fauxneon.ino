#include "NeonChannel.h"

NeonChannel greenarrow("Green Arrow",2);
NeonChannel karaoke("Karaoke",3);
NeonChannel martini("Martini",4);
NeonChannel cocktail("Cocktail",5);
NeonChannel yellowarrow("Fly in arrow",6);
NeonChannel flyin("Fly in ",7);

void setup() {                
	//Serial.begin(9600);
	
	greenarrow.setToggleDelay(3000,1000);
	karaoke.crackleMode();
	martini.setToggleDelay(2000,1000);
	cocktail.crackleMode();
	yellowarrow.setToggleDelay(3000,1000);
	flyin.setToggleDelay(5000,1000);	
	
	
	greenarrow.begin();
	karaoke.begin();
	martini.begin();
	cocktail.begin();
	yellowarrow.begin();
	flyin.begin();
}

void loop() {
	greenarrow.loop();
	karaoke.loop();
	martini.loop();
	cocktail.loop();
	yellowarrow.loop();
	flyin.loop();
	
	delay(50);
}