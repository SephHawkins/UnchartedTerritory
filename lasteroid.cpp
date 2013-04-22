#include "lasteroid.h"

lAsteroid::lAsteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{

}

void lAsteroid::onHit()
{

}

void lAsteroid::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
