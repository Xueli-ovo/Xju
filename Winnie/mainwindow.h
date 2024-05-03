#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
    Dia_settings *setting =new Dia_settings(this);
};
#endif // MAINWINDOW_H
