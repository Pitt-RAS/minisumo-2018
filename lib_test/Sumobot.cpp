#include "Sumobot.h"
#define TEST_PWM 25
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
void Sumobot::test( ){
  this -> lf -> clockwise( TEST_PWM );
  this -> rf -> clockwise( TEST_PWM );
  this -> lb -> clockwise( TEST_PWM );
  this -> rb -> clockwise( TEST_PWM );
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