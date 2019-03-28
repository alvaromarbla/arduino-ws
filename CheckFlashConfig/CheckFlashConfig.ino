/*
  ESP8266 CheckFlashConfig by Markus Sattler

  This sketch tests if the EEPROM settings of the IDE match to the Hardware

*/
uint32_t var1=3;
uint32_t var2=40;
uint32_t var3=20;

void setup(void) {
  Serial.begin(115200);
}

void loop() {
  var1=var1+1;
  var2=var2*var1;
  var3=var3-var2;
  Serial.printf("%u %u %u\n",var1,var2,var3);
  delay(1000);
}
