void setup() {
 /* Start serial for output */
  Serial.begin(115200);
}

void loop() {
   /* Welcome message! Useful as a control point */
  Serial.printf("Ahoy! ESP8266 here!\n"
                "---\n");
  
while (true)
  {
    /* Ensure other tasks are working (avoid WDT reset) */
    yield();
}
}
