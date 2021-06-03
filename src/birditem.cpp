#include "birditem.hpp"

BirdItem::BirdItem(const QPixmap &pixmap)
        :wingPosition(WingPosition::Up),wingDirectionIsUp(false)
{
    setPixmap(pixmap);
    auto birdWingsDirectionTimer = new QTimer(this);
    connect(birdWingsDirectionTimer,&QTimer::timeout,[this](){
        updatePixmap();
    });
    birdWingsDirectionTimer->start(BIRD_WINGS_UPDATE_DURATION);
    groundPosition = scenePos().y() + GROUND_POSITION;
    buildAnimations();
}

void BirdItem::updatePixmap()
{
    switch (wingPosition)
    {
        case WingPosition::Mid:
            // Updating the pixmap depending on the direction
            setPixmap(QPixmap{wingDirectionIsUp
                ? ":assets/bird-upflap.png" : ":assets/bird-downflap.png"});
            wingPosition = wingDirectionIsUp ? WingPosition::Up : WingPosition::Down;
            wingDirectionIsUp = !wingDirectionIsUp;
            break;
        case WingPosition::Up:
        case WingPosition::Down:
            setPixmap(QPixmap{":assets/bird-midflap.png"});
            wingPosition = WingPosition::Mid;
    }
}

qreal BirdItem::rotation() const
{
    return m_rotation;
}

qreal BirdItem::y() const
{
    return m_y;
}

void BirdItem::setRotation(qreal rotation)
{
    m_rotation = rotation;
    const auto point = boundingRect().center();
    QTransform transformRotation;
    transformRotation.translate(point.x(),point.y());
    transformRotation.rotate(rotation);
    transformRotation.translate(-point.x(),-point.y());
    setTransform(transformRotation);
}

void BirdItem::setY(qreal y)
{
    moveBy(0,y - m_y);
    m_y = y;
}

void BirdItem::buildAnimations()
{
    // Building our animation for the y axis
    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    yAnimation->start();
    // Rotation animation
    rotationAnimation = new QPropertyAnimation(this,"rotation",this);
    rotateTo(90,1200,QEasingCurve::InQuad);
}

void BirdItem::rotateTo(const qreal &end,const int &duration,const QEasingCurve &easingCurve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(easingCurve);
    rotationAnimation->setDuration(duration);
    rotationAnimation->start();
}

void BirdItem::flyUp()
{
    yAnimation->stop();
    rotationAnimation->stop();
    const qreal currentY = y();
    yAnimation->setStartValue(currentY);
    yAnimation->setEndValue(currentY - scene()->sceneRect().height() / 8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    connect(yAnimation,&QPropertyAnimation::finished,[this](){
        fall();
    });
    yAnimation->start();
    rotateTo(-20,200,QEasingCurve::OutCubic);
}

void BirdItem::fall()
{
    if(y() < GROUND_POSITION)
    {
        rotationAnimation->stop();
        yAnimation->stop();
        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(GROUND_POSITION);
        yAnimation->setDuration(500);
        yAnimation->start();
        rotateTo(90,1200,QEasingCurve::InCubic);
    }
}
