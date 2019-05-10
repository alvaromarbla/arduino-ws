#include  <Wire.h>
#include "SparkFunBME280.h"
#define SLAVE_ADDRESS 0x76

/* Instantiate a BME280 object called BME280_obj */
BME280 BME280_obj;


void setup() {

 /* Start serial for output */
  Serial.begin(115200);
  
    /* join i2c bus (address optional for master)*/
  Wire.begin(0, 2); //SDA and SCL//
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
 /* -- Configure the sensor --
   *  - Read  the  datasheet -
   */
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

void loop() {
   /* Welcome message! Useful as a control point */
  Serial.printf("Ahoy! ESP8266 here!\n"
                "---\n");
   /* Read and print sensor data */
  Serial.printf(" - Temp.: %2.2f [C]\n",  BME280_obj.readTempC());
  Serial.printf(" - Hum..: %2.2f [%%]\n", BME280_obj.readFloatHumidity());
  Serial.printf(" - Pres.: %2.2f [Pa]\n", BME280_obj.readFloatPressure());
  Serial.printf(" - Alt..: %2.2f [m]\n",  BME280_obj.readFloatAltitudeMeters());

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
}
