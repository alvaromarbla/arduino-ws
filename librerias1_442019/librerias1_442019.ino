/* Include required headers and/or libraries */
#include <Wire.h>
#include "SparkFunBME280.h"

#define SLAVE_ADDRESS 0x76

/* Instantiate a BME280 object called BME280_obj */
BME280 BME280_obj;

/*
 * Single-pass function to configure the app
 */
void setup()
{
  /* Start serial for output */
  Serial.begin(115200);

  /* Join I2C bus and set it to 400 kHz */
  Wire.begin(0, 2);
  Wire.setClock(400000);

  /* Address the sensor */
  BME280_obj.setI2CAddress(SLAVE_ADDRESS);

  /* Check communication before continue */
  if (BME280_obj.beginI2C(Wire) == false)
  {
    Serial.printf("The sensor did not respond. Please check wiring.\n");

    /* Stop here (WDT will reset at some point) */
    while(1);
  }
}

/*
 * Recurrent task, called forever
 */
void loop()
{
  /* Welcome message! Useful as a control point */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");

   //Serial.printf("Humidity: ");
  Serial.printf("Humidity=%2.1f %%" ,BME280_obj.readFloatHumidity(), 0);

  //Serial.printf(" Pressure: ");
  Serial.printf("  Pressure=%6.0f Pa" ,BME280_obj.readFloatPressure(), 0);

  //Serial.printf(" Alt: ");
  Serial.printf("    Altittude= %5.1f met", BME280_obj.readFloatAltitudeMeters(), 1);
  //Serial.print(BME280_obj.readFloatAltitudeFeet(), 1);

  //Serial.printf(" Temp: ");
  Serial.printf("    Temperature= %4.2f ºC" ,BME280_obj.readTempC(), 2);
  //Serial.print(BME280_obj.readTempF(), 2);

  Serial.printf("\n");

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
}
