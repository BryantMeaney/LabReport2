// This code will flash the red LED every 100ms and turn on/off the blue LED 
// instantly based on the button state. The blue LED is controlled by the pushbutton, 
//and the red LED flashes independently every 100ms.
// This lab was differnt as we could not use the "delay" code as it would interfiere
// with the flashing LED so we had to use the Millies code to get around this delema 
// sets integer names to pin 3 as redLed
int redLed = 3;
// sets integer names to pin 5 as blueLed
int blueLed = 4;
// sets integer names to pin 2 as button
int button = 2;
// buttonState used to store the button state
int buttonState = HIGH;
// will store last time LED was updated
unsigned long previousMillis = 0; 
// interval at which to blink (milliseconds)
const long interval = 100;

void setup() {
  // configures pin 2 as an input pull up
  pinMode(button, INPUT_PULLUP);
  // configures pin 3 as an Output 
  pinMode(redLed, OUTPUT);
  // configures pin 5 as an Output 
  pinMode(blueLed, OUTPUT);
}
void loop() {
  // Read the value of the button input on pin 2 
  buttonState = digitalRead(button);
// Turn on/off the blue LED based on the button state
  digitalWrite(blueLed, !buttonState);
// Get the current time
  unsigned long currentMillis = millis();
// Check if it's time to update the red LED
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you updated the LED
    previousMillis = currentMillis;
// Toggle the state of the red LED
    digitalWrite(redLed, !digitalRead(redLed));
  }
}