#include "mainwindow.h"

/** Goes through and initiates all the needed members 
 * for the program to function. Connects certain buttons to
 * their slots.
 */
MainWindow::MainWindow()  {
    boss = 0;
    gameInProgress = 0;
    count = 0;
    score_ = 0;
    laserCount = -1000;
    
    gameOver = NULL;
    
    //The Timer
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

    //The Scene and the view
    game = new GameScene(this);
    game->setSceneRect(0,0, 600, 800);
    QPixmap background("images/background.jpg");
    QBrush temp(background);
    game->setBackgroundBrush(temp);
    gameView = new QGraphicsView(game);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view = new QGraphicsView();
    view->setFixedSize(600, 600);
    view->setWindowTitle("Game");
    
    //The Pixmaps
    playerImage = new QPixmap("images/player.png");
    basicAlienImage = new QPixmap("images/BasicAlien.png");
    bulletImage = new QPixmap("images/Bullet.png");
    asteroidImage = new QPixmap("images/asteroid.png");
    lasteroidImage = new QPixmap("images/lasteroid.png");
    diveAlienImage = new QPixmap("images/diveAlien.png");
    missileImage = new QPixmap("images/missile.png");
    explodeImage = new QPixmap("images/explosion.png");
    bossImage = new QPixmap("images/boss.png");
    deadlyLaser = new QPixmap("images/laser.png");
    sightLaser = new QPixmap("images/lasersight.png");
    livesImage = new QPixmap("images/lives.png"); 
  
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
    instructions =  new QTextEdit("Instructions: Enter your name into the name box. Hit start to begin the game. Use the left and right arrowkeys to move left and right, and spacebar to shoot. Avoid or shoot the aliens, asteroids and their weapons");
    instructions->setReadOnly(1);
    
    //The start, pause, and quit Buttons
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
      mainLayout->setRowMinimumHeight(i, 80);
    }
    view->setLayout(mainLayout);
}

/** Deallocates all the memory allocated by new statements
 * in this class 
 */
