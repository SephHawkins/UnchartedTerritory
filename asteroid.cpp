#include "asteroid.h"

Asteroid::Asteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{

}

void Asteroid::onHit()
{

}

void Asteroid::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
