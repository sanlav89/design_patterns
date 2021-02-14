#include <QCoreApplication>

#include "weatherdata.h"
#include "display.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WeatherData *weatherData = new WeatherData;
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay *statisticsDisplay = new StatisticsDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->setMeasurements(78, 90, 29.2f);

    delete statisticsDisplay;
    delete currentDisplay;
    delete weatherData;

    return a.exec();
}
