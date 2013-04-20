#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Programming Assignment #4
 * @section purpose Purpose/Overview
 * This program represents a puzzle game of size 9, or 16
 * with a graphic interface. The user may create a game and 
 * then play by clicking the tiles to move them. They also may use 
 * a cheat function to get the solution.
 * The cheat implements
 * the A* algorithm to solve the puzzle
 * @section requirements Requirements
 * To run, enter ./puzzle_jboman
 */
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
