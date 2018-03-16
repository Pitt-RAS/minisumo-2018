#include "Sumobot.h"
int A_HERTZ_PIN = A1;
int B_HERTZ_PIN = A2;
Encoder *c = new Encoder( A_HERTZ_PIN );
Motor *a = new Motor( 5, 6, 10, 4, c );
/*Motor *b = new Motor( 3, 2, 9, 4 );*/
/*Motor *c = new Motor( 9, 10, 11, 12 );
Motor *d = new Motor( 13, 14, 15, 16 ); */

Sumobot *small_levi = new Sumobot( a, a, a, a ); 
void setup() {
  // put your setup code here, to run once:
  /* small_levi -> setup( ); */
  small_levi -> setup( );
  Serial.begin(9600);
}
int tick = 0;
int pwm = 25;
void loop() {
  small_levi -> test( tick );
  Serial.println( a -> get_hertz( ) );
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
  // a -> clockwise( pwm );
  //Serial.println( "Motor Call:"+a -> get_hertz( ) );
  // Serial.println( a -> get_hertz( ) );
  // Serial.println( c -> get_hertz( ) );
  //Serial.println( tick );
  //Serial.println( a -> get_hertz( ) );
  tick++;
}
