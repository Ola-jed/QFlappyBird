#ifndef QFLAPPYBIRD_PILLARITEM_HPP
#define QFLAPPYBIRD_PILLARITEM_HPP

#include "scene.hpp"
#include "birditem.hpp"
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsItemGroup>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>

class PillarItem: public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)

public:
    explicit PillarItem();
    ~PillarItem();
    qreal x() const;
    void stopPillar();

public slots:
    void setX(qreal x);

private:
    bool isAfterBird = false;
    const int ANIMATION_DURATION = 2500;
    const int X_AXIS_VALUE = 260;
    qreal m_x;
    int yPos;
    bool collisionWithBird() const;
    QGraphicsPixmapItem *topPillar;
    QGraphicsPixmapItem *bottomPillar;
    QPropertyAnimation *xAnimation;
    void buildAnimation();

signals:
    void collidedABird();
};

#endif //QFLAPPYBIRD_PILLARITEM_HPP