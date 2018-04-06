#include "PhotoSensor.h"
/*
 * Provide this constructor with the pin that will read analogous data from the
 * photo sensor.
 */
PhotoSensor::PhotoSensor( int read_pin ){
  this -> read_pin = read_pin;
}
/*
 * Sets our pin to input.
 */
void PhotoSensor::setup( ){
  pinMode( read_pin, INPUT );
}
/*
 * Performs an analog read. Technically a redundant function. Don't use this 
 * anymore. 
 */
int PhotoSensor::read( ){
  return analogRead( this -> read_pin );
}
/*
 * True if we aren't sensing white (< 300)
 */
bool PhotoSensor::within_boundary( ){
  return analogRead( this -> read_pin) <= BOUNDARY_SENSE_THRESHOLD ;
}