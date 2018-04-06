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
int SENSOR_CENTER = 2;
int SENSOR_CENTER_LEFT = -1;
int SENSOR_CENTER_RIGHT = -1; 
int SENSOR_RIGHT = -1;
int SENSOR_LEFT = -1;
int PHOTO_RECV_FR = A3;
int PHOTO_RECV_FL = -1;
int PHOTO_RECV_BR = -1;
int PHOTO_RECV_BL = -1;
Encoder *c = new Encoder(  );
Motor *a = new Motor( AIN1, AIN2, PWMA, c );
Motor *b = new Motor( BIN1, BIN2, PWMB, c );
IRSensor *center = new IRSensor( IR_SEND_PIN, SENSOR_CENTER );
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
  Serial.begin(9600);
}
int tick = 0;
void loop() {
  lobo -> loop( tick );
  tick++;
}
