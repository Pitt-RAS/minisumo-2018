#include "Sumobot.h"
int A_HERTZ_PIN = A5;
int B_HERTZ_PIN = A2;
int AIN1 = 11;
int AIN2 = 12;
int PWMA = 10;
Encoder *c = new Encoder( A_HERTZ_PIN );
Motor *a = new Motor( AIN1, AIN2, PWMA, c );
 
void setup() {
  a -> setup( );
  Serial.begin(9600);
}
int tick = 0;
int pwm = 128;
void loop() {
  a -> clockwise( pwm );
  Serial.println( a -> get_hertz( ) );
  tick++;
}
