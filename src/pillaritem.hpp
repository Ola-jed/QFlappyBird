#ifndef QFLAPPYBIRD_PILLARITEM_HPP
#define QFLAPPYBIRD_PILLARITEM_HPP

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

public slots:
    void setX(qreal x);

private:
    const int ANIMATION_DURATION = 1500;
    const int X_AXIS_VALUE = 260;
    qreal m_x;
    int yPos;

    QGraphicsPixmapItem *topPillar;
    QGraphicsPixmapItem *bottomPillar;
    QPropertyAnimation *xAnimation;

    void buildAnimation();
};

#endif //QFLAPPYBIRD_PILLARITEM_HPP