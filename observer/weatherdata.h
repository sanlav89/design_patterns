#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "interfaces.h"
#include <QList>

class WeatherData : public Subject
{
public:
    WeatherData() :
        Subject(),
        observers(QList<Observer *>()),
        temperature(0),
        humidity(0),
        pressure(0)
    {
    }

    void registerObserver(Observer *o) override
    {
        observers.append(o);
    }

    void removeObserver(Observer *o) override
    {
        int i = observers.indexOf(o);
        if (i >= 0) {
            observers.removeAt(i);
        }
    }

    void notifyObservers() override
    {
        for (int i = 0; i < observers.size(); i++) {
            observers[i]->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

    // Другие методы WeatherData

private:
    QList<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;
};

#endif // WEATHERDATA_H
