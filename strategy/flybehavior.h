#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H
#include <QDebug>

/*
 * Абстрактный класс интерфейса "летающие"
 */
class FlyBehavior
{
public:
    virtual ~FlyBehavior() {}  // В классах интерфейса (абстрактных) необходимо объявить виртуальный деструктор
    virtual void fly() const = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() const override
    {
        qDebug() << Q_FUNC_INFO << "I'm flying!";
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() const override
    {
        qDebug() << Q_FUNC_INFO << "I can't fly =(";
    }
};

#endif // FLYBEHAVIOR_H
