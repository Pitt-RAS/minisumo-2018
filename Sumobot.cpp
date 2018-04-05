#include "Sumobot.h"
/*
 * Eventually we will need sensors, encoders, etc.
 * For now, this constructor initializes a robot based off its motors (pre-
 * initialized before this, as well.)
 */
Sumobot::Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb ){
  this -> lf = lf;
  this -> rf = rf;
  this -> lb = lb;
  this -> rb = rb;
}
Sumobot::Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb, IRSensor * r,
          IRSensor * cr, IRSensor * c, IRSensor * cl, IRSensor * l){
  this -> lf = lf;
  this -> rf = rf;
  this -> lb = lb;
  this -> rb = rb;
  this -> r = r;
  this -> cr = cr;
  this -> c = c;
  this -> cl = l;
  this -> l = l;
}
Sumobot::Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb, IRSensor * r,
          IRSensor * cr, IRSensor * c, IRSensor * cl, IRSensor * l,
          PhotoSensor * plf, PhotoSensor * prf, PhotoSensor * plb, 
          PhotoSensor * prb ){
  this -> lf = lf;
  this -> rf = rf;
  this -> lb = lb;
  this -> rb = rb;
  this -> r = r;
  this -> cr = cr;
  this -> c = c;
  this -> cl = l;
  this -> l = l;
  this -> plf = plf;
  this -> prf = prf;
  this -> plb = plb;
  this -> prb = prb;
}
/*
 * This function will rotate the robot deg degrees (not radians?) clockwise.
 */
void Sumobot::rotate_clockwise( int deg ){
  
}
/*
 * This function will rotate the robot deg degrees anticlockwise.
 */
void Sumobot::rotate_anticlockwise( int deg ){
  
}
void Sumobot::forward( int pwm ){
  this -> right_side_clockwise( pwm );
  this -> left_side_anticlockwise( pwm );
}
void Sumobot::right_side_clockwise( int pwm ){
  this -> rf -> clockwise( pwm );
  this -> rb -> clockwise( pwm );
}
void Sumobot::left_side_clockwise( int pwm ){
  this -> lf -> clockwise( pwm );
  this -> lb -> clockwise( pwm );
}
void Sumobot::right_side_anticlockwise( int pwm ){
  this -> rf -> anticlockwise( pwm );
  this -> rb -> anticlockwise( pwm );
}
void Sumobot::left_side_anticlockwise( int pwm ){
  this -> lf -> anticlockwise( pwm );
  this -> lb -> anticlockwise( pwm );
}
void Sumobot::loop( int tick ){
  if ( c -> is_obstructed( ) ){
    this -> forward( DEFAULT_PWM );
  }
}
void Sumobot::test( int tick ){
  if ( tick < 1000 ){
    this -> lf -> clockwise( TEST_PWM );
    this -> rf -> clockwise( TEST_PWM );
    this -> lb -> clockwise( TEST_PWM );
    this -> rb -> clockwise( TEST_PWM );
  }
  else {
    this -> lf -> anticlockwise( TEST_PWM );
    this -> rf -> anticlockwise( TEST_PWM );
    this -> lb -> anticlockwise( TEST_PWM );
    this -> rb -> anticlockwise( TEST_PWM );    
  }
}
/*
 * Component-required setup function. Triggers setup function of each motor.
 */
void Sumobot::setup( ){
  this -> lf -> setup( );
  this -> rf -> setup( );
  this -> lb -> setup( );
  this -> rb -> setup( );
}
/*
 * Returns an array containing a pointer to an array for each motor. The 
 * arrays pointed to will contain the pins in use by that motor, in respective
 * order ofL lf, rf, lb, rb.
 */
int* Sumobot::get_pins( ){
  int res[ 4 ] = {  this -> lf -> get_pins( ), 
                    this -> rf -> get_pins( ), 
                    this -> lb -> get_pins( ), 
                    this -> rb -> get_pins( ) };
  return res;
}