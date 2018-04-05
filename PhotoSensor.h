#ifndef PHOTOSENSOR_H
#define PHOTOSENSOR_H
#include <Arduino.h>
#include "Component.h"
#define BOUNDARY_SENSE_THRESHOLD 200
class PhotoSensor: public Component{
private: 
  int read_pin;
  int read( );
public:
  PhotoSensor( ) { };
  PhotoSensor( int read_pin );
  ~PhotoSensor( ) { };
  void setup( );
  int* get_pins( );
  bool within_boundary( );
};
#endif