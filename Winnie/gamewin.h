#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QMainWindow>

namespace Ui {
class GameWin;
}

class GameWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWin(QWidget *parent = nullptr);
    ~GameWin();

private:
    Ui::GameWin *ui;
};

#endif // GAMEWIN_H
