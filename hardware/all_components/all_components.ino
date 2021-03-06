//import libraries
#include <BLEAttribute.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLECommon.h>
#include <BLEDescriptor.h>
#include <BLEPeripheral.h>
#include <BLEService.h>
#include <BLETypedCharacteristic.h>
#include <BLEUuid.h>
#include <CurieBLE.h>
//define ports
const int Eye = 2;
const int TouchPin_1=3;
const int TouchPin_2=4;
const int TouchPin_3=5;
const int TouchPin_4=6;
const int TouchPin_5=7;
const int TouchPin_6=8;
int sum_input;
//set up bluetooth
BLEService statusService("2947af14-fc38-11e5-86aa-5e5517507c66");
#define status_UUID "2947af14-fc38-11e5-86aa-5e5517507c66"
BLEPeripheral blePeripheral;
BLEIntCharacteristic statusval(status_UUID, BLERead | BLENotify);

void setup() { 
  Serial.begin(9600);
  pinMode(Eye, OUTPUT);
  pinMode(TouchPin_1, INPUT);
  pinMode(TouchPin_2, INPUT);
  pinMode(TouchPin_3, INPUT);
  pinMode(TouchPin_4, INPUT);
  pinMode(TouchPin_5, INPUT);
  pinMode(TouchPin_6, INPUT);
  // Initialize BLE peripheral
  blePeripheral.setLocalName("Plush");
  blePeripheral.setAdvertisedServiceUuid(statusService.uuid());
  blePeripheral.addAttribute(statusService);
  blePeripheral.addAttribute(statusval);
  // Set initial values
  statusval.setValue(0);
  // Now, activate the BLE peripheral
  blePeripheral.begin();
  Serial.println("Bluetooth device active, waiting for connections...");
}


void updatestatus() {
  statusval.setValue(sum_input);
}

void loop() {
  BLECentral central = blePeripheral.central();
  sum_input = digitalRead(TouchPin_1)+digitalRead(TouchPin_2)+digitalRead(TouchPin_3)+digitalRead(TouchPin_4)+digitalRead(TouchPin_5)+digitalRead(TouchPin_6);
  Serial.println(sum_input);
  if(central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    updatestatus();
    while(sum_input != 0 && central.connected()){
      for (int i=0; i < 3; i++){
        digitalWrite(Eye, HIGH);    
        delay(100); 
        digitalWrite(Eye, LOW);  
        delay(100); 
        Serial.println("flag");
      }    
    sum_input = 0; 
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
    digitalWrite(Eye, LOW);    
    }
  }
}
