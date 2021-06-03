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

public slots:
    void startGame();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    // Each second, a pillar appears
    const int DURATION_PILLAR_TIMER = 1000;
    bool inGame;
public:
    [[nodiscard]] bool isInGame() const;
    [[nodiscard]] int getScore() const;
    void setInGame(bool inGame);
    void incrementScore();

private:
    int score = 0;
    QTimer *pillarTimer;
    BirdItem *bird;
    void deletePillars();
    void setUpPillarTimer();
    void stopBirdAndPillars();
};

#endif //QFLAPPYBIRD_SCENE_HPP
