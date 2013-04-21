#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>
#include <iostream>

class MainWindow;

class GameScene: public QGraphicsScene
{
  public:
   MainWindow *mw_;   
  protected:
   void keyPressEvent(QKeyEvent *e);
   void keyReleaseEvent(QKeyEvent *e);
  public:
   GameScene(MainWindow *mw);

};

#endif
