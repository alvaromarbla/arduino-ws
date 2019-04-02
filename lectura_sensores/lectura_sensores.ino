/* Include required headers and/or libraries */
#include <Wire.h>

/* Single-pass function to configure the app */
void setup()
{
  /* Join i2c bus (address optional for master) */
  Wire.begin(0, 2);

  /* start serial for output */
  Serial.begin(115200);
}

/* Recurrent task, called forever */
void loop()
{
  /* Welcome message! Useful to know where  */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");
  
  /*Begin transmission*/
  Wire.beginTransmission(0x76);

  Wire.write(0xF2);
  Wire.write(B001);

  /*Write chipID register*/
  Wire.write(0xF4);
  Wire.write(B00100111);


    Wire.write(0xFD);

      /* Request data from slave with address 0x76 */

  Wire.requestFrom(0x76, 2);

  /* Wait for data to be available */
  while (Wire.available())
  {
  /* Receive the byte */
  uint8_t hum1 = Wire.read();
  uint8_t hum2 = Wire.read();

  uint16_t humtot=hum1;
  humtot=humtot<<8;
  humtot=humtot+hum2;

    /* Send it to console/monitor */
    Serial.printf("Received byte: %02X %02X \n", hum1,hum2);
  }
     /*End transmission */

  Wire.endTransmission();

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
  
}
