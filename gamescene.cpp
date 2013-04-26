#include "gamescene.h"
#include "mainwindow.h"

/** Inits the GameScene, passing it a pointer to the MainWindow class
 * @param mw The MainWindow that created the GameScene
 */
GameScene::GameScene(MainWindow *mw)
{
  mw_ = mw;
}

/** Called when a key is released, and calls the 
 * MainWindow's keyReleaseEvent
 * @param e The QKeyEvent
 */
void GameScene::keyReleaseEvent(QKeyEvent *e)
{
  mw_->keyReleaseEvent(e);
}

/** Called when a key is pressed, and calls the 
 * MainWindow's keyPressEvent
 * @param e The QKeyEvent
 */
void GameScene::keyPressEvent(QKeyEvent *e)
{
  mw_->keyPressEvent(e);
}

