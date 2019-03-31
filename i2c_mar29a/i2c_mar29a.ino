#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2); //SDA and SCL

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  Wire.beginTransmission(0x76);// start a connection with slave device
  Wire.write(0xD0);//select the register adress
  Wire.requestFrom(0x76, 1); //number of bytes to read
  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    char c = Wire.read();

    // print the character
    Serial.printf("Received: %02X\n", c);
  }
  delay(500);
  Wire.endTransmission();
}
