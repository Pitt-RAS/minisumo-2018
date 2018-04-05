#include "Sumobot.h"
int A_HERTZ_PIN = A5;
int B_HERTZ_PIN = A7;
int AIN1 = 11;
int AIN2 = 12;
int PWMA = 10;
int BIN1 = 13;
int BIN2 = 22;
int PWMB = 9;
int IR_SEND_PIN = 0;
int SENSOR_CENTER = 2;
int PHOTO_RECV = A3;
Encoder *c = new Encoder( A_HERTZ_PIN );
Motor *a = new Motor( AIN1, AIN2, PWMA, c );
Motor *b = new Motor( BIN1, BIN2, PWMB, c );
IRSensor *center = new IRSensor( IR_SEND_PIN, SENSOR_CENTER );
PhotoSensor *ps = new PhotoSensor( PHOTO_RECV );
Sumobot *lobo = new Sumobot( a, b, a, b, center, center, center, center, center);
void setup() {
  lobo -> setup( );
  Serial.begin(9600);
}
int tick = 0;
int pwm = 128;
void loop() {
  lobo -> loop( tick );
  Serial.println( ps -> within_boundary( ) ); 
  tick++;
}
