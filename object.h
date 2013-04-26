#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsPixmapItem>
#include <string>

/** The base class for all items in the game. The object class derives from 
 * QGraphicsPixmapItem, and contains the virtual fuction move, as well as 
 * various protected variables
 * @author Joseph Boman
 */
class Object : public QGraphicsPixmapItem
{
 protected: 
  /** The x Coordinate */
  int x;
  /** The y Coordinate */
  int y;
  /** The x Velocity */
  int xVel;
  /** The y Velocity */
  int yVel;
  /** The QPixmap that will be the image */
  QPixmap *pixMap;
 public:
  Object(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  /** A virtual function for movement */
  virtual void move() = 0;
  /** Returns the y-value
   * @return The y-value
   */
  int getY(){return y;}
  /** Returns the x-value
   * @return The x-value
   */
  int getX(){return x;}
  /** The type of the object */
  std::string type;
};
#endif
