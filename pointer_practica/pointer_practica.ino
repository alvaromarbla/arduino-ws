/* Include required headers and/or libraries */

/*
 * Single-pass function to configure the app
 */
void setup()
{
  /* Start serial for output */
  Serial.begin(115200);

  /* Welcome message! Useful as a control point */
  Serial.printf("Ahoy! ESP8266 here!\n---\n");
}

/*
 * Recurrent task, called forever
 */
void loop()
{
  /* Create some variables of different types */
  uint8_t  var_u8    =   8;
  int8_t   var_i8    =  -8;
  char     var_ch    = 'c';
  uint16_t var_u16   =  16;
  int16_t  var_i16   = -16;
  uint32_t var_u32   =  32;
  int32_t  var_i32   = -32;
  float    var_flt   = 1.0;
  double   var_dbl   = 2.0;

  /* Create a few arrays */
  uint8_t  arr_u8[8] = {  1,   2,   3,   4,   5,   6,   7,   8  };
  int8_t   arr_i8[8] = { -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8  };
  char     arr_ch[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

  /* Create a few simple (single) pointers */
  uint8_t  *pt_u8    = &var_u8;
  int8_t   *pt_i8    = &var_i8;
  char     *pt_ch    = &var_ch;

  /* Check some variables assignments */
  Serial.printf("Checking variables assignments:\n");
  Serial.printf("(TIP: '@' means 'addressed at')\n");
  Serial.printf(" - Direct-access (using variable name):\n");
  Serial.printf("   - uint8_t  var_u8 ...: %3u @ 0x%X\n", var_u8, &var_u8);
  Serial.printf("   - int8_t   var_i8 ...: %3i @ 0x%X\n", var_i8, &var_i8);
  Serial.printf("   - char     var_ch ...: %3c @ 0x%X\n", var_ch, &var_ch);
  Serial.printf("   - uint16_t var_u16 ..: %3u @ 0x%X\n", var_u16, &var_u16);
  Serial.printf("   - int16_t  var_i16 ..: %3i @ 0x%X\n", var_i16, &var_i16);
  Serial.printf("   - uint32_t var_u32 ..: %3u @ 0x%X\n", var_u32, &var_u32);
  Serial.printf("   - int32_t  var_i32 ..: %3i @ 0x%X\n", var_i32, &var_i32);
  Serial.printf("   - float    var_flt ..: %1.1f @ 0x%X\n", var_flt, &var_flt);
  Serial.printf("   - double   var_dbl ..: %1.1f @ 0x%X\n", var_dbl, &var_dbl);

  Serial.printf(" - Indirect-access (using pointers):\n");
  Serial.printf("   - Pointed by pt_u8 ..: %3u @ 0x%X\n", *pt_u8, pt_u8);
  Serial.printf("   - Pointed by pt_i8 ..: %3i @ 0x%X\n", *pt_i8, pt_i8);
  Serial.printf("   - Pointed by pt_ch ..: %3c @ 0x%X\n", *pt_ch, pt_ch);

  /* Reassign pointers from single variables to arrays members */
  /* Same: pt_u8 = &arr_u8[0]; */
  pt_u8 = arr_u8;
  /* Same: pt_i8 = &arr_i8[0]; */
  pt_i8 = arr_i8;
  /* Same: pt_ch = &arr_ch[0]; */
  pt_ch = arr_ch;
  Serial.printf(" - Same pointers, but reassigned to arrays:\n");
  Serial.printf("   - Pointed by pt_u8 ..: %3u @ 0x%X\n", *pt_u8, pt_u8);
  Serial.printf("   - Pointed by pt_i8 ..: %3i @ 0x%X\n", *pt_i8, pt_i8);
  Serial.printf("   - Pointed by pt_ch ..: %3c @ 0x%X\n", *pt_ch, pt_ch);

  /* Move to next position on arrays */
  pt_u8++;
  pt_i8++;
  pt_ch++;
  Serial.printf(" - Same pointers, but after incrementing by 1:\n");
  Serial.printf("   - Pointed by pt_u8 ..: %3u @ 0x%X\n", *pt_u8, pt_u8);
  Serial.printf("   - Pointed by pt_i8 ..: %3i @ 0x%X\n", *pt_i8, pt_i8);
  Serial.printf("   - Pointed by pt_ch ..: %3c @ 0x%X\n", *pt_ch, pt_ch);

  /* ~~ o ~~ */

  /* Process is locked until reset is performed */
  Serial.printf("Locking now\n");
  while (true)
  {
    /* Ensure other tasks are working (avoid WDT reset) */
    yield();
  }
}
