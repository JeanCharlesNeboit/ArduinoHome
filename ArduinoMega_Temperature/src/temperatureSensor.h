#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <DHT.h>
#include <DHT_U.h>
#include "sensor.h"

class TemperatureSensor: public Sensor, public DHT {
    private:

    public:
      TemperatureSensor();
      virtual ~TemperatureSensor();

      float measureTemperature(bool isFahrenheit);
      float measureHumidity();
      float measureHeatIndex(bool isFahrenheit);
};

#endif
