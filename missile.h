#ifndef MISSILE_H
#define MISSILE_H

#include "object.h"

/** The missile class. Derives from the Object class. A missile moves only
 * vertically but explodes when it reaches a certain point on the screen
 * @author Joseph Boman
 */
class Missile: public Object
{
 public:
  Missile(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  void explode();
  /** This is used to control how long the explosion lasts. Starts at 50 */
  int time;
};

#endif
