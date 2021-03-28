#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "pizza.h"

class PizzaStore
{
public:
    Pizza orderPizza(QString type)
    {
        Pizza pizza = createPizza(type);
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        return pizza;
    }
    virtual ~PizzaStore() {}

protected:
    virtual Pizza createPizza(QString type) = 0;
};

class NYPizzaStore : public PizzaStore
{
    Pizza createPizza(QString type) override
    {
        if (type == "cheese") {
            return NYStyleCheesePizza();
        } else {
            return Pizza();
        }
    }
};

class ChicagoPizzaStore : public PizzaStore
{
    Pizza createPizza(QString type) override
    {
        if (type == "cheese") {
            return ChicagoStyleCheesePizza();
        } else {
            return Pizza();
        }
    }
};


#endif // PIZZASTORE_H
