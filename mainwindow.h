#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QListView>
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
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>


/** The MainWindow class. Contains all of the Widgets, Items,
 * Layouts and Objects required to create the program.
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
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsView *gameView;
    //The buttons
    QPushButton *startGame;
    QPushButton *quit;
    QPushButton *pause;
    //The list view and items for it
    QListView *highScores;
    QStandardItemModel *hSModel;
    //The layouts
    QVBoxLayout *buttons;
    QFormLayout *nameLayout;
    QGridLayout *mainLayout;
    //The timer
    QTimer *timer;
    //The Instructions
    QTextEdit *instructions;
    //The Edit Box
    QLineEdit *nameField;
    
    //Various members used to hold data in between functions
    std::string playerName;
    std::vector<QStandardItem*> highScoreList;
    
    //Fills in the high scores from the high score file
    void getHighScores();
    
public slots:
    //The slots that react to various in-game events
    void beginGame();
    void handleTimer();
    void pauseGame();
};

#endif // MAINWINDOW_H
