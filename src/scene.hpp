#ifndef QFLAPPYBIRD_SCENE_HPP
#define QFLAPPYBIRD_SCENE_HPP

#include "birditem.hpp"
#include "pillaritem.hpp"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parent = nullptr);
    void addBird();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    // Each second, a pillar appears
    const int DURATION_PILLAR_TIMER = 1000;
    QTimer *pillarTimer;
    BirdItem *bird;
    void setUpPillarTimer();
};

#endif //QFLAPPYBIRD_SCENE_HPP
