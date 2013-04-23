#ifndef BOSS_H
#define BOSS_H

#include "object.h"

class Boss: public Object
{
 public:
  Boss(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  void fireLasers();
};

#endif
