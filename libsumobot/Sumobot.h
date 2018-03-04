#ifndef SUMOBOT_H
#define SUMOBOT_H
#include <Arduino.h>
#include "Motor.h"
#include "Component.h"
class Sumobot: public Component {
private:
  Motor lf;
  Motor lb;
  Motor rf;
  Motor rb;
public: 
  Sumobot( Motor lf, Motor rf, Motor lb, Motor rb );
  ~Sumobot( );
  void setup ( );
  int* get_pins( );
};
#endif