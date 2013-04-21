#include "player.h"

Player::Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  x = xVal;
  y = yVal;
  xVelo = 0;
  yVelo = 0;
  lives = 3;
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
  std::cout<<"x "<<x<<" y "<<y<<std::endl;
}

void Player::onHit()
{
  if(lives > 0)
  {
    lives--;
  }
  else
  {
  
  }
}

void Player::setXVel(int xVelo)
{
  xVel = xVelo;
}

void Player::setXandY(int xVal, int yVal)
{
  x = xVal;
  y = yVal;
}
