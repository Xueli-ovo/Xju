#ifndef DIA_SETTINGS_H
#define DIA_SETTINGS_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class Dia_settings;
}

class Dia_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Dia_settings(QWidget *parent = nullptr);
    ~Dia_settings();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_comboBox_gamemode_currentIndexChanged(int index);

signals:
    void send_size(int x,int y);

private:
    Ui::Dia_settings *ui;
};

#endif // DIA_SETTINGS_H
