#ifndef BOSS_H
#define BOSS_H

#include "object.h"

/** The Boss class. Derives from the Object class. The boss is stationary after it reaches its target position
 * @author Joseph Boman
 */
class Boss: public Object
{
 public:
  Boss(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  /** The remaining health of the boss. Starts at 100 */
  int health;
};

#endif
