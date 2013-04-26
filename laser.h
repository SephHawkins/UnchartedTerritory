#ifndef LASER_H
#define LASER_H

#include "object.h"

/** The Laser class. Derives from the Object class. The laser is completely
 * stationary, but changes its deadliness
 * @author Joseph Boman
 */
class Laser: public Object
{
 public:
  Laser(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  /** A bool to see if the laser is deadly 
   * True if it is, false otherwise 
   */
  bool deadly;
};

#endif
