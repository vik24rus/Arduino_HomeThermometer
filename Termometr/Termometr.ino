//We always have to include the library
#include "LedControlMS.h"
#include "OneWire.h"


/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 6 is connected to CS
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,2);
OneWire  ds(9);  // on pin 10 (a 4.7K resistor is necessary)

byte out[8]=    {B00111100,B01000010,B10010101,B10010001,B10010001, B10010101, B01000010, B00111100};
byte numbers[100][8]= {
  {B00000000, B00000000, B00000000, B00000000, B00000000, B11111111, B10000001, B11111111},//0
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000100, B00000010, B11111111},//1
  {B00000000, B00000000, B00000000, B00000000, B00000000, B11110011, B10001001, B10000111},//2
  {B00000000, B00000000, B00000000, B00000000, B00000000, B10001001, B10001001, B11111111},//3
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00001111, B00001000, B11111111},//4
  {B00000000, B00000000, B00000000, B00000000, B00000000, B10001111, B10001001, B11111001},//5
  {B00000000, B00000000, B00000000, B00000000, B00000000, B11111111, B10001001, B11111001},//6
  {B00000000, B00000000, B00000000, B00000000, B00000000, B11110001, B00001001, B00000111},//7
  {B00000000, B00000000, B00000000, B00000000, B00000000, B11111111, B10001001, B11111111},//8
  {B00000000, B00000000, B00000000, B00000000, B00000000, B10001111, B10001001, B11111111},//9
  {B00000000, B00000100, B00000010, B11111111, B00000000, B11111111, B10000001, B11111111},//10
  {B00000000, B00000100, B00000010, B11111111, B00000000, B00000100, B00000010, B11111111},//11
  {B00000000, B00000100, B00000010, B11111111, B00000000, B11110011, B10001001, B10000111},//12
  {B00000000, B00000100, B00000010, B11111111, B00000000, B10001001, B10001001, B11111111},//13
  {B00000000, B00000100, B00000010, B11111111, B00000000, B00001111, B00001000, B11111111},//14
  {B00000000, B00000100, B00000010, B11111111, B00000000, B10001111, B10001001, B11111001},//15
  {B00000000, B00000100, B00000010, B11111111, B00000000, B11111111, B10001001, B11111001},//16
  {B00000000, B00000100, B00000010, B11111111, B00000000, B11110001, B00001001, B00000111},//17
  {B00000000, B00000100, B00000010, B11111111, B00000000, B11111111, B10001001, B11111111},//18
  {B00000000, B00000100, B00000010, B11111111, B00000000, B10001111, B10001001, B11111111},//19
  {B00000000, B11110011, B10001001, B10000111, B00000000, B11111111, B10000001, B11111111},//20
  {B00000000, B11110011, B10001001, B10000111, B00000000, B00000100, B00000010, B11111111},//21
  {B00000000, B11110011, B10001001, B10000111, B00000000, B11110011, B10001001, B10000111},//22
  {B00000000, B11110011, B10001001, B10000111, B00000000, B10001001, B10001001, B11111111},//23
  {B00000000, B11110011, B10001001, B10000111, B00000000, B00001111, B00001000, B11111111},//24
  {B00000000, B11110011, B10001001, B10000111, B00000000, B10001111, B10001001, B11111001},//25
  {B00000000, B11110011, B10001001, B10000111, B00000000, B11111111, B10001001, B11111001},//26
  {B00000000, B11110011, B10001001, B10000111, B00000000, B11110001, B00001001, B00000111},//27
  {B00000000, B11110011, B10001001, B10000111, B00000000, B11111111, B10001001, B11111111},//28
  {B00000000, B11110011, B10001001, B10000111, B00000000, B10001111, B10001001, B11111111},//29
  {B00000000, B10001001, B10001001, B11111111, B00000000, B11111111, B10000001, B11111111},//30
  {B00000000, B10001001, B10001001, B11111111, B00000000, B00000100, B00000010, B11111111},//31
  {B00000000, B10001001, B10001001, B11111111, B00000000, B11110011, B10001001, B10000111},//32 
  {B00000000, B10001001, B10001001, B11111111, B00000000, B10001001, B10001001, B11111111},//33
  {B00000000, B10001001, B10001001, B11111111, B00000000, B00001111, B00001000, B11111111},//34
  {B00000000, B10001001, B10001001, B11111111, B00000000, B10001111, B10001001, B11111001},//35
  {B00000000, B10001001, B10001001, B11111111, B00000000, B11111111, B10001001, B11111001},//36
  {B00000000, B10001001, B10001001, B11111111, B00000000, B11110001, B00001001, B00000111},//37
  {B00000000, B10001001, B10001001, B11111111, B00000000, B11111111, B10001001, B11111111},//38
  {B00000000, B10001001, B10001001, B11111111, B00000000, B10001111, B10001001, B11111111},//39
  {B00000000, B00001111, B00001000, B11111111, B00000000, B11111111, B10000001, B11111111},//40
  {B00000000, B00001111, B00001000, B11111111, B00000000, B00000100, B00000010, B11111111},//41
  {B00000000, B00001111, B00001000, B11111111, B00000000, B11110011, B10001001, B10000111},//42 
  {B00000000, B00001111, B00001000, B11111111, B00000000, B10001001, B10001001, B11111111},//43
  {B00000000, B00001111, B00001000, B11111111, B00000000, B00001111, B00001000, B11111111},//44
  {B00000000, B00001111, B00001000, B11111111, B00000000, B10001111, B10001001, B11111001},//45
  {B00000000, B00001111, B00001000, B11111111, B00000000, B11111111, B10001001, B11111001},//46
  {B00000000, B00001111, B00001000, B11111111, B00000000, B11110001, B00001001, B00000111},//47
  {B00000000, B00001111, B00001000, B11111111, B00000000, B11111111, B10001001, B11111111},//48
  {B00000000, B00001111, B00001000, B11111111, B00000000, B10001111, B10001001, B11111111},//49
  {B00000000, B10001111, B10001001, B11111001, B00000000, B11111111, B10000001, B11111111},//50
  {B00000000, B10001111, B10001001, B11111001, B00000000, B00000100, B00000010, B11111111},//51
  {B00000000, B10001111, B10001001, B11111001, B00000000, B11110011, B10001001, B10000111},//52 
  {B00000000, B10001111, B10001001, B11111001, B00000000, B10001001, B10001001, B11111111},//53
  {B00000000, B10001111, B10001001, B11111001, B00000000, B00001111, B00001000, B11111111},//54
  {B00000000, B10001111, B10001001, B11111001, B00000000, B10001111, B10001001, B11111001},//55
  {B00000000, B10001111, B10001001, B11111001, B00000000, B11111111, B10001001, B11111001},//56
  {B00000000, B10001111, B10001001, B11111001, B00000000, B11110001, B00001001, B00000111},//57
  {B00000000, B10001111, B10001001, B11111001, B00000000, B11111111, B10001001, B11111111},//58
  {B00000000, B10001111, B10001001, B11111001, B00000000, B10001111, B10001001, B11111111},//59
  {B00000000, B11111111, B10001001, B11111001, B00000000, B11111111, B10000001, B11111111},//60
  {B00000000, B11111111, B10001001, B11111001, B00000000, B00000100, B00000010, B11111111},//61
  {B00000000, B11111111, B10001001, B11111001, B00000000, B11110011, B10001001, B10000111},//62 
  {B00000000, B11111111, B10001001, B11111001, B00000000, B10001001, B10001001, B11111111},//63
  {B00000000, B11111111, B10001001, B11111001, B00000000, B00001111, B00001000, B11111111},//64
  {B00000000, B11111111, B10001001, B11111001, B00000000, B10001111, B10001001, B11111001},//65
  {B00000000, B11111111, B10001001, B11111001, B00000000, B11111111, B10001001, B11111001},//66
  {B00000000, B11111111, B10001001, B11111001, B00000000, B11110001, B00001001, B00000111},//67
  {B00000000, B11111111, B10001001, B11111001, B00000000, B11111111, B10001001, B11111111},//68
  {B00000000, B11111111, B10001001, B11111001, B00000000, B10001111, B10001001, B11111111},//69
  {B00000000, B11110001, B00001001, B00000111, B00000000, B11111111, B10000001, B11111111},//70
  {B00000000, B11110001, B00001001, B00000111, B00000000, B00000100, B00000010, B11111111},//71
  {B00000000, B11110001, B00001001, B00000111, B00000000, B11110011, B10001001, B10000111},//72 
  {B00000000, B11110001, B00001001, B00000111, B00000000, B10001001, B10001001, B11111111},//73
  {B00000000, B11110001, B00001001, B00000111, B00000000, B00001111, B00001000, B11111111},//74
  {B00000000, B11110001, B00001001, B00000111, B00000000, B10001111, B10001001, B11111001},//75
  {B00000000, B11110001, B00001001, B00000111, B00000000, B11111111, B10001001, B11111001},//76
  {B00000000, B11110001, B00001001, B00000111, B00000000, B11110001, B00001001, B00000111},//77
  {B00000000, B11110001, B00001001, B00000111, B00000000, B11111111, B10001001, B11111111},//78
  {B00000000, B11110001, B00001001, B00000111, B00000000, B10001111, B10001001, B11111111},//79
  {B00000000, B11111111, B10001001, B11111111, B00000000, B11111111, B10000001, B11111111},//80
  {B00000000, B11111111, B10001001, B11111111, B00000000, B00000100, B00000010, B11111111},//81
  {B00000000, B11111111, B10001001, B11111111, B00000000, B11110011, B10001001, B10000111},//82 
  {B00000000, B11111111, B10001001, B11111111, B00000000, B10001001, B10001001, B11111111},//83
  {B00000000, B11111111, B10001001, B11111111, B00000000, B00001111, B00001000, B11111111},//84
  {B00000000, B11111111, B10001001, B11111111, B00000000, B10001111, B10001001, B11111001},//85
  {B00000000, B11111111, B10001001, B11111111, B00000000, B11111111, B10001001, B11111001},//86
  {B00000000, B11111111, B10001001, B11111111, B00000000, B11110001, B00001001, B00000111},//87
  {B00000000, B11111111, B10001001, B11111111, B00000000, B11111111, B10001001, B11111111},//88
  {B00000000, B11111111, B10001001, B11111111, B00000000, B10001111, B10001001, B11111111},//89
  {B00000000, B10001111, B10001001, B11111111, B00000000, B11111111, B10000001, B11111111},//90
  {B00000000, B10001111, B10001001, B11111111, B00000000, B00000100, B00000010, B11111111},//91
  {B00000000, B10001111, B10001001, B11111111, B00000000, B11110011, B10001001, B10000111},//92 
  {B00000000, B10001111, B10001001, B11111111, B00000000, B10001001, B10001001, B11111111},//93
  {B00000000, B10001111, B10001001, B11111111, B00000000, B00001111, B00001000, B11111111},//94
  {B00000000, B10001111, B10001001, B11111111, B00000000, B10001111, B10001001, B11111001},//95
  {B00000000, B10001111, B10001001, B11111111, B00000000, B11111111, B10001001, B11111001},//96
  {B00000000, B10001111, B10001001, B11111111, B00000000, B11110001, B00001001, B00000111},//97
  {B00000000, B10001111, B10001001, B11111111, B00000000, B11111111, B10001001, B11111111},//98
  {B00000000, B10001111, B10001001, B11111111, B00000000, B10001111, B10001001, B11111111} //99
   };
            


