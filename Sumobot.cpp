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
  this -> left_side_clockwise( pwm );
}
void Sumobot::backward( int pwm ){
    this -> right_side_anticlockwise( pwm );
  this -> left_side_anticlockwise( pwm );
}
void Sumobot::rotate_left( int pwm ){
  this -> left_side_clockwise( pwm );
  this -> right_side_anticlockwise( pwm );
}
void Sumobot::rotate_right( int pwm ){
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
bool Sumobot::within_boundary_front( ){
  return this -> plf -> within_boundary( ) && this -> prf -> within_boundary( );
}
bool Sumobot::within_boundary_rear( ){
  return this -> plb -> within_boundary( ) && this -> prb -> within_boundary( );
}
void Sumobot::loop( int tick ){
  if ( this -> within_boundary( ) ){
    if ( this -> c -> is_obstructed( ) ){
      this -> forward( DEFAULT_PWM );
    }
    if ( this -> lc -> is_obstructed( ) ){
      this -> rotate_left( MICRO_ADJUST_PWM );
    }
    if ( this -> rc -> is_obstructed( ) ){
      this -> rotate_right( MICRO_ADJUST_PWM );
    }
    else if ( this -> r -> is_obstructed( ) ){
      this -> rotate_right( ROTATIONAL_PWM );
    }
    else if ( this -> l -> is_obstructed( ) ){
      this -> rotate_left( ROTATIONAL_PWM );
    }
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
  if ( this -> r ) this -> r -> setup( );
  if ( this -> cr) this -> cr -> setup( );
  if ( this -> c) this -> c -> setup( );
  if ( this -> cl ) this -> cl -> setup( );
  if ( this -> l ) this -> l -> setup( );
  if ( this -> plf ) this -> plf -> setup( );
  if ( this -> prf ) this -> prf -> setup( );
  if ( this -> plb ) this -> plb -> setup( );
  if ( this -> prb ) this -> prb -> setup( );
  
}
/*
 * Returns an array containing a pointer to an array for each motor. The 
 * arrays pointed to will contain the pins in use by that motor, in respective
 * order ofL lf, rf, lb, rb.
 */
int* Sumobot::get_pins( ){
  int res[ 4 ] = {  0, 0, 0, 0 };
  return res;
}