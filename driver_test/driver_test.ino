#include <Motor.h>
int BIN2 = 2;
int BIN1 = 3;
int STBY = 4;
int AIN1 = 5;
int AIN2 = 6;
int PWMA = 10;
int PWMB = 9;

Motor *a = new Motor( AIN1, AIN2, 10, STBY );
Motor *b = new Motor( BIN1, BIN2, 9 , STBY );
void setup() {
  int i;
  for ( i = 2; i < 13; i++ ){
    pinMode( i, OUTPUT );
  }
  Serial.begin(9600);
}
void loop() {
  int x;
  for ( x = 0; x <= 255; x++){
    delay(100);
    Serial.println(x);
    a -> clockwise( x );
    b -> clockwise( x );
  }
}
