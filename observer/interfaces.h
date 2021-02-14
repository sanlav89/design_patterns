#ifndef INTERFACES_H
#define INTERFACES_H

class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class DisplayElement
{
public:
    virtual ~DisplayElement() {}
    virtual void display() const = 0;
};

class Subject
{
public:
    virtual ~Subject() {};
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObservers();
};

#endif // INTERFACES_H
