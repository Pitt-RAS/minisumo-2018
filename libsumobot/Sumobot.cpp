#include "Sumobot.h"
/*
 * Eventually we will need sensors, encoders, etc.
 */
Sumobot::Sumobot( Motor * lf, Motor * rf, Motor * lb, Motor * rb ){
  this -> lf = lf;
  this -> rf = rf;
  this -> lb = lb;
  this -> rb = rb;
}
void Sumobot::rotate_clockwise( int deg ){
  
}
void Sumobot::rotate_anticlockwise( int deg ){
  
}
void Sumobot::setup( ){
  this -> lf -> setup( );
  this -> rf -> setup( );
  this -> lb -> setup( );
  this -> rb -> setup( );
}
int* Sumobot::get_pins( ){
  int res[ 4 ];
  return res;
}