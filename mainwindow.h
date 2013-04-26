#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QListView>
#include <QKeyEvent>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTimer>
#include <QTimeLine>
#include <QApplication>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPixmap>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "player.h"
#include "gamescene.h"
#include "basicalien.h"
#include "bullet.h"
#include "asteroid.h"
#include "lasteroid.h"
#include "missile.h"
#include "divealien.h"
#include "boss.h"
#include "laser.h"

/** The MainWindow class. Contains all of the Widgets, Items,
 * Layouts and Objects required to create the game.
 * @author Joseph Boman
 */

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    //Constructors and Destructors
    explicit MainWindow();
    ~MainWindow();
    //Shows the window
    void show();
    
private:
    //The scene and views
    GameScene *game;
    QGraphicsView *gameView;
    QGraphicsView *view;
    //The buttons
    QPushButton *startGame;
    QPushButton *quit;
    QPushButton *pause;
    //The high score list and model
    QListView *highScores;
    QStandardItemModel *hSModel;
    //The layouts
    QVBoxLayout *buttons;
    QFormLayout *nameLayout;
    QGridLayout *mainLayout;
    //The timer
    QTimer *timer;
    //The Instructions box
    QTextEdit *instructions;
    //The Name Box
    QLineEdit *nameField;
    //Special Objects
    Player *player;
    Boss *boss;
    Laser *laser;
    //Text Items
    QGraphicsSimpleTextItem *gameOver;
    QGraphicsSimpleTextItem *score;
    QGraphicsSimpleTextItem *scoreValue;
    //The PixMaps for various things
    QPixmap *bulletImage;
    QPixmap *basicAlienImage;
    QPixmap *playerImage;
    QPixmap *asteroidImage;
    QPixmap *lasteroidImage;
    QPixmap *diveAlienImage;
    QPixmap *missileImage;
    QPixmap *explodeImage;
    QPixmap *bossImage;
    QPixmap *deadlyLaser;
    QPixmap *sightLaser;
    QPixmap *livesImage;
    
    //Various members used to hold data in between functions
    std::string playerName;
    std::vector<QStandardItem*> highScoreList;
    std::vector<Object*> pBullets;
    std::vector<Object*> eBulletsandPlayer;
    std::vector<QGraphicsPixmapItem*> lives_;
    
    //Fills in the high scores from the high score file
    void getHighScores();
    
    //Other data members
    bool gameInProgress;
    int count;
    int laserCount;
    int score_;
    int highScores_[5];
    std::string names_[5];
    
public:
    //The keyboard Events
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    //Checks for collision
    std::vector<Object*>::iterator checkCollision(std::vector<Object*>::iterator it, bool &ok);
    //If the player is hit
    void playerHit();
    //Writes the high scores to a file
    void writeHighScores();
    //Replaces the high scores in the high score list
    void replaceHighScores();
    
public slots:
    //The slots that react to various in-game events
    void beginGame();
    void handleTimer();
    void pauseGame();
    void bossTimer();
};

#endif // MAINWINDOW_H
