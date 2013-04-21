#include "bullet.h"

Bullet::Bullet(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{

}

void Bullet::onHit()
{

}

void Bullet::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
