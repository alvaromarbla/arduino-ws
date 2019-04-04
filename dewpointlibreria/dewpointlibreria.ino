/*
  Calculating dewpoint on the BME280
  Nathan Seidle @ SparkFun Electronics
  November 3rd, 2018
  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14348 - Qwiic Combo Board
  https://www.sparkfun.com/products/13676 - BME280 Breakout Board
  This example shows how to calculate dew point based on humidity and temperature.
  Comes from Pavel-Sayekat: https://github.com/sparkfun/SparkFun_BME280_Breakout_Board/pull/6
  Hardware connections:
  BME280 -> Arduino
  GND -> GND
  3.3 -> 3.3
  SDA -> A4
  SCL -> A5
*/

#include <Wire.h>

#include "SparkFunBME280.h"
BME280 BME280_obj;

void setup()
{
  Serial.begin(115200);
  Serial.printf("Example showing dewpoint calculation");

  BME280_obj.setI2CAddress(0x76); //Connect to a second sensor
  if (BME280_obj.beginI2C() == false) Serial.printf("Sensor connect failed");
}

void loop()
{
  Serial.printf("Humidity: ");
  Serial.printf(BME280_obj.readFloatHumidity(), 0);

  Serial.printf(" Pressure: ");
  Serial.printf(BME280_obj.readFloatPressure(), 0);

  Serial.printf(" Temp: ");
  Serial.printf(BME280_obj.readTempC(), 2);
  //Serial.print(mySensor.readTempF(), 2);

  Serial.printf(" Dewpoint: ");
  Serial.printf(BME280_obj.dewPointC(), 2);
  //Serial.print(mySensor.dewPointF(), 2);

  Serial.printf();

  delay(50);
}
