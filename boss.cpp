#include "boss.h"

/** Creates a boss that has the values specified.  Inits the type to be Boss.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Boss::Boss(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Boss";
  health = 100;
}

/** Moves the boss vertically. Is no longer called after the boss reaches its final position */
void Boss::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
