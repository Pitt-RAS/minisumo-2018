#ifndef PHOTOSENSOR_H
#define PHOTOSENSOR_H
#include <Arduino.h>
#include "Component.h"
#define BOUNDARY_SENSE_THRESHOLD 400
class PhotoSensor: public Component{
private: 
  int read_pin;
  int read( );
public:
  PhotoSensor( ) { };
  PhotoSensor( int read_pin );
  ~PhotoSensor( ) { };
  void setup( );
  bool within_boundary( );
};
#endif
