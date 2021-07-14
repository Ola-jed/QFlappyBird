#include <QApplication>
#include "widget.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("QFlappyBird");
    QCoreApplication::setOrganizationName("QFlappyBird");
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    Widget e;
    e.show();
    return QApplication::exec();
}
