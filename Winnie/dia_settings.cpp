#include "dia_settings.h"
#include "ui_dia_settings.h"

Dia_settings::Dia_settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dia_settings)
{
    ui->setupUi(this);
    qDebug()<<"---设置窗口启动---\n";
}

Dia_settings::~Dia_settings()
{
    qDebug()<<"---设置窗口已经退出---\n";
    delete ui;

}

void Dia_settings::on_buttonBox_clicked(QAbstractButton *button1)
{
    QString player_str;
    if (button1 == ui->buttonBox->button(QDialogButtonBox::Apply)){
        qDebug()<<"-应用被按下\n";
        player_str=ui->line_edit_player->text();
        //设置错误选项检查
        if (player_str =="")
        {
            qDebug()<<"*玩家输入了空字符串\n";
            QMessageBox::critical(this,"错误","玩家名不能为空!");
            ui->line_edit_player->setText("Player");
        }
        //应用设置
        //Window size
        if (ui->comboBox->currentIndex() == 0)
            emit send_size(1050,700);
        else if (ui->comboBox->currentIndex() ==1)
            emit send_size(800,700);
    }
    else if (button1==ui->buttonBox->button(QDialogButtonBox::Cancel)){
        this->hide();
        qDebug()<<"-退出设置...\n";
    }
}

