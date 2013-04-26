#ifndef BASICALIEN_H
#define BASICALIEN_H

#include "object.h"

/** The basic Alien class. Derives from the Object class. An alien moves both
 * horizontally and vertically
 * @author Joseph Boman
 */
class BasicAlien: public Object
{
 public:
  BasicAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
};

#endif
