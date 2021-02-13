#ifndef DUCK_H
#define DUCK_H

#include "flybehavior.h"
#include "quackbehavior.h"
#include <QDebug>

/*
 * Базовый класс Утки
 */
class Duck
{
public:

    Duck() {}
    virtual ~Duck() {}

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

    /*
     * Динамическое изменение поведения
     */
    void setFlyBehavior(FlyBehavior *fb)
    {
        flyBehavior = fb;
    }

    void setQuackBehavior(QuackBehavior *qb)
    {
        quackBehavior = qb;
    }

protected:
    /*
     * Интерфейсы в C++ - это абстрактные классы.
     * они объявляются указателями
     */
    FlyBehavior *flyBehavior = nullptr;       // Интерфейс "летающие"
    QuackBehavior *quackBehavior = nullptr;   // Интерфейс "квакающие"

};

/*
 * Класс крякающей утки
 */
class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck()
    {
        flyBehavior = new FlyWithWings;
        quackBehavior = new Quack;
    }

    ~MallardDuck()
    {
        delete flyBehavior;
        delete quackBehavior;
    }

    void display() override
    {
        qDebug() << Q_FUNC_INFO << "I'm a real Mallard Duck";
    }
};

/*
 * Утка-примнка
 */
class ModelDuck : public Duck
{
public:
    ModelDuck() : Duck()
    {
        flyBehavior = new FlyNoWay;
        quackBehavior = new Quack;
    }

    ~ModelDuck()
    {
        delete flyBehavior;
        delete quackBehavior;
    }

    void display() override
    {
        qDebug() << Q_FUNC_INFO << "I'm a model Duck";
    }
};


#endif // DUCK_H
