#include <QCoreApplication>

#include "pizzastore.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PizzaStore *nyStore = new NYPizzaStore;
    PizzaStore *chicagoStore = new ChicagoPizzaStore;

    Pizza pizza = nyStore->orderPizza("cheese");
    qDebug() << "Ethan ordered a " << pizza.name() << endl;
    pizza = chicagoStore->orderPizza("cheese");
    qDebug() << "Joel ordered a " << pizza.name() << endl;

    delete chicagoStore;
    delete nyStore;

    return a.exec();
}
