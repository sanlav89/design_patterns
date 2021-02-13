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

/*
 * Умеет летать
 */
class FlyWithWings : public FlyBehavior
{
public:
    void fly() const override
    {
        qDebug() << Q_FUNC_INFO << "I'm flying!";
    }
};

/*
 * Не умеет летать
 */
class FlyNoWay : public FlyBehavior
{
public:
    void fly() const override
    {
        qDebug() << Q_FUNC_INFO << "I can't fly =(";
    }
};

/*
 * Реактивный полет
 */
class FlyRockedPowered : public FlyBehavior
{
public:
    void fly() const override
    {
        qDebug() << Q_FUNC_INFO << "I'm flying with a rocket";
    }
};

#endif // FLYBEHAVIOR_H
