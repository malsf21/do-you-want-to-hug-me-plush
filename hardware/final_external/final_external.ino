#include <SoftwareSerial.h>
const int Eye_left = 2;
const int Eye_right = 6;
const int TouchPin_1=3;
const int TouchPin_2=4;
const int TouchPin_3=5;
const int TouchPin_4=7;
const int TouchPin_5=8;
int sum_input;
//set up bluetooth
SoftwareSerial BT(10, 11); 

void setup() { 
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(Eye_left, OUTPUT);
  pinMode(Eye_right, OUTPUT);
  pinMode(TouchPin_1, INPUT);
  pinMode(TouchPin_2, INPUT);
  pinMode(TouchPin_3, INPUT);
  pinMode(TouchPin_4, INPUT);
  pinMode(TouchPin_5, INPUT);

  // Now, activate the BLE peripheral
  
}




void loop() {

  sum_input = digitalRead(TouchPin_1)+digitalRead(TouchPin_2)+digitalRead(TouchPin_3)+digitalRead(TouchPin_4)+digitalRead(TouchPin_5);
  Serial.println(sum_input);
  if (sum_input !=0){
    BT.println("1");
    for (int i=0; i < 3; i++){
        digitalWrite(Eye_left, HIGH);
        digitalWrite(Eye_right, HIGH);       
        delay(100); 
        digitalWrite(Eye_left, LOW);  
        digitalWrite(Eye_right, LOW);  
        delay(100); 
        Serial.println("flag");
      }    
  }else{
    BT.println("0");
  }
  sum_input = 0; 
  digitalWrite(Eye_left, LOW);  
  digitalWrite(Eye_right, LOW);    

}
