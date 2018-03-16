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
int Encoder::get_hertz( ){
  return MICROSECONDS_PERIOD/pulseIn( this -> in, LOW );
}
/*
 * Abandons ship after timeout microseconds.
 */
int Encoder::get_hertz( int timeout ){
  return MICROSECONDS_PERIOD/pulseIn( this -> in, LOW, timeout );
}
int* Encoder::get_pins( ){
  int res[ 1 ] = { in };
  return res;
}
void Encoder::setup( ){
  pinMode( in, INPUT );
}