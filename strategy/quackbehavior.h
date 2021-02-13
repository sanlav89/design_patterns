#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <QDebug>

/*
 * Абстрактный класс интерфейса "квакающие"
 */
class QuackBehavior
{
public:
    virtual ~QuackBehavior() {}
    virtual void quack() const = 0;
};

class Quack : public QuackBehavior
{
public:
    void quack() const override
    {
        qDebug() << Q_FUNC_INFO << "Quack!";
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() const override
    {
        qDebug() << Q_FUNC_INFO << "<< Silence >>";
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() const override
    {
        qDebug() << Q_FUNC_INFO << "Squeak!";
    }
};

#endif // QUACKBEHAVIOR_H
