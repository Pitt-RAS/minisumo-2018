#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#include "Motor.h"
#include "Encoder.h"
#include "Component.h"
#include "IRSensor.h"
#include "PhotoSensor.h"

#define TEST_PWM 250
#define DEFAULT_PWM 125 //formerly 150
#define ROTATIONAL_PWM 125 //formerly 100
#define MICRO_ADJUST_PWM 35 //formery 50
#define MAX_PWM 255
#define JETTISON_RUN_DELAY 100
#define BRAKE_GRACE_DELAY 50
#define BOUND_TICK_DELAY 250
#define ROTATE_TICK_DELAY 115
#define SEE_NOTHING_DELAY 50
#define SIDE_BOUNDARY_DELAY 750
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
  bool within_boundary_left( );
  bool within_boundary_right( );
  void rotate_right( int pwm );
  void rotate_left( int pwm );
  void short_all( );
  void bear_clockwise( int left_pwm, int right_pwm );
  void bear_anticlockwise( int left_pwm, int right_pwm );
  void timed_rotation_left( int pwm, int delay );
  void timed_rotation_right( int pwm, int delay );
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