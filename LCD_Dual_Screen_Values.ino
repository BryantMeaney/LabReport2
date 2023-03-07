//The purpose of this code is that if the current screen is 0, 
// the code displays the "raw value" screen and prints the raw value on the LCD 
// and the serial monitor. If the current screen is 1, the code calculates the 
// voltage value of the analog input signal and displays the "volt value" screen
// and prints the voltage value on the LCD and the serial monitor.
// The educational aspect of this lab was the implementation of a 
// second screen on our LCD along with how to use a PushButton to switch between the two

// include the LiquidCrystal library
#include <LiquidCrystal.h>

// define the pin for the push button
int pushButtonPin = 2;

// initialize button state and current screen variables
int buttonState = 0;
int currentScreen = 0;

// set A0Value variable to A0 pin
int A0Value = A0;
// Use A0Value variable to calculate A0VoltValue
float A0VoltValue = (A0Value / 1023.0) * 5.0;
// initialize the lcd with its pins 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // begin communication with the serial monitor 
  Serial.begin(9600);

  // initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // set the push button pin as input with internal pull-up resistor
  pinMode(pushButtonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the push button
  buttonState = digitalRead(pushButtonPin);

  // toggle the current screen when the button is pressed
  if (buttonState == 1) {
    // toggle the screen between 0 and 1
    currentScreen ^= 1;  
    // wait to prevent errors 
    delay(100);  
  }

  // read the value of pin A0
  analogRead(A0Value);

  // clear the LCD screen and set the cursor to the top-left corner
  lcd.clear();
  // Places the text on the top line of the LCD
  lcd.setCursor(0, 0);

  // Parameters the screen 0 
  if (currentScreen == 0) {  
    // display the "raw value: screen
    lcd.print("raw value:");
    // Displays the actual value
    lcd.print(A0Value);
  } else {  
    
    float A0VoltValue = (A0Value / 1023.0) * 5.0;  // calculate the voltage value
    // display the "volt value" screen
    lcd.print("volt value:");
    // display the voltage value screen
    lcd.print(A0VoltValue);
  }

  // print the "The Voltage Value Is" within the serial monitor 
  Serial.print("The Voltage Value is     ");
  // print the actual volt value on the serial monitor 
  Serial.print(A0VoltValue);
    // print the "The Raw value" on the serial monitor 
  Serial.println("The Raw Value is     ");
    // print the actual raw value on the serial monitor 
  Serial.print(A0Value);

}