#define _PRINT_SERIAL
#ifdef _PRINT_SERIAL
	#define PRINT(x) Serial.print(x);
#else
	#define PRINT(x) // noop
#endif

const int CHANNELA = 2;

void setup() {                

	#ifdef _PRINT_SERIAL
		Serial.begin(9600);
	#endif

  pinMode(2, OUTPUT);  // channel A  - green
  pinMode(3, OUTPUT);  // channel B  - red
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

}

void loop() {
	PRINT("loop ");
	PRINT(millis());
	PRINT("\n");
	
  int x = 3;
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(500);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off
	delay(10000);
	
}

/*
// #define _PRINT_SERIAL
#ifdef _PRINT_SERIAL
	#define PRINT(x) Serial.println(x);
#else
	#define PRINT(x) // noop
#endif

const int CHANNEL_A = 2; // green
const int CHANNEL_B = 3; // red
const int CHANNEL_C = 4;
const int CHANNEL_D = 5;
const int CHANNEL_E = 6;
const int CHANNEL_F = 7;
const int CHANNEL_G = 8;
const int CHANNEL_H = 9;
const int N_CHANNELS = 8;
int channels[] = {CHANNEL_A,CHANNEL_B,CHANNEL_C,CHANNEL_D,CHANNEL_E,CHANNEL_F,CHANNEL_G,CHANNEL_H}; 

void setup() {                

#ifdef _PRINT_SERIAL
	Serial.begin(9600);
#endif

	for (int i=0;i<N_CHANNELS;i++){
		pinMode(channels[i], OUTPUT);
	}
	
}

void loop() {
	
    digitalWrite(CHANNEL_A, HIGH);
    delay(10000);
    digitalWrite(CHANNEL_A, LOW);
	
	delay(10000);
}

//////////////////////////// RANDOM STUFF

float gaussianRandom(int limit, int iterations){
	float r = 0;
	for (int i=0;i<iterations;i++){
		r += random(limit);
	}
	return r/iterations;
}

int gaussianRandomInt(int limit, int iterations){
	return round(gaussianRandom(limit,iterations));
}
	
float inverseGaussianRandom(int limit, int iterations){
	float r = gaussianRandom(limit,iterations);
	if (r >= limit / 2){
		r = limit - (r - (limit / 2));
	} else {
		r = (limit/2) - r;
	}
	return r;
}

int inverseGaussianRandomInt(int limit, int iterations){
	return round(inverseGaussianRandom(limit,iterations));
}

*/
