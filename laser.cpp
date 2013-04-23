#include "laser.h"

Laser::Laser(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo): Object(p, xVal, yVal, xVelo, yVelo)
{
  type = "Laser";
  deadly = 0;
}

void Laser::move()
{

}
