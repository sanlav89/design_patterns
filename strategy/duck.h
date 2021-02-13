#ifndef DUCK_H
#define DUCK_H

#include "flybehavior.h"
#include "quackbehavior.h"
#include <QDebug>

class Duck
{
public:

    /*
     * Интерфейсы в C++ - это абстрактные классы.
     * они объявляются указателями
     */
    FlyBehavior *flyBehavior;       // Интерфейс "летающие"
    QuackBehavior *quackBehavior;   // Интерфейс "квакающие"

    Duck() {}

    /*
     * Метод, который будет иметь разную реализацию, но будет точно у всех
     * субклассов
     */
    virtual void display() = 0;

    /*
     * Делегирование операций классам поведения
     */
    void performFly()
    {
        flyBehavior->fly();
    }
    void performQuack()
    {
        quackBehavior->quack();
    }

    /*
     * В отличие от display(), этот метод одинаков для всех объектов,
     * унаследованных от Duck
     */
    void swim()
    {
        qDebug() << Q_FUNC_INFO << "All ducks float, even decoys!";
    }

};

class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck()
    {
        flyBehavior = new FlyWithWings;
        quackBehavior = new Quack;
    }

    void display() override
    {
        qDebug() << Q_FUNC_INFO << "I'm a real Mallard Duck";
    }
};

#endif // DUCK_H
