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
  /* Filter coefficient.          | 0 to 4 is valid.   | See 3.4.4     */
  BME280_obj.setFilter(2);
  /* Time between readings.       | 0 to 7 valid.      | See table 27. */
  BME280_obj.setStandbyTime(1);
  /* 0 disables temp sensing.     | 0 to 16 are valid. | See table 24. */
  BME280_obj.setTempOverSample(2);
  /* 0 disables pressure sensing. | 0 to 16 are valid. | See table 23. */
  BME280_obj.setPressureOverSample(16);
  /* 0 disables humidity sensing. | 0 to 16 are valid. | See table 19. */
  BME280_obj.setHumidityOverSample(1);
  /* MODE_SLEEP, MODE_FORCED, MODE_NORMAL is valid.    | See 3.3       */
  BME280_obj.setMode(MODE_NORMAL);
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
