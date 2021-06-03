#include "pillaritem.hpp"

PillarItem::PillarItem():
    topPillar(new QGraphicsPixmapItem(QPixmap(":assets/pillar-reversed.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":assets/pillar.png")))
{
    topPillar->setPos(QPointF{0,0} -
        QPointF{topPillar->boundingRect().width() / 2,topPillar->boundingRect().height() + 60});
    bottomPillar->setPos(QPointF{0,0} +
        QPointF{-bottomPillar->boundingRect().width() / 2,60});
    addToGroup(topPillar);
    addToGroup(bottomPillar);
    buildAnimation();
}

void PillarItem::buildAnimation()
{
    // Defining random values for the position of the pillar item
    yPos = QRandomGenerator::global()->bounded(150);
    auto const xRandom = QRandomGenerator::global()->bounded(200);
    setPos(QPoint{0,0} + QPoint{X_AXIS_VALUE + xRandom,yPos});
    // Animation for x axis for the pillar item
    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(X_AXIS_VALUE + xRandom);
    xAnimation->setEndValue(-X_AXIS_VALUE);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(ANIMATION_DURATION);
    // Destroy the pillar item when it's go out the view
    connect(xAnimation,&QPropertyAnimation::finished,[this](){
        scene()->removeItem(this);
        delete this;
    });
    xAnimation->start();
}

qreal PillarItem::x() const
{
    return m_x;
}

void PillarItem::setX(qreal x)
{
    m_x = x;
    setPos(QPoint{0,0} + QPointF{x,static_cast<qreal>(yPos)});
}

PillarItem::~PillarItem()
= default;
