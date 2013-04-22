#ifndef OBJECT_H
#define OBJECT_H
#include <QGraphicsPixmapItem>
#include <string>

class Object : public QGraphicsPixmapItem
{
 protected: 
  int x;
  int y;
  int xVel;
  int yVel;
  QPixmap *pixMap;
 public:
  Object(QPixmap *p, int xVal, int yVal, int xVelo, int yVelo);
  virtual void move() = 0;
  int getY(){return y;}
  int getX(){return x;}
  std::string type;
};
#endif
