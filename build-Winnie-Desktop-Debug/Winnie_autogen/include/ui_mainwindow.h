/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QWidget *centralwidget;
    QFrame *headline;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuWinnie;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 700);
        MainWindow->setMinimumSize(QSize(1100, 700));
        MainWindow->setMaximumSize(QSize(1100, 700));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-page-setup")));
        MainWindow->setWindowIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setCheckable(false);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        action_2->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        headline = new QFrame(centralwidget);
        headline->setObjectName(QString::fromUtf8("headline"));
        headline->setGeometry(QRect(150, 10, 841, 51));
        headline->setFrameShape(QFrame::NoFrame);
        headline->setFrameShadow(QFrame::Raised);
        headline->setLineWidth(0);
        label = new QLabel(headline);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 841, 51));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 27));
        menuWinnie = new QMenu(menubar);
        menuWinnie->setObjectName(QString::fromUtf8("menuWinnie"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuWinnie->menuAction());
        menuWinnie->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Winnie", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "# Welcome to Winnie Cat.", nullptr));
        menuWinnie->setTitle(QCoreApplication::translate("MainWindow", "Winnie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
