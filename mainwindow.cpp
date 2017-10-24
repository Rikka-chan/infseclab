#include "mainwindow.h"
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    central = new QWidget(this);
    setCentralWidget(central);

    QGridLayout* main_layout = new QGridLayout(central);
    central->setLayout(main_layout);

    QLabel* username_label = new QLabel(tr("Username"), central);
    QLabel* pass_label = new QLabel(tr("Password"), central);

    QLineEdit* username = new QLineEdit(central);
    QLineEdit* password = new QLineEdit(central);
    password->setEchoMode(QLineEdit::Password);
    password->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    password->setMaximumHeight(30);
    username->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    username->setMaximumHeight(30);

    QPushButton* login_btn = new QPushButton(tr("Login"), central);

    main_layout->addWidget(username_label, main_layout->rowCount(), 0);
    main_layout->addWidget(username, main_layout->rowCount() - 1, 1);
    main_layout->addWidget(pass_label, main_layout->rowCount(), 0);
    main_layout->addWidget(password, main_layout->rowCount() - 1, 1);

    main_layout->addWidget(login_btn, main_layout->rowCount(), 0, 1,2, Qt::AlignCenter);
    SqlSingleton* db = SqlSingleton::Instance();
    setMinimumSize(160, 160);
    createActions();
    createMenus();
}


void MainWindow::createActions(){
    closeAct = new QAction(tr("Close"), this);
    logoutAct = new QAction(tr("Logout"), this);
    aboutAct = new QAction(tr("About"), this);
    russianAct = new QAction(tr("Russian"), this);
    englishAct = new QAction(tr("English"), this);

    connect(closeAct, &QAction::triggered, this, &MainWindow::close);
    connect(logoutAct, &QAction::triggered, this, &MainWindow::logout);
    connect(russianAct, &QAction::triggered, this, &MainWindow::russian);
    connect(englishAct, &QAction::triggered, this, &MainWindow::english);
}

void MainWindow::createMenus(){
    sub_menu = menuBar()->addMenu(tr("&Menu"));
    sub_menu->addAction(logoutAct);
    sub_menu->addAction(closeAct);

    lang_menu = menuBar()->addMenu(tr("&Language"));
    lang_menu->addAction(russianAct);
    lang_menu->addAction(englishAct);

    help_menu = menuBar()->addMenu(tr("&Help"));
    help_menu->addAction(aboutAct);
}

void MainWindow::logout(){}
void MainWindow::about(){}
void MainWindow::russian(){}
void MainWindow::english(){}

MainWindow::~MainWindow()
{

}
