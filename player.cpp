#include "player.h"

/** Creates a player that has the values specified.  Inits the type to be Player.  Starts with 3 lives.
 * @param p The QPixmap that will be the image displayed
 * @param xVal The x Position of the top left corner
 * @param yVal The y Position of the top left corner
 * @param xVelo The initial horizontal velocity
 * @param yVelo The initial vertical veloctiy
 */
Player::Player(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  lives = 2;
  type = "Player";
}

/** Moves the player, unless it is on the edge of the screen */
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

/** Sets the x velocity
 * @param xVelo The new x velocity
 */
void Player::setXVel(int xVelo)
{
  xVel = xVelo;
}
