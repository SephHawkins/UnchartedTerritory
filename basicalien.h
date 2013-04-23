#ifndef BASICALIEN_H
#define BASICALIEN_H

#include "object.h"

class BasicAlien: public Object
{
 public:
  BasicAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
};

#endif
