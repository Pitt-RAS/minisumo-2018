#define irLedPin 0
#define irSensorPin 1

int irRead(int readPin, int triggerPin);

void setup()
{
  pinMode(irSensorPin, INPUT_PULLUP);
  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600); 
    tone(0, 48000);

}

void loop()
{  
  Serial.println(irRead(irSensorPin, irLedPin));
  delay(100);
}

int irRead(int readPin, int triggerPin)
{
  //int halfPeriod = 80; //one period at 38.5khZ is aproximately 26 microseconds
  //int halfPeriod = 80;
  int cycles = 20; //26 microseconds * 38 is more or less 1 millisecond
  int i;
  /*for (i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }*/
  return digitalRead(readPin);
}
