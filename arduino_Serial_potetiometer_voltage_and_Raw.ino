// This lab was to use the Arduino and read the analog value of pin A0,
//then calculate the voltage value, and displays both the raw and voltage values
//  on the serial monitor. It uses the analogRead() function to read the A0 pin
// and calculates the voltage value by dividing the A0Value by 1023 and multiplying by 5. 
//This lab was to familiarize us with the use of a petentiometer along with 
// how to utilize the LCD screen while displaying two values 
// Sets integer of pin A0 to A0Value
int A0Value = A0;

void setup() {
// configure the parameters of the serial monitor 
Serial.begin(9600);
}
void loop() {
// Read Pin A0 
analogRead(A0Value);
// display "The raw value is:" on the serial monitor
Serial.print("The raw value is:");
// add a space for ease of reading 
Serial.print("\t");
// Print the actual A0value
Serial.print(A0Value);
// add a space for seperation 
Serial.print("\t");
//Define A0voltValue value as (A0Value/1023)*5
float A0VoltValue = (A0Value/1023)*5;
// display "The Voltage value is:" on the serial monitor
Serial.print("The voltage value is:");
// add a space for ease of reading 
Serial.print("\t");
// Print the actual A0Voltvalue
Serial.println(A0VoltValue);
}
