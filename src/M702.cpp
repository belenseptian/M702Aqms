/*
 * M702 sensor library made by Belen Septian 
 * This library can be used to read the data from M702B air quality sensor
 * As of now it supports on ESP32 only
 * Please do not remove this copyright
*/
#include "Arduino.h"
#include "M702.h"

M702::M702(int _pin_rx, int _pin_tx)
{
    pin_rx = _pin_rx;
    pin_tx = _pin_tx;
}

void M702::begin()
{
    #if defined (ESP32)
        Serial2.begin(9600, SERIAL_8N1, pin_rx, pin_tx); //Hardware Serial 2 of ESP32
    #endif
}

void M702::readAll()
{
    while (Serial2.available()) 
    {
        delay(2);
        byte read_incoming = Serial2.read();
        read_all += read_incoming;
        if(store_index <= 16)
        {
            store_all[store_index] = read_incoming;
            store_index++;
        }
    }
    if(!read_all.equals("") && store_index == 17)
    {
        store = true;
    }
    else
    {
        store = false;
    }
    delay(2);
    read_all = "";
    store_index = 0;
}

int M702::getCO2()
{
    if(store == true)
    {
        co2 = (store_all[2]*256)+store_all[3];
        return (store_all[2]*256)+store_all[3];
    }
    else
    {
        return co2;       
    }
}

int M702::getCH20()
{
    if(store == true)
    {
        ch20 = (store_all[4]*256)+store_all[5];
        return (store_all[4]*256)+store_all[5];
    }
    else
    {
        return ch20;       
    }
}

int M702::getTVOC()
{
    if(store == true)
    {
        tvoc = (store_all[6]*256)+store_all[7];
        return (store_all[6]*256)+store_all[7];
    }
    else
    {
        return tvoc;       
    }
}

int M702::getPM2_5()
{
    if(store == true)
    {
        pm2_5 = (store_all[8]*256)+store_all[9];
        return (store_all[8]*256)+store_all[9];
    }
    else
    {
        return pm2_5;       
    }
}

int M702::getPM10()
{
    if(store == true)
    {
        pm10 = (store_all[10]*256)+store_all[11];
        return (store_all[10]*256)+store_all[11];
    }
    else
    {
        return pm10;       
    }
}

float M702::getTemperature()
{
    if(store == true)
    {
        String integer_part = String(store_all[12]);
        String decimal_part = String(store_all[13]);
        String combination = integer_part+decimal_part;
        temp = combination.toFloat()/10;
        return combination.toFloat()/10;
    }
    else
    {
        return temp;       
    }
}

float M702::getHumidity()
{
    if(store == true)
    {
        String integer_part = String(store_all[14]);
        String decimal_part = String(store_all[15]);
        String combination = integer_part+decimal_part;
        humidity = combination.toFloat()/10;
        return combination.toFloat()/10;
    }
    else
    {
        return humidity;       
    }
}