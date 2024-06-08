#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dia_settings.h"
#include "gamewin.h"

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

    QMessageBox::information(this,"鸣谢","Code:Xueliovo\nUI:Xueliovo\nPainter:🤐待宰羔阳😈");
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

void MainWindow::on_action_cbk_triggered()
{
    QMessageBox::information(this,"联系方式","Oops!我们还没有制作相关的反馈渠道呢,如有任何想法建议请联系:\nxlywkk@163.com\
\n还请各位大佬手下留情,本程序仅做练习~");
}


void MainWindow::on_action_release_triggered()
{
    CustomWidget *widget = new CustomWidget();
    widget->show();
}


void MainWindow::on_button_start_clicked()
{
    GameWin win;
    win.show();

}

