#ifndef BULLET_H
#define BULLET_H

#include "object.h"

/** The Bullet class. Derives from the Object class. A bullet moves only vertically
 * @author Joseph Boman
 */
class Bullet: public Object
{
 public:
  Bullet(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
};

#endif
