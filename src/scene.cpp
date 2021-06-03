#include "scene.hpp"

Scene::Scene(QObject *parent) : QGraphicsScene(parent),inGame(false)
{
    setUpPillarTimer();
}

// The game starts and the items begin to move
void Scene::startGame()
{
    bird->startFlying();
    if(!pillarTimer->isActive())
    {
        deletePillars();
        inGame = true;
        pillarTimer->start(DURATION_PILLAR_TIMER);
    }
}

void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer,&QTimer::timeout,[this](){
        auto pillarItem = new PillarItem();
        // In case of collision
        connect(pillarItem,&PillarItem::collidedABird,[this](){
            pillarTimer->stop();
            stopBirdAndPillars();
            inGame = false;
        });
        addItem(pillarItem);
    });
}

void Scene::addBird()
{
    bird = new BirdItem(QPixmap{":assets/bird-upflap.png"});
    addItem(bird);
}

// Handle key press and mouse press event for the bird
void Scene::keyPressEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key::Key_Space) && inGame)
    {
        bird->flyUp();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && inGame)
    {
        bird->flyUp();
    }
    QGraphicsScene::mousePressEvent(event);
}

void Scene::stopBirdAndPillars()
{
    bird->stopFlying();
    // Stop all the pillars of the scene
    auto sceneItems = items();
    foreach(auto item,sceneItems)
    {
        auto tempPillarItem = dynamic_cast<PillarItem*>(item);
        if(tempPillarItem)
        {
            tempPillarItem->stopPillar();
        }
    }
}

bool Scene::isInGame() const
{
    return inGame;
}

void Scene::setInGame(bool isInGame)
{
    inGame = isInGame;
}

void Scene::deletePillars()
{
    auto sceneItems = items();
    foreach(auto item,sceneItems)
    {
        auto tempPillarItem = dynamic_cast<PillarItem*>(item);
        if(tempPillarItem)
        {
            removeItem(tempPillarItem);
            delete tempPillarItem;
        }
    }
}

void Scene::incrementScore()
{
    score++;
    qDebug() << score;
}

int Scene::getScore() const
{
    return score;
}
