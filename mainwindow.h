#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "sqlsingleton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget* central;
    void createActions();
    void createMenus();

    QMenu *sub_menu;
    QMenu *help_menu;
    QMenu *lang_menu;
    QAction *aboutAct;
    QAction *closeAct;
    QAction *logoutAct;
    QAction* russianAct;
    QAction* englishAct;

private slots:
    void about();
    void logout();
    void russian();
    void english();
};

#endif // MAINWINDOW_H
