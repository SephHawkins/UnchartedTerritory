#include "laser.h"

/** Creates a laser that has the values specified.  Inits the type to be Laser.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Laser::Laser(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Laser";
  deadly = 0;
}

/** This function does nothing, but must be implemented, since Laser derives from Object */
void Laser::move()
{

}
