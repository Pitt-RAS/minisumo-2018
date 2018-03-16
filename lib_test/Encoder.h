#ifndef ENCODER_H
#define ENCODER_H
#include <Arduino.h>
#include "Component.h"
#define MICROSECONDS_PERIOD 500000
class Encoder: public Component{
private:
  int in;
public:
  Encoder( );
  Encoder( int pin );
  ~Encoder( );
  int get_hertz( );
  int get_hertz( int timeout );
  int* get_pins( );
  void setup( );
};
#endif