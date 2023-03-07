// In this lab we will be creating a multimeter to measure the 
// resistance values of various resistors with analogRead. 
// The main differnece of this lab was the utilization of mulitple 
// lines of equations with more than one varible, 
// simotaniously we leart how to impleament custom symbols onto our LCD display,
//  in our case we created a ohm symbol for the multimeter

#include <LiquidCrystal.h>
// Assigning pins to the LCD Display
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// creating the custom character in our case the ohm symbol 
byte customChar[8] = {
	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b10001,
	0b01010,
	0b10001,
	0b00000
};
void setup() {
  // Configure the parameters of the LCD
  lcd.begin(16, 2); 
  lcd.createChar(0,customChar);
  // Initialize serial communication
  Serial.begin(9600);
}
void loop() {
  // Read A0Value through the A0 pin
float A0Value = analogRead(A0);
// starts to Convert the input value to a voltage value 
float A0VoltValue1 = (A0Value/1023.0);
// finilizes the Conversion of the input value to a voltage value 
float A0VoltValueFinal = (A0VoltValue1*5.0);
// Calculate current based off the voltage value and known resistor 
float IAValue = (5-A0VoltValueFinal)/9933.0;
//Converts the current value to mA for ease of viewing 
float IAValuemA = (IAValue*1000);
//Calculates the resistance given the voltage and current.
float resistance = (A0VoltValueFinal/IAValue);

  
  
  // Display resistance with Ω symbol on the LCD
  // set the cursor to the top left corner of the LCD
  lcd.setCursor(0,0); 
  // display the text "Resistance:"
  lcd.print("Res:"); 
  // display the value of resistance
  lcd.print(resistance);
  // write the custom byte we defined previously  
  lcd.write((byte)0);
 

// print "resistance =" on the serial monitor 
Serial.print("resistance =");
// Print resistance value 
Serial.println(resistance);
// put a space on the serial monitor 
Serial.print("\t");
// print "Volts ="" on the serial monitor 
Serial.print("Volts =");
//Print the voltage value on the serial monitor 
Serial.print(A0VoltValueFinal);
// put a space on the serial monitor 
Serial.print("\t");
// print "current mA =" on the serial monitor 
Serial.print("current mA =");
// Print The current value to the serial monitor 
Serial.print(IAValuemA);
// put a space on the serial monitor 
Serial.print("\t");
}
