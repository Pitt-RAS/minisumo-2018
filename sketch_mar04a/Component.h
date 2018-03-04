#ifndef COMPONENT_H
#define COMPONENT_H
class Component{
public:
  virtual void setup( ) = 0;
  virtual int* get_pins( ) = 0;
  /*virtual void get_state( ) = 0;*/
};
#endif