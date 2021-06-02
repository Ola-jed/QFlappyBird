#include "scene.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpPillarTimer();
}

void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer,&QTimer::timeout,[=](){
        auto pillarItem = new PillarItem();
        addItem(pillarItem);
    });
    pillarTimer->start(DURATION_PILLAR_TIMER);
}
