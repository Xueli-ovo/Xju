#include "gamewin.h"
#include "ui_gamewin.h"

GameWin::GameWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWin)
{
    ui->setupUi(this);
    qDebug() <<"游戏开始\n";
    Scene s;
    qDebug() <<"场景创建\n";

    QGraphicsView view(&s);
    view.setScene(&s);
    view.setFixedSize(1440, 1080);
    view.show();
}

GameWin::~GameWin()
{
    qDebug() <<"游戏结束\n";
    delete ui;
}

Scene::Scene(QWidget *parent){
    setSceneRect(0, 0, 1440, 1080);
    setBackgroundBrush(Qt::white);
}

void Scene::mouseMove(QGraphicsSceneMouseEvent *event){
    emit mouseMoved(event->scenePos());
    QGraphicsRectItem *square = new QGraphicsRectItem(0, 0, 50, 50);
    square->setPos(event->scenePos());
    square->setBrush(Qt::blue);
    square->setFlag(QGraphicsItem::ItemIsMovable);
    addItem(square);
}
