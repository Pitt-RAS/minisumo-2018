#include "Sumobot.h"
Motor *a = new Motor( 1, 2, 3, 4 );
Motor *b = new Motor( 5, 6, 7, 8 );
Motor *c = new Motor( 9, 10, 11, 12 );
Motor *d = new Motor( 13, 14, 15, 16 );

Sumobot *small_levi = new Sumobot( a, b, c, d );
void setup() {
  // put your setup code here, to run once:
  small_levi -> setup( );
}

void loop() {
  // put your main code here, to run repeatedly:

}
