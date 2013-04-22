#ifndef LASTEROID_H
#define LASTEROID_H

#include "object.h"

class lAsteroid: public Object
{
 public:
  lAsteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
};

#endif
