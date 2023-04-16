#include <IRremote.h>      //must copy IRremote library to arduino libraries
#include <Servo.h>

#define plus 0xA3C8EDDB   //clockwise rotation button
#define minus 0xF076C13B  //counter clockwise rotation button
#define buttonPin 8       //button pin

int RECV_PIN = 2;       //IR receiver pin
Servo servo;
int val;                //rotation angle
bool cwRotation, ccwRotation;  //the states of rotation

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  servo.attach(9);     //servo pin
  pinMode(buttonPin, INPUT_PULLUP); //set button pin as input with internal pull-up resistor
}

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == plus)
    {
      cwRotation = !cwRotation;      //toggle the rotation value
      ccwRotation = false;         //no rotation in this direction
    }

    if (results.value == minus)
    {
      ccwRotation = !ccwRotation;   //toggle the rotation value
      cwRotation = false;            //no rotation in this direction
    }
  }

  // Check the state of the button
  if (digitalRead(buttonPin) == LOW) {
    cwRotation = true;
    ccwRotation = false;
  } else {
    cwRotation = false;
    ccwRotation = false;
  }

  if (cwRotation && (val != 175))  {
    val++;                         //for colockwise button
  }
  if (ccwRotation && (val != 0))  {
    val--;                         //for counter colockwise button
  }
  servo.write(val);
  delay(20);          //General speed
}

