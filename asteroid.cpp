#include "asteroid.h"

/** Creates an asteroid that has the values specified.  Inits the type to be Asteroid.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Asteroid::Asteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Asteroid";
}
/** Moves the asteroid. Holds the x position constant so it only moves vertically */
void Asteroid::move()
{
  x = x;
  y += yVel;
  setPos(x,y);
}
