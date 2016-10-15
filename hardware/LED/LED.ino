const int LED_Pin = 2;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_Pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
}
