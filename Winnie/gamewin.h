#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>
#include <QGraphicsRectItem>

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
private slots:
    //void on_mouseMoved(QPointF point);

};

class Scene: public QGraphicsScene{
    Q_OBJECT
protected:
    void mouseMove(QGraphicsSceneMouseEvent *event);
public:
    Scene(QWidget *parent = 0);
signals:
    void mouseMoved(QPointF point);
};



#endif // GAMEWIN_H
