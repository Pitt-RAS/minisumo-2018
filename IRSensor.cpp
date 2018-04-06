#include "IRSensor.h"
/*
 * The base constructor requires only a pin that the IR LED sends on, and the 
 * pin in which the reciever works on.
 */
IRSensor::IRSensor( int send_pin, int recv_pin ){
  this -> send_pin = send_pin;
  this -> recv_pin = recv_pin;
}
/*
 * Required setup function sets the pin modes for this component, and then
 * also sets the tonal frequency for the sending LED.
 */
void IRSensor::setup( ){
  pinMode( recv_pin, INPUT_PULLUP );
  pinMode( send_pin, OUTPUT );
  tone( send_pin, TONE_VALUE );
}
/*
 * True if something is blocking the line of sight of this sensor, false if
 * not the case. It should be noted that in original code, the method was 
 * determining if the light was being reflected back to the sensor (true case)
 * or not (false case.)
 */
bool IRSensor::is_obstructed( ){
  return !digitalRead( recv_pin );
}