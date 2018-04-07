#ifndef IRSENSOR_H
#define IRSENSOR_H
#include <Arduino.h>
#include "Component.h"
#define TONE_VALUE 44000
class IRSensor: public Component{
private:
  int send_pin, recv_pin;
public:
  IRSensor( );
  IRSensor( int send_pin, int recv_pin );
  ~IRSensor( ){};
  void send_pulse( );
  bool is_obstructed( );
  void setup( );
};
#endif