MainWindow::~MainWindow()
{
  writeHighScores();
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
  if(gameInProgress)
  {
    return;
  }
  if(gameOver != NULL)
  {
    game->removeItem(gameOver);
    delete gameOver;
    game->removeItem(score);
    delete score;
    game->removeItem(scoreValue);
    delete scoreValue;
    score_ = 0;
    if(laserCount != -1000)
    {
      disconnect(timer, SIGNAL(timeout()), this, SLOT(bossTimer()));
      connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    }
  }
  count = 0;
  QString temp = nameField->text();
  playerName = temp.toStdString();
  if(playerName == "")
  {
    nameField->setFocus();
    return;
  }
  gameInProgress = 1;
  player = new Player(playerImage, 275, 615, 0, 0);
  eBulletsandPlayer.push_back(player);
  game->addItem(player);
  QBrush brush(Qt::white);
  QFont serifFont("Times", 20);
  score = new QGraphicsSimpleTextItem("Score:");
  score->setPos(120, 110);
  score->setBrush(brush);
  score->setFont(serifFont);
  game->addItem(score);
  scoreValue = new QGraphicsSimpleTextItem("0");
  scoreValue->setPos(190, 110);
  scoreValue->setBrush(brush);
  scoreValue->setFont(serifFont);
  game->addItem(scoreValue);
  for(int i = 0; i < 3; i++)
  {
    QGraphicsPixmapItem *life = new QGraphicsPixmapItem();
    life->setPixmap(*livesImage);
    life->setPos(380+(35*i),115);
    lives_.push_back(life);
    game->addItem(life);
  }
  timer->start();
  gameView->setFocus();
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
  if(!timer->isActive() && e->key() != Qt::Key_P)
  {
    return;
  }
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
      if(pBullets.size() < 3)
      {
        Bullet *bullet = new Bullet(bulletImage, player->getX()+24, player->getY(), 0, -3); 
        game->addItem(bullet);
        pBullets.push_back(bullet);
      }
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

std::vector<Object*>::iterator MainWindow::checkCollision(std::vector<Object*>::iterator it, bool &ok)
{
  std::vector<Object*>::iterator hit;
  for(hit = eBulletsandPlayer.begin()+1; hit < eBulletsandPlayer.end(); ++hit)
    {
      if((*it)->collidesWithItem(*hit))
      {
        ok = 1;
        return hit;
      }
    }
    ok = 0;
    return hit;
}
void MainWindow::handleTimer()
{
  bool ok;
  //If it's boss time
  if(count == 5000)
  {
    timer->stop();
    count = 0;
    for(std::vector<Object*>::iterator it = pBullets.begin(); it < pBullets.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    pBullets.clear();
    for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin()+1; it < eBulletsandPlayer.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    eBulletsandPlayer.clear();
    eBulletsandPlayer.push_back(player);
    boss = new Boss(bossImage, 175, -300, 0, 1);
    game->addItem(boss);
    disconnect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(bossTimer()));
    timer->start();
    return;
  }
  count++;
  //Moving the player
  player->move();
  
  //Creating asteroids and Large Asteroids.
  if(count % 150 == 0)
  {
    if(count % 600 == 0)
    {
    lAsteroid *lasteroid = new lAsteroid(lasteroidImage, (rand()%300+120), (rand()%60-50), 0, 1);
    game->addItem(lasteroid);
    eBulletsandPlayer.push_back(lasteroid);
    }
    else
    {
    Asteroid *asteroid = new Asteroid(asteroidImage, (rand()%300+120), (rand()%60-50), 0, 1);
    game->addItem(asteroid);
    eBulletsandPlayer.push_back(asteroid);
    }
  }

  //Creating Alien Objects at certain intervals
  if(count % 420 == 0)
  {
    int check = rand()%2;
    switch(check)
    {
      case 0:
      {
        BasicAlien *alien = new BasicAlien(basicAlienImage, 60, (rand()%250+100), 1, 0);
        game->addItem(alien);
        eBulletsandPlayer.push_back(alien);
        break;
      }
      case 1:
      {
        BasicAlien *alien = new BasicAlien(basicAlienImage, 440, (rand()%250+100), -1, 0);
        game->addItem(alien);
        eBulletsandPlayer.push_back(alien);
        break;
      }
    }
  }
  
  //Creating diveAlien Objects at certain intervals
  if(count % 981 == 0)
  {
    DiveAlien *diveAlien = new DiveAlien(diveAlienImage, (rand()%300+120), 0, 0, 1);
    game->addItem(diveAlien);
    eBulletsandPlayer.push_back(diveAlien);
  }
  //Moving the objects, other than the player
    for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin()+1; it != eBulletsandPlayer.end(); ++it)
    {
      if(it < eBulletsandPlayer.begin() || it > eBulletsandPlayer.end())
        break;
      /*std::cout<<"Begin "<<(*eBulletsandPlayer.begin())<<std::endl;
      std::cout<<"End "<<(*eBulletsandPlayer.end()-1)<<std::endl;
      std::cout<<"Inner loop began"<<(*it)<<std::endl;
      std::cout<<"Type: "<<(*it)->type<<std::endl;*/
      //If it's off the screen
      if((*it)->getY() < -60 || (*it)->getX() > 460 || (*it)->getX() < 0 || (*it)->getY() > 700)
      {
        delete (*it);
        (*it) = NULL;
        continue;
      }
      //If it's a Dive Alien
      if((*it)->type == "DiveAlien")
      {
        if((*it)->getY() > 300)
        {
          DiveAlien *temp = (DiveAlien*) (*it);
          temp->zoomOff();
          Missile *missile = new Missile(missileImage, (*it)->getX()+16, (*it)->getY()+48, 0, 1);
          game->addItem(missile);
          eBulletsandPlayer.push_back(missile);
        }
      }
    
      //If it's a Basic Alien
      if((*it)->type == "BasicAlien")
      {
        if((*it)->getX() == 200 || (*it)->getX() == 350)
        {
          Bullet *bullet = new Bullet(bulletImage, (*it)->getX()+24, (*it)->getY()+64, 0, 2);
          game->addItem(bullet);
          eBulletsandPlayer.push_back(bullet);
        }
      }
    
      //If it's a missile
      if((*it)->type == "Missile")
      {
        if((*it)->getY() > 580)
        {
          Missile *temp = (Missile*) (*it);
          temp->explode();
          temp->setPixmap(*explodeImage);
          if(temp->time == 0)
          {
            delete (*it);
            (*it) = NULL;
            continue;
          }
        }
      }
    }
  for(unsigned int i = 0; i < eBulletsandPlayer.size(); i++)
  {
    if(eBulletsandPlayer[i] == NULL)
    {
      eBulletsandPlayer[i] = eBulletsandPlayer[eBulletsandPlayer.size()-1];
      eBulletsandPlayer.pop_back();
    }
  }
  for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin()+1; it != eBulletsandPlayer.end(); ++it)
  {
    (*it)->move();
  }
  
  //Moving the player's bullets
  for(std::vector<Object*>::iterator it = pBullets.begin(); it < pBullets.end(); ++it)
  {
    (*it)->move();
    if((*it)->getY() < 120)
    {
      delete (*it);
      (*it) = NULL;
    }
  }
  for(unsigned int i = 0; i < pBullets.size(); i++)
  {
    if(pBullets[i] == NULL)
    {
      pBullets[i] = pBullets[pBullets.size()-1];
      pBullets.pop_back();
    }
  }
  //Checking for collision between player and enemies
  std::vector<Object*>::iterator pit = eBulletsandPlayer.begin();
  checkCollision(pit, ok);
  if(ok)
  {
    playerHit();
    return;
  }
  //Checking for collision between player's bullets and the enemies
  for(std::vector<Object*>::iterator it = pBullets.begin(); it < pBullets.end(); ++it)
  {
    std::vector<Object*>::iterator hit = checkCollision(it, ok);
    if(ok)
    {
      if((*hit)->type == "Missile" || (*hit)->type == "Bullet" || (*hit)->type == "Asteroid")
      {
        score_ += 1;
      }
      else if((*hit)->type == "LAsteroid")
      {
        score_ += 2;
      }
      else if((*hit)->type == "BasicAlien" || (*hit)->type == "DiveAlien")
      {
        score_ += 3;
      }
      QString temp = QString::number(score_);
      scoreValue->setText(temp);
      /*if((*hit)->type == "LAsteroid")
      {
        Asteroid *asteroid = new Asteroid(asteroidImage, (*hit)->getX()-16, (*hit)->getY(), 0, 1);
        game->addItem(asteroid);
        eBulletsandPlayer.push_back(asteroid);
        Asteroid *asteroidT = new Asteroid(asteroidImage, (*hit)->getX()+48, (*hit)->getY(), 0, 1);
        game->addItem(asteroidT);
        eBulletsandPlayer.push_back(asteroidT);
      }*/
      delete (*it);
      delete (*hit);
      (*it) = NULL;
      eBulletsandPlayer.erase(hit);
      break;
    }
  }
  for(unsigned int i = 0; i < pBullets.size(); i++)
  {
    if(pBullets[i] == NULL)
    {
      pBullets[i] = pBullets[pBullets.size()-1];
      pBullets.pop_back();
    }
  }
}

