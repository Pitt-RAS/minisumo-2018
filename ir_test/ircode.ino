#define irLedPin 0
#define irSensorPin 1

int irRead(int readPin, int triggerPin);

void setup()
{
  pinMode(irSensorPin, INPUT_PULLUP);
  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600); 
  /*tone( pin, frequency );*/
  tone(0, 48000);

}

void loop()
{  
  Serial.println(irRead(irSensorPin, irLedPin));
  delay(100);
}

int irRead(int readPin, int triggerPin)
{
  /*This is all there is to it*/
  return digitalRead(readPin);
}
