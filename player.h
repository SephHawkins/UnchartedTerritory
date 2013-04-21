#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include "object.h"
#include <iostream>

class Player: public Object
{
 private:
  int lives;
 public:
  Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  void onHit();
  void move();
  void setXVel(int xVelo);
  int getX(){return x;}
  int getY(){return y;}
};

#endif