void MainWindow::playerHit()
{
  timer->stop();
  score_ -= 5;
  QString temp = QString::number(score_);
  scoreValue->setText(temp);
  //If the player has more lives
  if(player->lives > 0)
  {
    player->lives--;
    for(std::vector<Object*>::iterator it = pBullets.begin(); it != pBullets.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    pBullets.clear();
    for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin()+1; it != eBulletsandPlayer.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    eBulletsandPlayer.clear();
    eBulletsandPlayer.push_back(player);
    delete lives_[lives_.size()-1];
    lives_.pop_back();
    timer->start();
  }
  //If the player is out of lives
  else
  {
  for(std::vector<Object*>::iterator it = pBullets.begin(); it != pBullets.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    pBullets.clear();
    for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin(); it != eBulletsandPlayer.end(); ++it)
    {
      game->removeItem(*it);
      delete(*it);
    }
    eBulletsandPlayer.clear();
    delete lives_[lives_.size()-1];
    lives_.pop_back();
    gameInProgress = 0;
    QBrush brush(Qt::white);
    QFont serifFont("Times", 40);
    gameOver = new QGraphicsSimpleTextItem("Game Over");
    gameOver->setBrush(brush);
    gameOver->setFont(serifFont);
    gameOver->setPos(180, 350);
    if(score_ > highScores_[4])
    {
      gameOver->setText(gameOver->text()+"\nHigh Score!");
      replaceHighScores();
    }
    game->addItem(gameOver);
  }
}

void MainWindow::pauseGame()
{
  if(timer->isActive())
  {
    timer->stop();
    gameView->setFocus();
  }
  else
  {
    timer->start();
    gameView->setFocus();
  }
}


void MainWindow::bossTimer()
{
  int bulletSpeed;
  if(boss->getY() < 140)
  {
    boss->move();
    laserCount = 1;
  }
  else
  {
    if(count == 0)
    {
      bulletSpeed = 2;
      laser = new Laser(sightLaser, 285, 370, 0, 0);
    }
    count++;
    //Fixing and making the laser
    if(laserCount == 500)
    {
      laser->setPixmap(*sightLaser);
      game->addItem(laser);
      laser->deadly = 0;
    }
    if(laserCount == 1000)
    {
      laser->setPixmap(*deadlyLaser);
      laser->deadly = 1;    
      laserCount = -500;
    }
    if(laserCount == 0)
    {
      game->removeItem(laser);
      laser->deadly = 0;
    }
    laserCount++;
    //Firing Bullets
    if(count % 25 == 0)
    {
      Bullet *bullet = new Bullet(bulletImage, rand()%234+175, 275, 0, bulletSpeed);
      game->addItem(bullet);
      eBulletsandPlayer.push_back(bullet);
    }
    //Checking the bullets hitting the boss
    for(std::vector<Object*>::iterator it = pBullets.begin(); it < pBullets.end(); ++it)
    {
      if((*it)->collidesWithItem(boss))
      {
        score_ += 5;
        QString temp = QString::number(score_);
        scoreValue->setText(temp);
        boss->health--;
        if(boss->health == 50)
        {
          bulletSpeed++;
        }
        else if(boss->health == 25)
        {
          bulletSpeed++;
        }
        if(boss->health == 0)
        {
          score_ += 500;
          QString temp = QString::number(score_);
          scoreValue->setText(temp);
          delete boss;
          delete laser;
          timer->stop();
          for(std::vector<Object*>::iterator it = pBullets.begin(); it != pBullets.end(); ++it)
          {
            game->removeItem(*it);
            delete(*it);
          }
          pBullets.clear();
          for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin(); it != eBulletsandPlayer.end(); ++it)
          {
            game->removeItem(*it);
            delete(*it);
          }
          eBulletsandPlayer.clear();
          gameInProgress = 0;
          QBrush brush(Qt::white);
          QFont serifFont("Times", 40);
          gameOver = new QGraphicsSimpleTextItem("YOU WIN!");
          gameOver->setBrush(brush);
          gameOver->setFont(serifFont);
          gameOver->setPos(180, 350);
          if(score_ > highScores_[4])
          {
            gameOver->setText(gameOver->text()+"\nHigh Score!");
            replaceHighScores();
          }
          game->addItem(gameOver);
          return;
        }
        delete (*it);
        (*it) = NULL;
        break;
      }
    }
    for(unsigned int i = 0; i < pBullets.size(); i++)
    {
      if(pBullets[i] == NULL)
      {
        pBullets[i] = pBullets[pBullets.size()-1];
        pBullets.pop_back();
      }
    }
    
    //Checking the bullets hitting the bullets
    bool ok;
    for(std::vector<Object*>::iterator it = pBullets.begin(); it < pBullets.end(); ++it)
    {
      std::vector<Object*>::iterator hit = checkCollision(it, ok);
      if(ok)
      {
        score_++;
        QString temp = QString::number(score_);
        scoreValue->setText(temp);
        delete (*it);
        delete (*hit);
        (*it) = NULL;
        eBulletsandPlayer.erase(hit);
        break;
      }
    }
    for(unsigned int i = 0; i < pBullets.size(); i++)
    {
      if(pBullets[i] == NULL)
      {
        pBullets[i] = pBullets[pBullets.size()-1];
        pBullets.pop_back();
      }
    }
    
    //Checking the bullets hitting the player
    std::vector<Object*>::iterator pit = eBulletsandPlayer.begin();
    checkCollision(pit, ok);
    if(ok)
    {
      if(player->lives == 0)
      {
        delete laser;
        delete boss;
      }
      playerHit();
      if(laserCount > 1000 || laserCount < 0)
        laserCount = 0;
      else
        laserCount = 1;
      return;
    }
    
    //Checking the laser and player
    if(laser->deadly == 1)
    {
      if(laser->collidesWithItem(player))
      {
        if(player->lives == 0)
        {
          delete laser;
          delete boss;
        }
        playerHit();
        if(laserCount > 1000 || laserCount < 0)
          laserCount = 0;
        else
          laserCount = 1;
        return;
      }
    }
    
    //Moving the player
    player->move();
    //Moving the enemy bullets
    for(std::vector<Object*>::iterator it = eBulletsandPlayer.begin()+1; it != eBulletsandPlayer.end(); ++it)
    {
      (*it)->move();
      if((*it)->getY() > 700)
      {
        delete (*it);
        (*it) = NULL;
      }
    }
    for(unsigned int i = 1; i < eBulletsandPlayer.size(); i++)
    {
      if(eBulletsandPlayer[i] == NULL)
      {
        eBulletsandPlayer[i] = eBulletsandPlayer[eBulletsandPlayer.size()-1];
        eBulletsandPlayer.pop_back();
      }
    }
    //Moving the player's bullets
    for(std::vector<Object*>::iterator it = pBullets.begin(); it != pBullets.end(); ++it)
    {
      (*it)->move();
      if((*it)->getY() < 120)
      {
        delete (*it);
        (*it) = NULL;
      }
    }
    for(unsigned int i = 0; i < pBullets.size(); i++)
    {
      if(pBullets[i] == NULL)
      {
        pBullets[i] = pBullets[pBullets.size()-1];
        pBullets.pop_back();
      }
    }
    
    
  }
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
    score = "Tommy Trojan - 100";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(5, si);
    score = "Tommy Trojan - 200";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(4, si);
    score = "Tommy Trojan - 300";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(3, si);
    score = "Tommy Trojan - 400";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(2, si);
    score = "Tommy Trojan - 500";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(1, si);
    score = "- - - - - - -High Scores- - - - - - -";
    si = new QStandardItem(score);
    highScoreList.push_back(si);
    hSModel->setItem(0, si);
    highScores->setModel(hSModel);
    for(int i = 0; i < 5; i++)
    {
      highScores_[i] = ((i+1)*100);
      names_[i] = "Tommy Trojan";
    }
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
    int scores;
    hsfile.close();
    hsfile.open("highscores.txt");
    for(int i = 0; i < 5; i++)
    {
      std::getline(hsfile, scoreLine, '-');
      names_[i] = scoreLine;
      hsfile>>scoreLine;
      scores = std::atoi(scoreLine.c_str());
      highScores_[i] = scores;
    }
    highScores->setModel(hSModel);
  }
}

