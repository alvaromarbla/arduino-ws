#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2); //SDA and SCL

  // start serial for output
  Serial.begin(115200);
}

void loop() {
  // request 6 bytes from slave device #0xDD
  Wire.requestFrom(0xEC, 6); //Look Datasheet

  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    char c = Wire.read();

    // print the character
    Serial.printf("Received: %02X\n", c);
  }

  delay(500);
}
