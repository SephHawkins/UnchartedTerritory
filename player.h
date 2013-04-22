#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player: public Object
{
 public:
  int lives;
  Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void move();
  void setXVel(int xVelo);
};

#endif