void MainWindow::replaceHighScores()
{
  QStandardItem* si;
  int i;
  for(i = 4; i >= 0; i--)
  {
    if(highScores_[i] > score_)
      break;
  }
  for(int q = 4; q > (i+1); q--)
  {
    highScores_[q] = highScores_[q-1];
    names_[q] = names_[q-1];
  }
  names_[i+1] = playerName;
  highScores_[i+1] = score_;
  QString score(QString::fromStdString(playerName));
  score = score + " - ";
  QString temp;
  temp.setNum(score_);
  score = score + temp;
  QStandardItem *temp_;
  si = new QStandardItem(score);
  hSModel->setItem(5, si);
  highScoreList.push_back(si);
  for(int j = 5; j > i+2; j--)
  {
    temp_ = hSModel->takeItem(j-1);
    si = hSModel->takeItem(j);
    hSModel->setItem(j, temp_);
    hSModel->setItem(j-1, si);

  }
  highScores->setModel(hSModel);
}

void MainWindow::writeHighScores()
{
  std::ofstream output;
  output.open("highscores.txt");
  for(int i = 0; i < 5; i++)
  {
    if(names_[i] == playerName)
    {
      output<<std::endl;
      output<<names_[i]<<" - "<<highScores_[i];
    }
    else
      output<<names_[i]<<"- "<<highScores_[i];
  }
}
