#include "Sumobot.h"
int A_HERTZ_PIN = A5;
int B_HERTZ_PIN = A7;
int AIN1 = 11;
int AIN2 = 12;
int PWMA = 10;
int BIN1 = 13;
int BIN2 = 22;
int PWMB = 9;
int IR_SEND_PIN = 0;
int SENSOR_CENTER = 1;
int SENSOR_CENTER_LEFT = 3;
int SENSOR_CENTER_RIGHT = 2; 
int SENSOR_RIGHT = 6;
int SENSOR_LEFT = 5;
int PHOTO_RECV_FR = A2;
int PHOTO_RECV_FL = A3;
int PHOTO_RECV_BR = A0;
int PHOTO_RECV_BL = A1;
Encoder *c = new Encoder(  );
Motor *a = new Motor( AIN1, AIN2, PWMA, c );
Motor *b = new Motor( BIN1, BIN2, PWMB, c );
IRSensor *center = new IRSensor( IR_SEND_PIN, SENSOR_CENTER );
/* This is the problem one: */
IRSensor *center_left = new IRSensor( IR_SEND_PIN, SENSOR_CENTER_LEFT );
IRSensor *center_right = new IRSensor( IR_SEND_PIN, SENSOR_CENTER_RIGHT );
IRSensor *right = new IRSensor( IR_SEND_PIN, SENSOR_RIGHT );
IRSensor *left = new IRSensor( IR_SEND_PIN, SENSOR_LEFT );

PhotoSensor *pfr = new PhotoSensor( PHOTO_RECV_FR );
PhotoSensor *pfl = new PhotoSensor( PHOTO_RECV_FL );
PhotoSensor *pbl = new PhotoSensor( PHOTO_RECV_BL );
PhotoSensor *pbr = new PhotoSensor( PHOTO_RECV_BR ); /*My favorite beer*/
Sumobot *lobo = 
  new Sumobot( a, b, a, b, right, center_right, center, center_left, left,
                pfl, pfr, pbl, pbr );
void setup() {
  lobo -> setup( );
  
//  tone( 0, 48000 );
  Serial.begin(9600);
}
int tick = 0;
void loop() {
//  Serial.print( "FRONT RIGHT: " );
//  Serial.print( analogRead( PHOTO_RECV_FR ) );
//  Serial.print( " " );
//  Serial.print( pfr -> within_boundary( ) );
//  Serial.print( " FRONT LEFT: " );
//  Serial.print( analogRead( PHOTO_RECV_FL ) );
//  Serial.print( " " );
//  Serial.print( pfl -> within_boundary( ) );
//  Serial.print( " BACK LEFT: " );
//  Serial.print( analogRead( PHOTO_RECV_BL ) );
//  Serial.print( " " );
//  Serial.print( pbl -> within_boundary( ) );
//  Serial.print( " BACK RIGHT: " );
//  Serial.print( analogRead( PHOTO_RECV_BR ) );
//  Serial.print( " " );
//  Serial.print( pbr -> within_boundary( ) );
//
  delay( 5000 );
  lobo -> jettison( );
  while (1){
    // Serial.print( " RIGHTMOST: " );
    // Serial.print( right -> is_obstructed( ) );
    // Serial.print( " CENTER_RIGHT: " );
    // Serial.print( center_right -> is_obstructed( ) );
    // Serial.print( " CENTER:" );
    // Serial.print( center -> is_obstructed( ) );
    // Serial.print( " CENTER_LEFT:" );
    // Serial.print( center_left -> is_obstructed( ) );
    // Serial.print( " LEFTMOST: ");
    // Serial.println( left -> is_obstructed( ) );

    lobo -> loop( tick );
  }
}
