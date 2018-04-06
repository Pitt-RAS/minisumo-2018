#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#include "Motor.h"
#include "Encoder.h"
#include "Component.h"
#include "IRSensor.h"
#include "PhotoSensor.h"

#define TEST_PWM 25
#define DEFAULT_PWM 100
#define ROTATIONAL_PWM 150
#define MICRO_ADJUST_PWM 50
#define MAX_PWM 255
#define JETTISON_RUN_DELAY 100
class Sumobot: public Component {
private:
  IRSensor * r, * cr, * c, * cl, * l;
  PhotoSensor * plf, * prf, * plb, * prb;
  
  void right_side_clockwise( int pwm );
  void left_side_clockwise( int pwm );
  void right_side_anticlockwise( int pwm );
  void left_side_anticlockwise( int pwm );
  void forward( int pwm );
  void backward( int pwm );
  bool within_boundaries( );
  bool within_boundary_front( );
  bool within_boundary_rear( );
  void rotate_right( int pwm );
  void rotate_left( int pwm );
  void short_all( );
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
  void test( int pwm );
  void loop( int tick );
  void jettison( );
};
#endif