#include <QCoreApplication>

#include "duck.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Duck *mallard = new MallardDuck;
    mallard->performQuack();
    mallard->performFly();

    return a.exec();
}
