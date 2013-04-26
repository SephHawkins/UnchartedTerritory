#include "bullet.h"

/** Creates a bullet that has the values specified.  Inits the type to be Bullet.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Bullet::Bullet(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Bullet";
}

/** Moves the bullet. Holds the x - value constant so that it only moves vertically. */
void Bullet::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
