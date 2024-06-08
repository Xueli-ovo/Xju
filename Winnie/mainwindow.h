#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QPlainTextEdit>

#include "dia_settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_action_2_triggered();

    void on_actionWinniesettings_triggered();

    void on_button_settings_clicked();

    void change_size(int x,int y);

    void on_action_cbk_triggered();

    void on_action_release_triggered();

    void on_button_start_clicked();

private:
    Ui::MainWindow *ui;
    Dia_settings *setting =new Dia_settings(this);
};


class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setFixedSize(800, 600);

        plainTextEdit = new QPlainTextEdit(this);
        plainTextEdit->setReadOnly(false);
        plainTextEdit->setFixedSize(800, 600);

        QFile file(":/RELEASE");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"打开了文件.\n";
            QTextStream in(&file);
            plainTextEdit->setPlainText(in.readAll());
            file.close();
            plainTextEdit->setReadOnly(true);
        }
    }

private:
    QPlainTextEdit *plainTextEdit;
};
#endif // MAINWINDOW_H
