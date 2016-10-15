int buzzer = 3;
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(3, OUTPUT);
} 

void loop()  { 

 
  tone(buzzer, 50); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
 
}

void beep(unsigned char delayms){
  analogWrite(3, 3);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(3, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  

