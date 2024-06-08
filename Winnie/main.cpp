#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix(":/splash.png");
    QSplashScreen splash(pix);
    splash.show();

    // 创建一个定时器，延迟3秒后关闭启动画面


    MainWindow w;
    QTimer::singleShot(3000, &splash, &QSplashScreen::close);
    QTimer::singleShot(3000, &w,&QMainWindow::show );
    //w.show();

    return a.exec();
}
