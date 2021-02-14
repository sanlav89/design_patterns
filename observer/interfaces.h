#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObject>

class Observer : public QObject
{
    Q_OBJECT
public:
    virtual ~Observer() {}
public slots:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class DisplayElement
{
public:
    virtual ~DisplayElement() {}
    virtual void display() const = 0;
};

class Subject : public QObject
{
    Q_OBJECT
public:
    virtual ~Subject() {};
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObservers() = 0;

signals:
    void valuesChanged(float, float, float);
};

#endif // INTERFACES_H
