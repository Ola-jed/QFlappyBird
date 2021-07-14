#ifndef QFLAPPYBIRD_WIDGET_HPP
#define QFLAPPYBIRD_WIDGET_HPP

#include "scene.hpp"
#include "pillaritem.hpp"
#include <QStyle>
#include <QWidget>
#include <QScreen>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    Scene *scene{};

    void buildScene();

private slots:
    void startGame();
};

#endif //QFLAPPYBIRD_WIDGET_HPP
