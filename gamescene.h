#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>

class MainWindow;

/** This class represents the scene. It derives from QGraphicsScene 
 * and is used to reimplement the keyPressEvent and keyReleaseEvent
 * @author Joseph Boman
 */
class GameScene: public QGraphicsScene
{
  public:
   /** The MainWindow that created this scene */
   MainWindow *mw_;   
  protected:
   void keyPressEvent(QKeyEvent *e);
   void keyReleaseEvent(QKeyEvent *e);
  public:
   GameScene(MainWindow *mw);

};

#endif
