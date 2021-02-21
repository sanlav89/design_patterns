#ifndef PIZZA_H
#define PIZZA_H

#include <QStringList>
#include <QDebug>

class Pizza
{
public:

    virtual void prepare()
    {
        qDebug() << "Preparing" << m_name;
        qDebug() << "Tossing dough...";
        qDebug() << "Adding sause...";
        qDebug() << "Add toppings: ";
        for (QString topping : m_toppings) {
            qDebug() << "    " << topping;
        }
    }

    virtual void bake()
    {
        qDebug() << "Bake for 25 minutes at 350";
    }

    virtual void cut()
    {
        qDebug() << "Cutting the pizza into diagonal slices";
    }

    virtual void box()
    {
        qDebug() << "Place pizza in official PizzaStore box";
    }

    QString name() const
    {
        return m_name;
    }

protected:
    QString m_name;
    QString m_dough;
    QString m_sause;
    QStringList m_toppings;
};

class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza()
    {
        m_name = "NY Style Sause and Cheese Pizza";
        m_dough = "Thin Crust Dough";
        m_sause = "Marinara Sause";
        m_toppings.append("Grated Reggiano Cheese");
    }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza()
    {
        m_name = "Chicago Style Deep Dish Cheese Pizza";
        m_dough = "Extra Tick Crust Dough";
        m_sause = "Plum Tomato Sause";
        m_toppings.append("Shredded Mozarella Cheese");
    }

    void cut() override
    {
        qDebug() << "Cutting the pizza into square slices";
    }
};

#endif // PIZZA_H
