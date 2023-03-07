//This Arduino code sets the brightness values for three RGB
// (Red, Green, Blue) pins, RedPin, BluePin, and GreenPin. 
//It initializes the brightness levels of Red, Blue, and Green as integers,
// The purpose of this lab was to become familar with the RGB Led 
// along with the "analogWrite" command and how to implement it within our code.
//sets the red value of brightness from 0-255 
int Red_Amount= 255;
//sets the Blue value of brightness from 0-255 
int Blue_Amount= 100;
//sets the Green value of brightness from 0-255 
int Green_Amount= 0;
//Sets the Pin of the arduino to an integer such as RedPin
int RedPin= 3;
//Sets the Pin of the arduino to an integer such as BluePin
int BluePin= 5;
//Sets the Pin of the arduino to an integer such as GreenPin
int GreenPin =6;
void setup() {
  // put your setup code here, to run once:

pinMode(9,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
// sends voltage to RedPin based on Red_Amount
analogueWrite(RedPin,Red_Amount);
// sends voltage to BluePin based on Blue_Amount
analogueWrite(BluePin,Blue_Amount);
// sends voltage to GreenPin based on Green_Amount
analogueWrite(GreenPin,Green_Amount);



}
