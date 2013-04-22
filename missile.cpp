#include "missile.h"

Missile::Missile(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Missile";
  time = 50;
}

void Missile::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}

void Missile::explode()
{
  if(time == 50)
  {
    x = x - 48;
    y = y;
  }
  time--;
  yVel = 0;
}
