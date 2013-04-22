#include "player.h"

Player::Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  lives = 0;
  type = "Player";
}

void Player::move()
{
  if(x < 120 && xVel < 0)
    return;
  else if(x > 420 && xVel > 0)
    return;
  x += xVel;
  y = y;
  setPos(x,y);
}

void Player::setXVel(int xVelo)
{
  xVel = xVelo;
}
