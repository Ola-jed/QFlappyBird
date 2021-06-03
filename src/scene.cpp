#include "scene.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpPillarTimer();
}

void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer,&QTimer::timeout,[this](){
        auto pillarItem = new PillarItem();
        addItem(pillarItem);
    });
    pillarTimer->start(DURATION_PILLAR_TIMER);
}

void Scene::addBird()
{
    bird = new BirdItem(QPixmap{":assets/bird-upflap.png"});
    addItem(bird);
}

// Handle key press and mouse press event for the bird
void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key::Key_Space)
    {
        bird->flyUp();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        bird->flyUp();
    }
    QGraphicsScene::mousePressEvent(event);
}