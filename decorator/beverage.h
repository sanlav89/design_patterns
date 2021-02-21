#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <QString>

class Beverage
{
public:
    virtual ~Beverage() {}

    virtual QString description() const
    {
        return m_description;
    }
    virtual double cost() const = 0;

protected:
    QString m_description = "Uncknown Beverage";

};

class CondimentDecorator : public Beverage
{
public:
    virtual QString description() const = 0;

protected:
    Beverage *m_beverage;
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        m_description = "Espresso";
    }

    double cost() const override
    {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        m_description = "House Blend Coffee";
    }

    double cost() const override
    {
        return .89;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        m_description = "Dark Roast Coffee";
    }

    double cost() const override
    {
        return .99;
    }
};

class Decaf : public Beverage
{
public:
    Decaf()
    {
        m_description = "Decaffeinated Coffee";
    }

    double cost() const override
    {
        return 1.05;
    }
};

#endif // BEVERAGE_H
