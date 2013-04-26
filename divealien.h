#ifndef DIVEALIEN_H
#define DIVEALIEN_H

#include "object.h"
#include <cstdlib>

/** The DiveAlien class. Derives from the Object class. A DiveAlien moves both
 * horizontally and vertically
 * @author Joseph Boman
 */
class DiveAlien: public Object
{
 public:
  DiveAlien(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  //This is called after it drops the missile
  void zoomOff();
};

#endif
