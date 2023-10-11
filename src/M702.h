/*
 * M702 sensor library made by Belen Septian 
 * This library can be used to read the data from M702B air quality sensor
 * As of now it supports on ESP32 only
 * Please do not remove this copyright
*/
#ifndef M702_H
#define M702_H

#include <Arduino.h>

class M702
{
  public:
    M702(int _pin_rx, int _pin_tx);
    void begin();
    void readAll();
    int getCO2();
    int getCH20();
    int getTVOC();
    int getPM2_5();
    int getPM10();
    float getTemperature();
    float getHumidity();
  private:
    int pin_rx, pin_tx, co2, ch20, tvoc, pm2_5, pm10;
    String read_all;
    int store_index = 0;
    byte store_all[17];
    bool store = false;
    float temp, humidity;
};

#endif