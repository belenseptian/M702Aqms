/*
 * M702 sensor library made by Belen Septian 
 * This library can be used to read the data from M702B air quality sensor
 * As of now it supports on ESP32 only
 * Please do not remove this copyright
*/
#include <M702.h>

M702 M702(16,17); //Rx and Tx pins of your microcontroller respectively

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  M702.begin(); //this should be initialized on setup
}

void loop() {
  // put your main code here, to run repeatedly:
  M702.readAll(); //this should be initialized to read the data from sensors
  Serial.println("-------------");
  Serial.println(M702.getCO2());
  Serial.println(M702.getCH20());
  Serial.println(M702.getTVOC());
  Serial.println(M702.getPM2_5());
  Serial.println(M702.getPM10());
  Serial.println(M702.getTemperature());
  Serial.println(M702.getHumidity());
  Serial.println("-------------");
}
