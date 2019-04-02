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
  
  /*Start hum device*/
  Wire.write(0xF2);
  Wire.write(B001);

  /*Start t&p device*/
  Wire.write(0xF4);
  Wire.write(B00100111);

  /*Write in Data acquisition direction for hum*/
  Wire.write(0xFD);
  
  /*Write in Data acquisition direction for temp*/
  Wire.write(0xFA);
  
  /*Write in Data acquisition direction for pres*/
  Wire.write(0xF7);
  
      /* Request data from slave with address 0x76 */

  Wire.requestFrom(0x76, 8);

  /* Wait for data to be available */
  while (Wire.available())
  {
  /* Receive the byte */
  uint8_t hum1 = Wire.read();
  uint8_t hum2 = Wire.read();

  uint8_t temp1=Wire.read();
  uint8_t temp2=Wire.read();

  uint8_t pres1=Wire.read();
  uint8_t pres2=Wire.read();
  
  uint16_t hum=hum1;
  uint16_t temp=temp1;
  uint16_t pres=pres1;
  
  hum=hum<<8;
  hum=hum+hum2;

  temp=temp<<8;
  temp=temp+temp2;

  pres=pres<<8;
  pres=pres+pres2;

    /* Send it to console/monitor */
    Serial.printf("Received byte: %02X %02X %02X %u \n", hum1,hum2,hum,hum);
    Serial.printf("Recibido Humedad \n---\n");

    Serial.printf("Received byte: %02X %02X %02X %u \n", temp1,temp2,temp,temp);
    Serial.printf("Recibido Temperatura \n---\n");

    Serial.printf("Received byte: %02X %02X %02X %u \n", pres1,pres2,pres,pres);
    Serial.printf("Recibido Presión \n---\n");
  }
     /*End transmission */

  Wire.endTransmission();

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
  
}
