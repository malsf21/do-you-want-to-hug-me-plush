const int Eye = 2;
const int TouchPin_1=3;
const int TouchPin_2=4;
const int TouchPin_3=5;
const int TouchPin_4=6;
const int TouchPin_5=7;
const int TouchPin_6=8;
int sum_input;


void setup() { 
  pinMode(Eye, OUTPUT);
  pinMode(TouchPin_1, INPUT);
  pinMode(TouchPin_2, INPUT);
  pinMode(TouchPin_3, INPUT);
  pinMode(TouchPin_4, INPUT);
  pinMode(TouchPin_5, INPUT);
  pinMode(TouchPin_6, INPUT);
  Serial.begin(9600);
}

void loop() {
  sum_input = digitalRead(TouchPin_1)+digitalRead(TouchPin_2)+digitalRead(TouchPin_3)+digitalRead(TouchPin_4)+digitalRead(TouchPin_5)+digitalRead(TouchPin_6);
  Serial.println(sum_input);
  while(sum_input != 0){
    for (int i=0; i < 3; i++){
      digitalWrite(Eye, HIGH);    
      delay(100); 
      digitalWrite(Eye, LOW);  
      delay(100); 
    } 
     
    sum_input = 0;     
  }
  digitalWrite(Eye, LOW);   
                 


}
