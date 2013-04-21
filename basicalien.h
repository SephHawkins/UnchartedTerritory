#ifndef BASICALIEN_H
#define BASICALIEN_H

#include <QKeyEvent>
#include "object.h"
#include "bullet.h"
#include <iostream>

class BasicAlien: public Object
{
 public:
  BasicAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
};

#endif
