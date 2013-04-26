#include "lasteroid.h"

/** Creates a large asteroid that has the values specified.  Inits the type to be LAsteroid.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
lAsteroid::lAsteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "LAsteroid";
}

/** Moves the large Asteroid's y position. Holds the x constant */
void lAsteroid::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
