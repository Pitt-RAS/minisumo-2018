#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#inclde <Motor.h>
class Sumobot{
private:
  Motor lf;
  Motor lb;
  Motor rf;
  Motor rb;
public: 
  Robot( Motor lf, Motor rf, Motor lb, Motor rb );
  ~Robot( );
  
};
#endif