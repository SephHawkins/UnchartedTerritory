#ifndef ASTEROID_H
#define ASTEROID_H

#include "object.h"

/** The Asteroid class. Derives from the Object class. An asteroid moves only vertically
 * @author Joseph Boman
 */
class Asteroid: public Object
{
 public:
  Asteroid(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
};

#endif
