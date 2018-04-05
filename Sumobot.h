#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#include "Motor.h"
#include "Encoder.h"
#include "Component.h"
#include "IRSensor.h"
#include "PhotoSensor.h"

#define TEST_PWM 25
#define DEFAULT_PWM 25
class Sumobot: public Component {
private:
  IRSensor * r, * cr, * c, * cl, * l;
  PhotoSensor * plf, * prf, * plb, * prb;
public: 
  Motor * lf, * lb, * rf, * rb;
  Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb );
  Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb, IRSensor * r,
          IRSensor * cr, IRSensor * c, IRSensor * cl, IRSensor * l );
  Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb, IRSensor * r,
          IRSensor * cr, IRSensor * c, IRSensor * cl, IRSensor * l,
          PhotoSensor * plf, PhotoSensor * prf, PhotoSensor * plb, 
          PhotoSensor * prb );
  ~Sumobot( );
  void setup ( );
  int* get_pins( );
  void rotate_clockwise( int deg );
  void rotate_anticlockwise( int deg );
  void test( int pwm );
  void loop( int tick );
};
#endif