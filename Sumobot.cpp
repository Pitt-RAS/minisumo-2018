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
/*
 * Constructor sans-photo sensors.
 */
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
/*
 * Super-constructor; this will be the one we use for the completed robot.
 */
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
  this -> right_side_clockwise( pwm );
  this -> left_side_anticlockwise( pwm );

}
/*
 * Right rotation at PWM specified
 */
void Sumobot::rotate_right( int pwm ){
  this -> right_side_anticlockwise( pwm );
  this -> left_side_clockwise( pwm );
  
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
 * Akin to bearing forward
 */
void Sumobot::bear_clockwise( int left_pwm, int right_pwm ){
  this -> right_side_clockwise( left_pwm );
  this -> left_side_clockwise( right_pwm );
}
/*
 * Akin to bearing backwards
 */
void Sumobot::bear_anticlockwise( int left_pwm, int right_pwm ){
  this -> right_side_anticlockwise( right_pwm );
  this -> left_side_anticlockwise( left_pwm );
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
bool Sumobot::within_boundary_left( ){
  return this -> plb -> within_boundary( ) && this -> plf -> within_boundary( );
}
bool Sumobot::within_boundary_right( ){
  return this -> prb -> within_boundary( ) && this -> prf -> within_boundary( );
}
void Sumobot::timed_rotation_left( int pwm, int delay ){
  long startTime = millis( );
  while ( millis( ) - startTime < delay 
           && this -> within_boundary_left( ) )
    this -> rotate_left( pwm );
}
void Sumobot::timed_rotation_right( int pwm, int delay ){
  long startTime = millis( );
  while ( millis() - startTime < delay  
            && this -> within_boundary_right( ) )
    this -> rotate_right( pwm );
}
/*
 * The drive loop. This is where all the magic happens.
 */
void Sumobot::loop( int tick ){
/*    */
  /*If the front photo sensors report that we are in bounds*/
  if ( this -> within_boundary_front( ) ){    
    /*If the center, (center left, and center right) sensors are obstructed*/
    if ( this -> c -> is_obstructed( ) &&  this -> cl -> is_obstructed( ) 
          && this -> cr -> is_obstructed( ) && this -> l -> is_obstructed( ) 
          && this -> l -> is_obstructed( ) ){
      this -> forward( DEFAULT_PWM );
    }
    else if ( this -> cl -> is_obstructed( ) && this -> c -> is_obstructed( ) &&
              this -> cr -> is_obstructed( ) ){
      this -> forward( DEFAULT_PWM );
    }
    /*Just center and center left*/
    else if ( this -> c -> is_obstructed( ) && this -> cl -> is_obstructed( ) ){
      this -> bear_clockwise( ROTATIONAL_PWM, DEFAULT_PWM );
    }
    /*Just the center and center right*/
    else if ( this -> c -> is_obstructed( ) && this -> cr -> is_obstructed( ) ){
      this -> bear_clockwise( DEFAULT_PWM, ROTATIONAL_PWM );
    }
    /*If the rightmost sensor is obstructed*/
    else if ( this -> r -> is_obstructed( ) ){
      timed_rotation_right( ROTATIONAL_PWM, ROTATE_TICK_DELAY );
    }
    /*If the leftmost sensor is obstructed*/
    else if ( this -> l -> is_obstructed( ) ){
      timed_rotation_left( ROTATIONAL_PWM, ROTATE_TICK_DELAY );
      
    }
/*     else if( within_boundary_left( ) && !within_boundary_right( ) ) 
      timed_rotation_left( ROTATIONAL_PWM, SIDE_BOUNDARY_DELAY );
    else if ( within_boundary_right( ) && !within_boundary_left( ) )
      timed_rotation_right( ROTATIONAL_PWM, SIDE_BOUNDARY_DELAY ); */
    /*needs to go backwards*/
    else {
/*       long startTime = millis( );
      this -> forward( DEFAULT_PWM );
      while ( millis( ) - startTime < SEE_NOTHING_DELAY && 
                                                this -> within_boundaries( ) ); 
                                                */
      //this -> rotate_left( DEFAULT_PWM );
      this -> forward( 0 );
    }
  }
  else {
    this -> short_all( );
    delay( BRAKE_GRACE_DELAY );
    long startTime = millis( );
    while ( millis( ) - startTime < BOUND_TICK_DELAY && 
            this -> within_boundary_rear( ) )
      this -> backward( DEFAULT_PWM );
  }
}
bool Sumobot::within_boundaries( ){
  return this -> within_boundary_front( ) && this -> within_boundary_rear( );
}
/*
 * Short brake all motors.
 */
void Sumobot::short_all( ){
  this -> lf -> short_brake( MAX_PWM );
  this -> lb -> short_brake( MAX_PWM );
  this -> rf -> short_brake( MAX_PWM );
  this -> rb -> short_brake( MAX_PWM );
}
/*
 * Gun the motors for JETTISON_RUN_DELAY milliseconds
 */
void Sumobot::jettison( ){
  this -> backward( MAX_PWM );
  delay( JETTISON_RUN_DELAY );
  this -> short_all( );
  delay( BRAKE_GRACE_DELAY );
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
 * Component-required setup function. Triggers setup function of each motor and
 * subsequent components.
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
