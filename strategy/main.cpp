#include <QCoreApplication>

#include "duck.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Duck *mallard = new MallardDuck;
    mallard->performQuack();
    mallard->performFly();

    Duck *model = new ModelDuck;
    model->performFly();
    model->setFlyBehavior(new FlyRockedPowered);
    model->performFly();

    delete mallard;
    delete model;

    return a.exec();
}
