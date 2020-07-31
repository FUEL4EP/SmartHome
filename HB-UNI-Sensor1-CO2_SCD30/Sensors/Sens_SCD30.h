
//---------------------------------------------------------
// Sens_SCD30
// 2019-07-14 Tom Major (Creative Commons)
// https://creativecommons.org/licenses/by-nc-sa/4.0/
// You are free to Share & Adapt under the following terms:
// Give Credit, NonCommercial, ShareAlike
// +++
// AskSin++ 2016-10-31 papa Creative Commons
//---------------------------------------------------------

#ifndef _SENS_SCD30_H_
#define _SENS_SCD30_H_


#include "my_Sensors_SCD30.h"
#include <Wire.h>
#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30



namespace as {

class Sens_SCD30 : public Sensor {

    int16_t  _temperature;
    uint32_t _carbondioxide;
    uint8_t  _humidity;
    SCD30    airSensor;

    void measureRaw()
    {
        DPRINTLN("");
        while (!airSensor.dataAvailable())
        {
            delay(1000);
            DPRINT(".");
            if (airSensor.dataAvailable())
            {    
              break;
            }
        }
        if (airSensor.dataAvailable())
        {    
              _temperature      = (int16_t)(airSensor.getTemperature() * 10);                                             
              _carbondioxide    = (uint32_t)(floor(airSensor.getCO2() * 100.0 +0.5));                                             
              _humidity         = (uint8_t)(airSensor.getHumidity());
              DPRINTLN("");
        }
    }

public:
    Sens_SCD30()
        : _temperature(0)
        , _carbondioxide(0)
        , _humidity(0)
    {
    }

    void init(uint16_t height, uint16_t ambient_pressure, uint16_t temperature_correction, uint16_t update_intervall)
    {
        Wire.begin();
        
        delay(200);
        
        if (airSensor.begin() == false)
        {
          DPRINTLN("Error: no Sensirion SCD30 CO2 sensor found");
          DPRINTLN("Please check wiring. Freezing...");
          while (1);
        }
        else
        {
          DPRINTLN(F("SCD30 found"));
          _present = true;
      
          airSensor.setMeasurementInterval(update_intervall/4); // Change number of seconds between measurements: 2 to 1800 (30 minutes)
                                                                // update_intervall = 240 sec; SCD30 measurement intervall: 60 sec to allow SCD30 internal
                                                                // hardware oversampling

          airSensor.setAltitudeCompensation(height);            // Set altitude of the sensor in m
       
          airSensor.setAmbientPressure(ambient_pressure);       // Current ambient pressure in mBar: 700 to 1200
          
          airSensor.setAutoSelfCalibration(true);               // enable autocalibration
          
          float offset = airSensor.getTemperatureOffset();
          DPRINT("Current temp offset: ");
          DPRINT(offset);
          DPRINTLN(" deg C");

          airSensor.setTemperatureOffset((float)temperature_correction/10.0); //Optionally we can set temperature offset to 5°C
          DPRINT("New temp offset: ");
          DPRINT((float)temperature_correction/10.0);
          DPRINTLN(" deg C");
        }
    }

    void measure()
    {
        _temperature = _carbondioxide = _humidity = 0;
        if (_present == true) {
            measureRaw();
            DPRINT(F("SCD30 Temperature x10  : "));
            DDECLN(_temperature);
            DPRINT(F("SCD30 Carbondioxide x100     : "));
            DDECLN(_carbondioxide);
            DPRINT(F("SCD30 Humidity         : "));
            DDECLN(_humidity);
        }
    }

    int16_t  temperature() { return _temperature; }
    uint32_t carbondioxide() { return _carbondioxide; }
    uint8_t  humidity() { return _humidity; }
};

}

#endif