void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.begin(9600);
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,2);
  /* and clear the display */
  lc.clearDisplay(0);
  
  lc.shutdown(1,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(1,8);
  /* and clear the display */
  lc.clearDisplay(1);
  
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
//void writeArduinoOnMatrix() {
//  /* here is the data for the characters */
//  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
//  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
//  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
//  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
//  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
//  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
//  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};
//
//  /* now display them one by one with a small delay */
//  lc.setRow(0,0,a[0]);
//  lc.setRow(0,1,a[1]);
//  lc.setRow(0,2,a[2]);
//  lc.setRow(0,3,a[3]);
//  lc.setRow(0,4,a[4]);
//  delay(delaytime);
//  lc.setRow(0,0,r[0]);
//  lc.setRow(0,1,r[1]);
//  lc.setRow(0,2,r[2]);
//  lc.setRow(0,3,r[3]);
//  lc.setRow(0,4,r[4]);
//  delay(delaytime);
//  lc.setRow(0,0,d[0]);
//  lc.setRow(0,1,d[1]);
//  lc.setRow(0,2,d[2]);
//  lc.setRow(0,3,d[3]);
//  lc.setRow(0,4,d[4]);
//  delay(delaytime);
//  lc.setRow(0,0,u[0]);
//  lc.setRow(0,1,u[1]);
//  lc.setRow(0,2,u[2]);
//  lc.setRow(0,3,u[3]);
//  lc.setRow(0,4,u[4]);
//  delay(delaytime);
//  lc.setRow(0,0,i[0]);
//  lc.setRow(0,1,i[1]);
//  lc.setRow(0,2,i[2]);
//  lc.setRow(0,3,i[3]);
//  lc.setRow(0,4,i[4]);
//  delay(delaytime);
//  lc.setRow(0,0,n[0]);
//  lc.setRow(0,1,n[1]);
//  lc.setRow(0,2,n[2]);
//  lc.setRow(0,3,n[3]);
//  lc.setRow(0,4,n[4]);
//  delay(delaytime);
//  lc.setRow(0,0,o[0]);
//  lc.setRow(0,1,o[1]);
//  lc.setRow(0,2,o[2]);
//  lc.setRow(0,3,o[3]);
//  lc.setRow(0,4,o[4]);
//  delay(delaytime);
//  lc.setRow(0,0,0);
//  lc.setRow(0,1,0);
//  lc.setRow(0,2,0);
//  lc.setRow(0,3,0);
//  lc.setRow(0,4,0);
//  delay(delaytime);
//}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
//void rows() {
//  for(int row=0;row<8;row++) {
//    delay(delaytime);
//    lc.setRow(0,row,B10100000);
//    delay(delaytime);
//    lc.setRow(0,row,(byte)0);
//    for(int i=0;i<row;i++) {
//      delay(delaytime);
//      lc.setRow(0,row,B10100000);
//      delay(delaytime);
//      lc.setRow(0,row,(byte)0);
//    }
//  }
//}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
//void columns() {
//  for(int col=0;col<8;col++) {
//    delay(delaytime);
//    lc.setColumn(0,col,B10100000);
//    delay(delaytime);
//    lc.setColumn(0,col,(byte)0);
//    for(int i=0;i<col;i++) {
//      delay(delaytime);
//      lc.setColumn(0,col,B10100000);
//      delay(delaytime);
//      lc.setColumn(0,col,(byte)0);
//    }
//  }
//}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
//void single() {
//  for(int row=0;row<8;row++) {
//    for(int col=0;col<8;col++) {
//      delay(delaytime);
//      lc.setLed(0,row,col,true);
//      delay(delaytime);
//      for(int i=0;i<col;i++) {
//        lc.setLed(0,row,col,false);
//        delay(delaytime);
//        lc.setLed(0,row,col,true);
//        delay(delaytime);
//      }
//    }
//  }
//}

//void test_out_tmp(){
//  byte i;
//  byte present = 0;
//  byte type_s;
//  byte data[12];
//  byte addr[8];
//  float celsius;
//
//  if ( !ds.search(addr)) {
//    Serial.println("No more addresses.");
//    Serial.println();
////    draw_err();
//    delay(250);  
//    ds.reset_search();
//    lc.clearDisplay(0);
//    delay(250);
//    return;
//  }
//  
//  Serial.print("ROM =");
//  for( i = 0; i < 8; i++) {
//    Serial.write(' ');
//    Serial.print(addr[i], HEX);
//  }
//
//  if (OneWire::crc8(addr, 7) != addr[7]) {
//      Serial.println("CRC is not valid!");
//      return;
//  }
//  Serial.println();
// 
//  // the first ROM byte indicates which chip
//  switch (addr[0]) {
//    case 0x10:
//      Serial.println("  Chip = DS18S20");  // or old DS1820
//      type_s = 1;
//      break;
//    case 0x28:
//      Serial.println("  Chip = DS18B20");
//      type_s = 0;
//      break;
//    case 0x22:
//      Serial.println("  Chip = DS1822");
//      type_s = 0;
//      break;
//    default:
//      Serial.println("Device is not a DS18x20 family device.");
//      return;
//  } 
//
//  ds.reset();
//  ds.select(addr);
//  ds.write(0x44);        // start conversion, with parasite power on at the end
//  
//  delay(1000);     // maybe 750ms is enough, maybe not
//  // we might do a ds.depower() here, but the reset will take care of it.
//  
//  present = ds.reset();
//  ds.select(addr);    
//  ds.write(0xBE);         // Read Scratchpad
//
//  Serial.print("  Data = ");
//  Serial.print(present, HEX);
//  Serial.print(" ");
//  for ( i = 0; i < 9; i++) {           // we need 9 bytes
//    data[i] = ds.read();
//    Serial.print(data[i], HEX);
//    Serial.print(" ");
//  }
//  Serial.print(" CRC=");
//  Serial.print(OneWire::crc8(data, 8), HEX);
//  Serial.println();
//
//  // Convert the data to actual temperature
//  // because the result is a 16 bit signed integer, it should
//  // be stored to an "int16_t" type, which is always 16 bits
//  // even when compiled on a 32 bit processor.
//  int16_t raw = (data[1] << 8) | data[0];
//  if (type_s) {
//    raw = raw << 3; // 9 bit resolution default
//    if (data[7] == 0x10) {
//      // "count remain" gives full 12 bit resolution
//      raw = (raw & 0xFFF0) + 12 - data[6];
//    }
//  } else {
//    byte cfg = (data[4] & 0x60);
//    // at lower res, the low bits are undefined, so let's zero them
//    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
//    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
//    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
//    //// default is 12 bit resolution, 750 ms conversion time
//  }
//  celsius = (float)raw / 16.0;
//  Serial.print("  Temperature = ");
//  Serial.print(celsius);
//  Serial.print(" Celsius, ");
//  
//}

//void draw_err(){
//  byte err[8]={B11100000,B11100000,B11100000,B11111111,B11111111, B11100000, B11100000, B11100000};
//  for (int i=0;  i<8 ; i++){
//    lc.setRow(0,i,err[i]);
//  }
//}
//
//void worker(){
//  draw(2, true, 0);
//  delay(1000);
//}

//void draw(int temp_room, bool positive, int number_room){ 
//  if (number_room == 0){
//    lc.setLed(0,0,7,true);
//    if(positive == true){29
//      switch ( temp_room ) {
//        case 1:         
//          break;
// 
//        case 2:
//        
//        for (int i=0;  i<8 ; i++){
//          lc.setRow(0,i,number2[i]);
//        }
//         delay(2000);        
// void draw_err(){
//  byte err[8]={B11100000,B11100000,B11100000,B11111111,B11111111, B11100000, B11100000, B11100000};
//  for (int i=0;  i<8 ; i++){
//    lc.setRow(0,i,err[i]);
//  }
//}


//void draw(int temp_room, bool positive, int number_room){ 
//  if (number_room == 0){
//    lc.setLed(0,0,7,true);
//    if(positive == true){
//      switch ( temp_room ) {
//        case 1:         
//          break;
// 
//        case 2:
//        
//        for (int i=0;  i<8 ; i++){
//          lc.setRow(0,i,number2[i]);
//        }
//         delay(2000);        
//          break;
//        
//        default:          
//          break;
//        }
//    }else{
//      lc.setLed(0,0,4,true);
//    }
//  }
//
//  if (number_room == 1){
//    lc.setLed(0,0,7,true);
//    lc.setLed(0,0,6,true);
//    if(positive == true){
//      
//    }else{
//      lc.setLed(0,0,4,true);
//    }
//  }         break;
//        
//        default:          
//          break;
//        }
//    }else{
//      lc.setLed(0,0,4,true);
//    }
//  }
//
//  if (number_room == 1){
//    lc.setLed(0,0,7,true);
//    lc.setLed(0,0,6,true);
//    if(positive == true){
//      
//    }else{
//      lc.setLed(0,0,4,true);
//    }
//  }
  
//}
void loop() {

//  for (int i=0; i<100 ; i++){ 
//    delay(600);
//    lc.clearDisplay(0);
//    for (int j=0;  j<8 ; j++){
//      lc.setRow(0,j,numbers[i][j]);
//    }
//  }

}
