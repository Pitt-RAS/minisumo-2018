#include "Encoder.h"
/*
 * Don't use this constructor.
 */
Encoder::Encoder( ){
  
}
/* Creates an encoder sensor object from the int pin, denoting the pin where
 * the pulses are coming to.
 */
Encoder::Encoder( int pin ){
  this -> in = pin;
}
/*
 * Gets the hertz based on applying the period = 1/T forumla to the Arduino
 * standard function pulseIn
 */
int Encoder::get_hertz( ){
  return MICROSECONDS_PERIOD/pulseIn( in, LOW );
}
/*
 * Behaves exactly as get_hertz( ), but abandons ship after timeout microseconds
 */
int Encoder::get_hertz( int timeout ){
  return MICROSECONDS_PERIOD/pulseIn( in, LOW, timeout );
}
int* Encoder::get_pins( ){
  int res[ 1 ] = { in };
  return res;
}
void Encoder::setup( ){
  pinMode( in, INPUT );
}