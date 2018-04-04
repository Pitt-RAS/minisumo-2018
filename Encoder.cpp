#include "Encoder.h"
/* 
 * Creates an encoder sensor object from the int pin, denoting the pin where
 * the pulses are inputted.
 */
Encoder::Encoder( int pin ){
  this -> in = pin;
}
/*
 * Gets the hertz based on applying the period = 1/T formula to the Arduino
 * standard function pulseIn.
 * Also worth noting I have no actual idea how this function works at all 
 * because apparently even signals are beyond my understanding.
 */
int Encoder::get_hertz( ){
  return MICROSECONDS_WAVE_SPEED/pulseIn( in, LOW );
}
/*
 * Behaves exactly as get_hertz( ), but abandons ship after timeout 
 * microseconds.
 */
int Encoder::get_hertz( int timeout ){
  return MICROSECONDS_WAVE_SPEED/pulseIn( in, LOW, timeout );
}
/*
 * Returns an array containing one integer, the pin in use.
 */
int* Encoder::get_pins( ){
  int res[ 1 ] = { in };
  return res;
}
void Encoder::setup( ){
  pinMode( in, INPUT );
}