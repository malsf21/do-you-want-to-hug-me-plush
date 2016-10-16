#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
void setup()  
{
  // set digital pin to control as an output
  pinMode(2, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  
}

void loop() 
{
   BT.println("Hello from Arduino");
}
