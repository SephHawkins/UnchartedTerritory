#include "object.h"

/** Inits the Object to have the values specified.  Sets the position as well
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Object::Object(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo)
{
  pixMap = p;
  setPixmap(*p);
  x = xVal;
  y = yVal;
  xVel = xVelo;
  yVel = yVelo;
  setPos(x,y);
}
