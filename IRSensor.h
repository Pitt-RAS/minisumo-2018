#ifndef IRSENSOR_H
#define IRSENSOR_H
#include <Arduino.h>
#include <Component.h>
#define TONE_VALUE 48000
class IRSensor: public Component{
public:
  int send_pin, recv_pin;
  IRSensor( );
  IRSensor( int send_pin, int recv_pin );
  ~IRSensor( ){};
  void send_pulse( );
  bool is_obstructed( );
  void setup( );
  int* get_pins( );
}
#endif