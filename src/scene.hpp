#ifndef QFLAPPYBIRD_SCENE_HPP
#define QFLAPPYBIRD_SCENE_HPP

#include "pillaritem.hpp"
#include <QTimer>
#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parent = nullptr);

private:
    // Each second, a pillar appears
    const int DURATION_PILLAR_TIMER = 1000;
    QTimer *pillarTimer;
    void setUpPillarTimer();
};

#endif //QFLAPPYBIRD_SCENE_HPP
