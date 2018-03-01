#include <Motor.h>
int BIN2 = 2;
int BIN1 = 3;
int STBY = 4;
int AIN1 = 5;
int AIN2 = 6;
int PWMA = 7;
int PWMB = 8;
#include <Motor.h>
Motor *a = new Motor( AIN1, AIN2, 10, STBY );
void setup() {
  int i;
  for ( i = 2; i < 13; i++ ){
    pinMode( i, OUTPUT );
  }
  pinMode( 10, OUTPUT );
  Serial.begin(9600);
}
void loop() {
  while ( 1 ){
    int x;
    for ( x = 0; x <= 255; x++){
      delay(100);
      Serial.println(x);
      a -> clockwise( x );
    }
  }
}
