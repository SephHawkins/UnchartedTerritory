#include "missile.h"

/** Creates a missile that has the values specified.  Inits the type to be Missile.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Missile::Missile(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Missile";
  time = 50;
}

/** Moves the missile vertically only */
void Missile::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}

/** Triggers the explosion, stopping the movement and counting down from 50 each time it is called */
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
