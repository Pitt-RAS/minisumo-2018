#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include "Component.h"
class Motor: public Component{
private:
  int in1, in2, pwm, stby;
public:
  Motor( );
  Motor( int in1, int in2, int pwm, int stby );
  ~Motor( );
  void clockwise( int pwmv );
  void anticlockwise( int pwmv );
  void short_brake( int pwmv );
  void stop( );
  int* get_pins( );
  void setup( );
  
};
#endif