// This code is for an Arduino project that reads an analog voltage value from pin A0 
//it then  displays it on both the serial monitor and an LCD display. 
//it displays both values at the same time on the same screen.
// This lab was our first use of The LCD display 
//along with how to downlaod the library and wire it properly.
// Downloads the LCD Arduino Library for use 
#include <LiquidCrystal.h>
// Sets integer of pin A0 to A0Value
int A0Value = A0;
// assiging pins to the LCD Display 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
// configure the parameters of the serial monitor 
Serial.begin(9600);
// configure the parameters of the LCD
lcd.begin(16, 2); 
}
void loop() {
analogRead(A0Value);// Read Pin A0 
// display "The raw value is:" on the serial monitor
Serial.print("The raw value is:");
Serial.print("\t");// add a space for ease of reading 
// Print the actual A0value
Serial.print(A0Value);
Serial.print("\t");// add a space for ease of reading 
//Define A0voltValue value as (A0Value/1023)*5
float A0VoltValue = (A0Value/1023)*5;
// display "The Voltage value is:" on the serial monitor
Serial.print("The voltage value is:");
// add a space for ease of reading 
Serial.print("\t");
// Print the actual A0Voltvalue
Serial.println(A0VoltValue);
//print "volt value:" on LCD
lcd.print("volt value:");
//print value of A0VoltValue on the LCD
lcd.print(A0VoltValue);
// print it on the top line of the LCD
lcd.setCursor(0,0);
//print "raw value:" on LCD
lcd.print("raw value:");
//print actual value of A0value on LCD
lcd.print(A0Value);
// print it on the bottom line of the LCD
lcd.setCursor(0,1);
}
