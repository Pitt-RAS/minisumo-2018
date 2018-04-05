#include "PhotoSensor.h"
/*
 * Provide this constructor with the pin that will read analogous data from the
 * photo sensor.
 */
PhotoSensor::PhotoSensor( int read_pin ){
  this -> read_pin;
}
/*
 * Sets our pin to input.
 */
void PhotoSensor::setup( ){
  pinMode( read_pin, INPUT );
}
/*
 * Performs an analog read. Technically a redundant function.
 */
int PhotoSensor::read( ){
  return analogRead( this -> read_pin );
}
/*
 * True if we aren't sensing white (> 300)
 */
bool PhotoSensor::within_boundary( ){
  return this -> read( ) >= BOUNDARY_SENSE_THRESHOLD ;
}
/*
 * Component.h compliancy.
 */
int* PhotoSensor::get_pins( ){
  int res [ 1 ] = { this -> read_pin };
  return res;
}