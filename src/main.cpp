#include <QApplication>
#include "widget.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("QFlappyBird");
    QCoreApplication::setOrganizationName("QFlappyBird");
    QApplication a(argc, argv);
    Widget e;
    e.show();
    return QApplication::exec();
}
