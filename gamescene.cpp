#include "gamescene.h"
#include "mainwindow.h"

GameScene::GameScene(MainWindow *mw)
{
  mw_ = mw;
}

void GameScene::keyReleaseEvent(QKeyEvent *e)
{
  //QGraphicsScene::keyReleaseEvent(e);
  mw_->keyReleaseEvent(e);
}

void GameScene::keyPressEvent(QKeyEvent *e)
{
  //QGraphicsScene::keyPressEvent(e);
  mw_->keyPressEvent(e);
}

