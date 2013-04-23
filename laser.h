#ifndef LASER_H
#define LASER_H

#include "object.h"

class Laser: public Object
{
 public:
  Laser(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  bool deadly;
};

#endif
