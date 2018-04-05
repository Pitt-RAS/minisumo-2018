#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#include "Motor.h"
#include "Encoder.h"
#include "Component.h"
#include "IRSensor.h"
#include "PhotoSensor.h"

#define TEST_PWM 25
class Sumobot: public Component {
public: 
  Motor * lf;
  Motor * lb;
  Motor * rf;
  Motor * rb;
  Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb );
  ~Sumobot( );
  void setup ( );
  int* get_pins( );
  void rotate_clockwise( int deg );
  void rotate_anticlockwise( int deg );
  void test( int pwm );
};
#endif