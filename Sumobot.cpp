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
 * Sets drivetrain to move forward, with motors running at specified PWM
 */
void Sumobot::forward( int pwm ){
  this -> right_side_clockwise( pwm );
  this -> left_side_clockwise( pwm );
}
/*
 * Sets drivetrain to move backward, with motors at specified PWM
 */
void Sumobot::backward( int pwm ){
  this -> right_side_anticlockwise( pwm );
  this -> left_side_anticlockwise( pwm );
}
/*
 * Left rotation at PWM specified
 */
void Sumobot::rotate_left( int pwm ){
  this -> left_side_clockwise( pwm );
  this -> right_side_anticlockwise( pwm );
}
/*
 * Right rotation at PWM specified
 */
void Sumobot::rotate_right( int pwm ){
  this -> right_side_clockwise( pwm );
  this -> left_side_anticlockwise( pwm );
}
/*
 * Set the right side motors to move clockwise @ PWM
 */
void Sumobot::right_side_clockwise( int pwm ){
  this -> rf -> clockwise( pwm );
  this -> rb -> clockwise( pwm );
}
/*
 * Set the left side motors to move clockwise @ PWM
 */
void Sumobot::left_side_clockwise( int pwm ){
  this -> lf -> clockwise( pwm );
  this -> lb -> clockwise( pwm );
}
/*
 * Set the right side motors to move anticlockwise @ PWM
 */
void Sumobot::right_side_anticlockwise( int pwm ){
  this -> rf -> anticlockwise( pwm );
  this -> rb -> anticlockwise( pwm );
}
/*
 * Set the left side motors to move anticlockwise @ PWM
 */
void Sumobot::left_side_anticlockwise( int pwm ){
  this -> lf -> anticlockwise( pwm );
  this -> lb -> anticlockwise( pwm );
}
/*
 * Compares the front photo resistor sensors, returns true if both are within
 * bounds
 */
bool Sumobot::within_boundary_front( ){
  return this -> plf -> within_boundary( ) && this -> prf -> within_boundary( );
}
/*
 * Compares the rear photo resistor sensors, returns true if both are within 
 * bounds
 */
bool Sumobot::within_boundary_rear( ){
  return this -> plb -> within_boundary( ) && this -> prb -> within_boundary( );
}
/*
 * The drive loop. This is where all the magic happens.
 */
void Sumobot::loop( int tick ){
  if ( this -> within_boundary_front( ) ){
    if ( this -> within_boundary_rear( ) ){
      if ( this -> c -> is_obstructed( ) ){
        this -> forward( DEFAULT_PWM );
      }
      if ( this -> cl -> is_obstructed( ) ){
        this -> rotate_left( MICRO_ADJUST_PWM );
      }
      if ( this -> cr -> is_obstructed( ) ){
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
  else {
    for (int i = 0; i <= 500; i++ ){
      this -> backward( DEFAULT_PWM );
    }
  }
  
}
/*
 * Short brake all motors.
 */
void Sumobot::short_all( ){
  this -> lf -> short_brake( 0 );
  this -> lb -> short_brake( 0 );
  this -> rf -> short_brake( 0 );
  this -> rb -> short_brake( 0 );
}
/*
 * Gun the motors for JETTISON_RUN_DELAY miliseconds
 */
void Sumobot::jettison( ){
  this -> forward( MAX_PWM );
  delay( JETTISON_RUN_DELAY );
  this -> short_all( );
}
/*
 * Test function that goes back and forth.
 */
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
