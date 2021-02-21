#ifndef DECORATED_H
#define DECORATED_H

#include "beverage.h"

class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *beverage)
    {
        m_beverage = beverage;
    }

    QString description() const override
    {
        return m_beverage->description() + ", Mocha";
    }

    double cost() const override
    {
        return 0.20 + m_beverage->cost();
    }
};

class Soy : public CondimentDecorator
{
public:
    Soy(Beverage *beverage)
    {
        m_beverage = beverage;
    }

    QString description() const override
    {
        return m_beverage->description() + ", Soy";
    }

    double cost() const override
    {
        return 0.15 + m_beverage->cost();
    }
};

class Whip : public CondimentDecorator
{
public:
    Whip(Beverage *beverage)
    {
        m_beverage = beverage;
    }

    QString description() const override
    {
        return m_beverage->description() + ", Whip";
    }

    double cost() const override
    {
        return 0.1 + m_beverage->cost();
    }
};

#endif // DECORATED_H
