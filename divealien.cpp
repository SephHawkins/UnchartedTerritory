#include "divealien.h"

DiveAlien::DiveAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "DiveAlien";
}

void DiveAlien::onHit()
{

}

void DiveAlien::move()
{
  x += xVel;
  y += yVel;
  setPos(x,y);
}

void DiveAlien::zoomOff()
{
  if(rand()%2 == 0)
  {
    xVel = 5;
  }
  else
  {
    xVel = -5;
  }
  yVel = ((rand() % 10)-10);
}
