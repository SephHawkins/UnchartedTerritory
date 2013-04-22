#ifndef ASTEROID_H
#define ASTEROID_H

#include "object.h"

class Asteroid: public Object
{
 public:
  Asteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
};

#endif
