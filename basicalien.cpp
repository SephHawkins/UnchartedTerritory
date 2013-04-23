#include "basicalien.h"

BasicAlien::BasicAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "BasicAlien";
}

void BasicAlien::move()
{
  x += xVel;
  y = y;
  setPos(x,y);
}
