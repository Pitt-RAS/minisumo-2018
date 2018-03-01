#include "Motor.h"

Motor::Motor( int in1, int in2, int pwm, int stby ){
  this->in1 = in1;
  this->in2 = in2;
  this->pwm = pwm;
  this->stby = stby;
}

void Motor::clockwise( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, LOW );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );
}
void Motor::anticlockwise( int pwmv ){
  digitalWrite( in1, LOW );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );
}
void Motor::short_brake( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, pwmv );
  digitalWrite( stby, HIGH );    
}
void Motor::cold_stop( int pwmv ){
  digitalWrite( in1, HIGH );
  digitalWrite( in2, HIGH );
  analogWrite( pwm, 0 );
  digitalWrite( stby, LOW );
}