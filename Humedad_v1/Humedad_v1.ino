#include <Wire.h> 
 
void setup() { 
  // join i2c bus (address optional for master) 
  Wire.begin(0, 2); //SDA and SCL 
 
  // start serial for output 
  Serial.begin(115200); 
} 
 

void loop() { 
  Wire.beginTransmission(0x76);// start a connection with slave device 
  Wire.requestFrom(0x76, 1); //number of bytes to read 
  Wire.write(0xF7);
  
  uint8_t hum1=Wire.read();//select the register adress FD==MSB most significant byte


  // print the character 
  Serial.printf("Received: %u \n", hum1); 
  
  delay(500); 
  Wire.endTransmission();
} 
