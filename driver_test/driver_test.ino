#include <Motor.h>
/*
 * TODO: reassign these pins
 */
int BIN2 = 2;
int BIN1 = 3;
int STBY = 4;
int AIN1 = 5;
int AIN2 = 6;
int PWMA = 10;
int PWMB = 9;
/* Instantiate these motors based on their respective pins*/
Motor *a = new Motor( AIN1, AIN2, 10, STBY );
Motor *b = new Motor( BIN1, BIN2, 9 , STBY );
void setup() {
  /* Set output for pins 2 thru 12 */
  int i;
  for ( i = 2; i < 13; i++ ){
    pinMode( i, OUTPUT );
  }
  Serial.begin(9600);
}
void loop() {
  /* Trigger clockwise motion with a pulse-width modulation that increases from
   * 0 - 255; so the motors key up slowly and hit max speed, then cut out.
   */
  int x;
  for ( x = 0; x <= 255; x++){
    delay(100);
    Serial.println(x);
    a -> clockwise( x );
    b -> clockwise( x );
  }
}
