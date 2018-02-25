int BIN2 = 2;
int BIN1 = 3;
int STBY = 4;
int AIN1 = 5;
int AIN2 = 6;
int PWMA = 7;
int PWMB = 8;
void setup() {
  // put your setup code here, to run once:
  // declare the  as an OUTPUT:
  //lol what am I doing
  int i;
  for (i = 2; i < 13; i++){
    pinMode(i, OUTPUT);
  }
  /*
   * D2 -> BIN2
   */
}
void set_motor( int motor, boolean cw){
  if ( motor == 0 ){
    if ( cw ){
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(PWMA, HIGH);
      digitalWrite(STBY, HIGH);
      
    }
  }

}
void stby_motor( int motor ){
  if ( motor == 0 ){
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(PWMA, LOW);
      digitalWrite(STBY, LOW);
    
  }
  
}
void loop() {
  set_motor( 0, true );
  delay(10000);
  stby_motor( 0 );
}
