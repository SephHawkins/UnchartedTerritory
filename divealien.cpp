#include "divealien.h"

/** Creates a diving alien that has the values specified.  Inits the type to be DiveAlien.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
DiveAlien::DiveAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "DiveAlien";
}

/** Moves the DiveAlien both horizontally and vertically */
void DiveAlien::move()
{
  x += xVel;
  y += yVel;
  setPos(x,y);
}

/** After the alien drops the missile, it shoots off the screen in a random direction */
void DiveAlien::zoomOff()
{
  if(rand()%2 == 0)
  {
    xVel = 5;
  }
  else
  {
    xVel = -5;
  }
  yVel = ((rand() % 10)-10);
}
