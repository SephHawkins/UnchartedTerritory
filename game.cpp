#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Programming Assignment #5
 * @section purpose Purpose/Overview
 * This program runs a top scrolling 
 * space shooter game. The player must avoid enemies
 * and shoot them to get points. At the 
 * end is a boss that is extremely difficult
 * @section requirements Requirements
 * To run, enter ./game_jboman
 */
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
