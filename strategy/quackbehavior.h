#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <QDebug>

class QuackBehavior
{
public:
    QuackBehavior() {}
    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    void quack() override
    {
        qDebug() << Q_FUNC_INFO << "Quack!";
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override
    {
        qDebug() << Q_FUNC_INFO << "<< Silence >>";
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override
    {
        qDebug() << Q_FUNC_INFO << "Squeak!";
    }
};

#endif // QUACKBEHAVIOR_H
