#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "interfaces.h"
#include <QList>

class WeatherData : public Subject
{
    Q_OBJECT
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
        connect(this, &Subject::valuesChanged, o, &Observer::update);
        observers.append(o);
    }

    void removeObserver(Observer *o) override
    {
        int i = observers.indexOf(o);
        if (i >= 0) {
            disconnect(this, &Subject::valuesChanged, o, &Observer::update);
            observers.removeAt(i);
        }
    }

    void notifyObservers() override
    {
        if (changed) {
            emit valuesChanged(temperature, humidity, pressure);
            changed = false;
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        static bool first = false; // Пропуск оповещения при появлении первого показания
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        if (first) {
            setChanged();
        }
        measurementsChanged();
        first = true;
    }

    // Другие методы WeatherData

private:
    QList<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;
};

#endif // WEATHERDATA_H
