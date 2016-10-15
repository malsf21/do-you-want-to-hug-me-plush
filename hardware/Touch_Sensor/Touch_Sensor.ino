const int TouchPin=8;
void setup() {
pinMode(TouchPin, INPUT);
Serial.begin(9600);
} 
 
void loop() {
int sensorValue = digitalRead(TouchPin);
Serial.println(sensorValue);
}
