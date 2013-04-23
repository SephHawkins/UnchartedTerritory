#include "boss.h"

Boss::Boss(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Boss";
}

void Boss::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}

void Boss::fireLasers()
{

}
