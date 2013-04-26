#ifndef LASTEROID_H
#define LASTEROID_H

#include "object.h"

/** The large Asteroid class. Derives from the Object class. A large Asteroid moves only vertically
 * @author Joseph Boman
 */
class lAsteroid: public Object
{
 public:
  lAsteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
};

#endif
