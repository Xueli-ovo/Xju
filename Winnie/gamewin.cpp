#include "gamewin.h"
#include "ui_gamewin.h"

GameWin::GameWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWin)
{
    ui->setupUi(this);
}

GameWin::~GameWin()
{
    delete ui;
}
