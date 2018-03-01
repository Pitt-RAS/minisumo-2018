#include "Motor.h"
/*
 * Creating a motor instantiates four integers, *and that is all*, besides for 
 * the functions that move the motors.
 * in1, in2 -> digital output pin connecting to (A/B)IN(1/2) of the driver 
 * pwm -> analog output pin connecting to PWM(A/B)
 * stby -> digital output bridged to standby of motor driver
 */
Motor::Motor( int in1, int in2, int pwm, int stby ){
  this->in1 = in1;
  this->in2 = in2;
  this->pwm = pwm;
  this->stby = stby;
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
 * torque available. 
 */
void Motor::short_brake( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );    
}
/*
 * Don't use this, we don't know what it does yet.
 */
void Motor::cold_stop( ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, 0 );
  digitalWrite( stby, LOW );
}