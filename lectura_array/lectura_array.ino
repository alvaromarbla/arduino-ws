/* Include required headers and/or libraries */
#include <Wire.h>

/* Single-pass function to configure the app */
void setup()
{
  /* Join i2c bus (address optional for master) */
  Wire.begin(0, 2);

  /* start serial for output */
  Serial.begin(115200);

   /*Begin transmission*/
  Wire.beginTransmission(0x76);
  
  /*Start hum device*/
  Wire.write(0xF2);
  Wire.write(0x1);

  /*Start t&p device*/
  Wire.write(0xF4);
  Wire.write(0x27);


        /*Write in Data acquisition direction for pres*/
  Wire.write(0x88);
  
  Wire.endTransmission();

 

}
uint32_t callarray(uint16_t pos);
static uint32_t data;
data=arr[pos]<<12+arr[pos+1]<<4;
return data;


/* Recurrent task, called forever */
void loop()
{
  /* Welcome message! Useful to know where  */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");
  
 
      /* Request data from slave with address 0x76 */

  Wire.requestFrom(0x76, 128);


  static uint8_t arr[128];
  uint16_t arr_i=0;
  
  /* Wait for data to be available */
  while (Wire.available() && arr_i<=128)
  {    

  
  /* Receive the byte */
   arr[arr_i++]=Wire.read();


    /* Send it to console/monitor */
    Serial.printf("Received byte: %u \n", arr[arr_i]);
     /*End transmission */

  }

  /* Ensure not to flood with a huge amount of fast data */
  delay(500);
  

}
