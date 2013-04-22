#ifndef DIVEALIEN_H
#define DIVEALIEN_H

#include "object.h"
#include <cstdlib>

class DiveAlien: public Object
{
 public:
  DiveAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
  void zoomOff();
};

#endif
