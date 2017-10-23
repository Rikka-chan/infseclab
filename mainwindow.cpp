#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel* some = new QLabel("Fuck it!", this);
    SqlSingleton* db = SqlSingleton::Instance();
}

MainWindow::~MainWindow()
{

}
