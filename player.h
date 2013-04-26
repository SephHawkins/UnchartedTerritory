#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

/** The Player class. Derives from the Object class. The player moves horizontally
 * in reponse to keyboard commands.
 * @author Joseph Boman
 */
class Player: public Object
{
 public:
  /** This is one smaller than the total lives the player has. Starts at 2 */
  int lives;
  Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  void setXVel(int xVelo);
};

#endif
