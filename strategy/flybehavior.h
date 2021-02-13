#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H
#include <QDebug>

class FlyBehavior
{
public:
    FlyBehavior() {}
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() override
    {
        qDebug() << Q_FUNC_INFO << "I'm flying!";
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override
    {
        qDebug() << Q_FUNC_INFO << "I can't fly =(";
    }
};

#endif // FLYBEHAVIOR_H
