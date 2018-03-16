#include "Sumobot.h"
int A_HERTZ_PIN = A1;
int B_HERTZ_PIN = A2;
Motor *a = new Motor( 5, 6, 10, 4 );
Motor *b = new Motor( 3, 2, 9, 4 );
Encoder *c = new Encoder( A_HERTZ_PIN );
/*Motor *c = new Motor( 9, 10, 11, 12 );
Motor *d = new Motor( 13, 14, 15, 16 ); */

/* Sumobot *small_levi = new Sumobot( a, b, c, d ); */
void setup() {
  // put your setup code here, to run once:
  /* small_levi -> setup( ); */
  a -> setup( );
  Serial.begin(9600);
}
int tick = 0;
int pwm = 25;
void loop() {
  // put your main code here, to run repeatedly:
  /* small_levi -> get_pins( ); */
/*   if( tick <= 500 ){
    a -> clockwise( pwm );
    b -> clockwise( pwm );
  }
  else{
    a -> stop(  );
    b -> short_brake( pwm );
    if( tick >= 1500 ) tick = 0;
  } */
  a -> clockwise( pwm );
  //Serial.println( tick );
  Serial.println( c -> get_hertz( ) );
  tick++;
}
