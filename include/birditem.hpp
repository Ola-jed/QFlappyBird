#ifndef QFLAPPYBIRD_BIRDITEM_HPP
#define QFLAPPYBIRD_BIRDITEM_HPP

#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>

class BirdItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)

public:
    explicit BirdItem(const QPixmap &pixmap);
    qreal rotation() const;
    qreal y() const;
    void flyUp();
    void startFlying();
    void stopFlying();

public slots:
    void setRotation(qreal rotation);
    void setY(qreal y);
    void rotateTo(const qreal &end,const int &duration,const QEasingCurve &easingCurve);
    void fall();

private:
    qreal m_y;
    qreal m_rotation;
    enum WingPosition{
        Up,Mid,Down
    };
    void updatePixmap();
    void buildAnimations();
    WingPosition wingPosition;
    bool wingDirectionIsUp;
    static constexpr int BIRD_WINGS_UPDATE_DURATION = 80;
    static constexpr int GROUND_POSITION = 230;
    qreal groundPosition;
    QPropertyAnimation *yAnimation;
    QPropertyAnimation *rotationAnimation;
};

#endif //QFLAPPYBIRD_BIRDITEM_HPP
