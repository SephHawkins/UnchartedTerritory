#include "basicalien.h"

/** Creates a basic alien that has the values specified.  Inits the type to be BasicAlien.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
BasicAlien::BasicAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "BasicAlien";
}

/** Moves the alien's x and y position */
void BasicAlien::move()
{
  x += xVel;
  y += yVel;
  setPos(x,y);
}
