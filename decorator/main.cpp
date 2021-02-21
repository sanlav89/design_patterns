#include <QCoreApplication>

#include "decorated.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Beverage *beverage = new Espresso;
    qDebug() << beverage->description() << " $" << beverage->cost();

    Beverage *beverage2 = new DarkRoast;
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    qDebug() << beverage2->description() << " $" << beverage2->cost();

    Beverage *beverage3 = new HouseBlend;
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    qDebug() << beverage3->description() << " $" << beverage3->cost();

    delete beverage;
    delete beverage2;
    delete beverage3;

    return a.exec();
}
