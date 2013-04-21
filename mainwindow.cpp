#include "mainwindow.h"

/** Goes through and initiates all the needed members 
 * for the program to function. Connects certain buttons to
 * their slots.
 */
MainWindow::MainWindow()  {
    
    //The Timer
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

    testBullet = NULL;
    //The Scene and the view
    game = new GameScene(this);
    game->setSceneRect(0,0, 600, 800);
    gameView = new QGraphicsView(game);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //gameView = new QGraphicsView(scene);
    view = new QGraphicsView();
    view->setFixedSize(600, 600);
    view->setWindowTitle("Game");
    
    //The Individual Layouts
    buttons = new QVBoxLayout();
    mainLayout = new QGridLayout();
    nameLayout = new QFormLayout();
    
    //The name field
    nameField = new QLineEdit();
    nameLayout->insertRow(1, "Name", nameField);
    
    //The High Score
    hSModel = new QStandardItemModel(5, 1);
    highScores = new QListView();
    
    //Fill the list of high scores from a file
    getHighScores();
    
    //The instructions
    instructions =  new QTextEdit("Instructions: Enter your name into the name box. Hit start to begin the game. Use the left and right arrowkeys to move left and right, and spacebar to shoot");
    instructions->setReadOnly(1);
    
    //The start and quit Buttons
    quit = new QPushButton("&Quit", this);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    startGame = new QPushButton("&Start", this);
    connect(startGame, SIGNAL(clicked()), this, SLOT(beginGame()));
    pause = new QPushButton("&Pause", this);
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    buttons->addWidget(startGame);
    buttons->addWidget(pause);
    buttons->addWidget(quit);
    
    //Adds everything to the main layout
    mainLayout->addWidget(highScores, 4, 0, 1, 1, 0);
    mainLayout->addWidget(instructions, 0, 0, 1, 1, 0);
    mainLayout->addLayout(nameLayout, 1, 0, 1, 1, 0);
    mainLayout->addLayout(buttons, 2, 0, 2, 1, 0);
    mainLayout->addWidget(gameView, 0, 1, 5, 2, 0);
    
    //Sets the columns and rows of the Grid Layout to be the same
    for(int i = 0; i < 3; i++)
    {
      mainLayout->setColumnMinimumWidth(i, 200);
      mainLayout->setRowMinimumHeight(i, 100);
    }
    view->setLayout(mainLayout);
}

/** Deallocates all the memory allocated by new statements
 * in this class 
 */
MainWindow::~MainWindow()
{
  
}

/** Shows the view */
void MainWindow::show()
{
  view->show();
  nameField->setFocus();
}

/** Called when the start Game button is pressed.
 */
void MainWindow::beginGame()
{
  QString temp = nameField->text();
  playerName = temp.toStdString();
  if(playerName == "")
  {
    nameField->setFocus();
    return;
  }
  playerImage = new QPixmap("player.png");
  basicAlienImage = new QPixmap("BasicAlien.png");
  bulletImage = new QPixmap("Bullet.png");
  player = new Player(playerImage, 275, 615, 0, 0);
  testAlien = new BasicAlien(basicAlienImage, 80, 300, 1, 0);
  game->addItem(testAlien);
  game->addItem(player);
  timer->start();
  gameView->setFocus();
  /*//Creates the board
  int *values;
  int dim = static_cast<int>(sqrt(iSize));
  GUITile *tempTile;
  if(b_)
  {
    delete b_;
    while(tiles.size() != 0)
    {
      tempTile = tiles.back();
      delete tempTile;
      tiles.pop_back();
    }
  }
  moves = 0;
  b_ = new Board(iSize, iInitMoves, iSeed);
  //Runs the heuristic to determine the optimal set of moves
  PuzzleHeuristic *ph = new ManhattanHeuristic;
  PuzzleSolver ps(*b_);
  ps.run(ph);
  bestMoves = ps.getSolution().size();
  delete ph;
  values = b_->getTiles();
  //Creates the graphical tiles
    for(int i = 0; i < iSize; i++)
    {
      if(values[i] != 0)
      {
        tempTile = new GUITile(i, values[i], (75*(i%dim)), (75*(i/dim)), 75, 75, this);
        tiles.push_back(tempTile);
        scene->addItem(tempTile);
        scene->addItem(tempTile->getTextItem());
      }
    }
    //If the puzzle is solved, display the win scenario
  if(b_->solved())
  {
    //If they have solved a puzzle before this
    if(puzzle_solved == 1)
    {
      delete winner;
      delete winLayout;
      delete winView;
    }
    puzzle_solved = 1;
    winView = new QGraphicsView();
    winLayout = new QHBoxLayout();
    winner = new QPushButton("You Won!\nMoves: 0\nOptimal Moves: 0");
    connect(winner, SIGNAL(clicked()), winView, SLOT(close()));
    winLayout->addWidget(winner);
    winView->setLayout(winLayout);
    winView->show();
  }
}*/
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
  QWidget::keyPressEvent(e);
  switch(e->key())
  {
    case Qt::Key_A:
    {
      player->setXVel(0);
    }
    case Qt::Key_D:
    {
      player->setXVel(0);
    }
  }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
  QWidget::keyPressEvent(e);
  switch(e->key())
  {
    case Qt::Key_A:
    {
      player->setXVel(-1);
      break;
    }
    case Qt::Key_D:
    {
      player->setXVel(1);
      break;
    }
    case Qt::Key_Control:
    {
      testBullet = new Bullet(bulletImage, player->getX()+24, player->getY(), 0, -2);
      game->addItem(testBullet);
      break;
    }
    case Qt::Key_P:
    {
      if(timer->isActive())
        timer->stop();
      else
        timer->start();
    }
  }
}

void MainWindow::handleTimer()
{
  player->move();
  if(testBullet != NULL)
    testBullet->move();
  testAlien->move();
}

void MainWindow::pauseGame()
{

}

void MainWindow::getHighScores()
{
  std::ifstream hsfile;
  QString score;
  std::string scoreLine;
  QStandardItem* si;
  hsfile.open("highscores.txt");
  //If the file doesn't exist, create a default list of high scores
  if(!hsfile.is_open())
  {
    score = "Tommy Trojan - 100000";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(5, si);
    score = "Tommy Trojan - 200000";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(4, si);
    score = "Tommy Trojan - 300000";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(3, si);
    score = "Tommy Trojan - 400000";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(2, si);
    score = "Tommy Trojan - 500000";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(1, si);
    score = "- - - - - - -High Scores- - - - - - -";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(0, si);
    highScores->setModel(hSModel);
  }
  else
  {
    score = "- - - - - - -High Scores- - - - - - -";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(0,si);
    for(int i = 1; i < 6; i++)
    {
      std::getline(hsfile, scoreLine);
      score = QString::fromStdString(scoreLine);
      si = new QStandardItem(score);
      highScoreList.push_back(si);
      hSModel->setItem(i,si);
    }
    highScores->setModel(hSModel);
  }
}
