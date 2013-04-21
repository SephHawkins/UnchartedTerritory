#include "object.h"

Object::Object(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo)
{
  pixMap = p;
  setPixmap(*p);
  x = xVal;
  y = yVal;
  xVel = xVelo;
  yVel = yVelo;
  setPos(x,y);
}
