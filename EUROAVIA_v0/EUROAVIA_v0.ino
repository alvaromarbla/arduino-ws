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
}
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
