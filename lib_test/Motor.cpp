#include "Motor.h"
Motor::Motor( ){
  
}
/*
 * Creating a motor instantiates four integers, *and that is all*, besides for 
 * the functions that move the motors.
 * in1, in2 -> digital output pin connecting to (A/B)IN(1/2) of the driver 
 * pwm -> analog output pin connecting to PWM(A/B)
 * stby -> digital output bridged to standby of motor driver
 * encoder -> the an encoder object to account for this motor's hertz
 */
Motor::Motor( int in1, int in2, int pwm, int stby, Encoder *encoder ){
  this -> in1 = in1;
  this -> in2 = in2;
  this -> pwm = pwm;
  this -> stby = stby;
  this -> encoder = encoder;
}
Motor::Motor( int in1, int in2, int pwm, int stby ){
  this -> in1 = in1;
  this -> in2 = in2;
  this -> pwm = pwm;
  this -> stby = stby;
}
/*
 * Activates the motor clockwise, where speed is reflected as an integer 'pwmv'
 * between 0 and 255. 255 is max, 0 is none.
 */
void Motor::clockwise( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, LOW );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );
}
/*
 * Activates the motor anticlockwise, speed is reflected by 'pwmv', and integer 
 * between 0 and 255. 255 is max, 0 is none.
 */
void Motor::anticlockwise( int pwmv ){
  digitalWrite( in1, LOW );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );
}
/*
 * Don't use this, we don't know what it does yet.
 * Important: the slower a motor moves, the less braking 
 * torque available. StackOverflow electronics suggests this is a method of 
 * braking involving short-circuiting. 
 */
void Motor::short_brake( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );    
}
/*
 * Cuts power to the motor (no braking, expect the motor to continue to go
 * for a little 
 */
void Motor::stop( ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, 0 );
  digitalWrite( stby, LOW );
}
/*
 * An extended call to this motor's encoder's get_hertz( ) function. -2 is 
 * returned in the case that this motor doesn't have an encoder.
 */
int Motor::get_hertz( ){
  return encoder ? this -> encoder -> get_hertz( ) : -2;
}
/*
 * An extended call to this motor's encoder's get_hertz( ) function. -2 is 
 * returned in the case that this motor doesn't have an encoder.
 */
int Motor::get_hertz( int timeout ){
   return encoder ? this -> encoder -> get_hertz( timeout ): -2;
}
/*
 * setup function in coherence with Component class. Sets all four pins to 
 * OUTPUT.
 */ 
void Motor::setup( ){
  pinMode( in1, OUTPUT );
  pinMode( in2, OUTPUT );
  pinMode( pwm, OUTPUT );
  pinMode( stby, OUTPUT );
  if ( encoder ) encoder -> setup( );
}
/*
 * Returns an array containing the pins values as ints in order:
 * in1, in2, pwm, stby
 */
int* Motor::get_pins( ){
  int res[ 4 ] = { in1, in2, pwm, stby };
  return res;
}
