#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dia_settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"---主程序启动---\n";
    connect(setting,SIGNAL(send_size(int,int)),this,SLOT(change_size(int,int)));
}

MainWindow::~MainWindow()
{
    qDebug()<<"---主程序退出---\n";
    delete ui;
}


void MainWindow::on_action_2_triggered()
{
    QString msgTitle="关于 Winnie";
    QString msgInfo="Winnie Cat Version Dev 1.0\n Xju Project.\nPowered by Qt 5.15";
    QMessageBox::information(this,msgTitle,msgInfo,QMessageBox::Ok,QMessageBox::NoButton);
}


void MainWindow::on_actionWinniesettings_triggered()
{
    setting->show();
    qDebug()<<"-设置窗口被打开\n";
}


void MainWindow::on_button_settings_clicked()
{
    setting->show();
    qDebug()<<"-设置窗口被打开\n";
}


void MainWindow::change_size(int x,int y){
    //setup window
    this->setMaximumSize(x,y);
    this->setMinimumSize(x,y);
    this->setGeometry(this->x(),this->y(),x,y);
    qDebug()<<"Set Window Size Successfully\n";

    //setup widgets

}
