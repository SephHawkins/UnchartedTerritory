#ifndef BULLET_H
#define BULLET_H

#include <QKeyEvent>
#include "object.h"
#include <iostream>

class Bullet: public Object
{
 public:
  Bullet(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
};

#endif
