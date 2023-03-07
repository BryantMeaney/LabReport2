// The purpose of this program is to read the value of the potentiometer and
// set the RGB LED accordingly. If the potentiometer value is less than 100,
//the RGB LED is black (no color). If the potentiometer value is greater than 300, 
//the RGB LED is set to red. If the potentiometer value is greater than 500, 
//the RGB LED is set to blue. If the potentiometer value is greater than 700,
//the RGB LED is set to green. If the potentiometer value is greater than 900, 
//the RGB LED is set to white.
// The purpose of this Lab was to familiarize ourselves with the "If" 
// command based off a condition such as the value of the potentiometer 
// sets the integer of RedPin to pin 3
int RedPin= 3;
// sets the integer of BluePin to pin 4
int BluePin= 4;
// sets the integer of GreenPin to pin 5
int GreenPin= 5;
void setup() {
// configures pin 3 to be an Output 
pinMode(3,OUTPUT);
// configures pin 4 to be an Output 
pinMode(4,OUTPUT);
// configures pin 5 to be an Output 
pinMode(5,OUTPUT);
// configures the parameters for the serial monitor 
Serial.begin(9600);
}

void loop() {
// Reads the Value of A0
analogRead(A0Value);
// Prints "The raw value is:" on the serial monitor 
Serial.print("The raw value is:");
// adds a space for ease of reading on the serial monitor 
Serial.print("\t");
// Prints the actual value of A0
Serial.print(A0Value);
// adds a space for seperation of the two values 
Serial.print("\t");
// sets the A)Volt value as (A0Value/1023.0)*5.0
float A0VoltValue = (A0Value/1023.0)*5.0;
// print "The voltage value is:" on the serial monitor 
Serial.print("The voltage value is:");
// adds a space for ease of reading on the serial monitor 
Serial.print("\t");
// Prints the actual value of A0VoltValue
Serial.println(A0VoltValue);

// if the potetiometer is below 100 then the RGB is Black 
if (A0Value<100) {
analogWrite(RedPin,0);
analogWrite(BluePin,0);
analogWrite(GreenPin,0); 
}
// if the potetiometer is above 300 then the RGB is red
if (A0Value>300) {
analogWrite(RedPin,255);
analogWrite(BluePin,0);
analogWrite(GreenPin,0);  
}
// if the potetiometer is above 500 then the RGB is Blue
if (A0Value>500) {
analogWrite(RedPin,0);
analogWrite(BluePin,255);
analogWrite(GreenPin,0); 
}
// if the potetiometer is above 700 then the RGB is Green
if (A0Value>700) {
analogWrite(RedPin,0);
analogWrite(BluePin,0);
analogWrite(GreenPin,255);
}
// if the potetiometer is above 900 then the RGB is White
if (A0Value>900) {
analogWrite(RedPin,255);
analogWrite(BluePin,255);
analogWrite(GreenPin,255);
}
}
