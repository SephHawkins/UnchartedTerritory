#ifndef MISSILE_H
#define MISSILE_H

#include "object.h"
#include <iostream>

class Missile: public Object
{
 public:
  Missile(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  void explode();
  int time;
};

#endif
