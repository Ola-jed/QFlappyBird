// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "widget.hpp"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->startGameButton,&QPushButton::clicked,this,&Widget::startGame);
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),QGuiApplication::primaryScreen()->availableGeometry()));
    buildScene();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buildScene()
{
    scene = new Scene(this);
    scene->setSceneRect(-250,-300,500,600);
    auto pixItem = new QGraphicsPixmapItem(QPixmap{":/assets/background-night.png"});
    scene->addItem(pixItem);
    pixItem->setPos(QPointF{0,0} -
        QPointF{pixItem->boundingRect().width()/2,pixItem->boundingRect().height() / 2});
    ui->graphicsView->setScene(scene);
    scene->addBird();
}

void Widget::startGame()
{
    scene->startGame();
}
