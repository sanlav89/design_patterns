#ifndef DISPLAY_H
#define DISPLAY_H

#include "interfaces.h"
#include "weatherdata.h"
#include <QDebug>

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    CurrentConditionsDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) override
    {
        this->temperature = temperature;
        this->humidity = humidity;
        Q_UNUSED(pressure);
        display();
    }

    void display() const override
    {
        qDebug() << "Current conditions: " << temperature
                 << "F degrees and " << humidity << "% humidity";
    }

private:
    float temperature;
    float humidity;
    Subject *weatherData;

};


class StatisticsDisplay : public Observer, public DisplayElement
{
public:
    StatisticsDisplay(Subject *weatherData) :
        minTemperature(0),
        maxTemperature(0),
        avgTemperature(0),
        numberOfMeasurements(0)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) override
    {
        Q_UNUSED(humidity);
        Q_UNUSED(pressure);
        if (numberOfMeasurements == 0) {
            minTemperature = temperature;
            maxTemperature = temperature;
        } else {
            if (temperature < minTemperature) {
                minTemperature = temperature;
            }
            if (temperature > maxTemperature) {
                maxTemperature = temperature;
            }
        }
        avgTemperature += temperature;
        numberOfMeasurements++;
        display();
    }

    void display() const override
    {
        qDebug() << "Avg/Max/Min temperature = "
                 << avgTemperature / numberOfMeasurements << "/"
                 << maxTemperature << "/"
                 << minTemperature << "/";
    }

private:
    float minTemperature;
    float maxTemperature;
    float avgTemperature;
    int numberOfMeasurements;
    Subject *weatherData;
};



#endif // DISPLAY_H
