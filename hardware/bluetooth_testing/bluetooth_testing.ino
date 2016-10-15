#include <BLEAttribute.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLECommon.h>
#include <BLEDescriptor.h>
#include <BLEPeripheral.h>
#include <BLEService.h>
#include <BLETypedCharacteristic.h>
#include <BLETypedCharacteristics.h>
#include <BLEUuid.h>
#include <CurieBLE.h>
// Create my own UUIDs; used https://www.uuidgenerator.net/
BLEService statusService("2947af14-fc38-11e5-86aa-5e5517507c66");
#define status_UUID "2947af14-fc38-11e5-86aa-5e5517507c66"
// Arduino 101 acts as a BLE peripheral
BLEPeripheral blePeripheral;
BLEIntCharacteristic statusval(status_UUID, BLERead | BLENotify);

// Assign pin to indicate BLE connection 
const int INDICATOR_PIN = 2;

void setup() {
  Serial.begin(9600);
 
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

void loop() {
  // Check if the connection to the central is active or not
  BLECentral central = blePeripheral.central();
  if(central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(INDICATOR_PIN, HIGH);  
    while(central.connected()) {
      updatestatus();
    }
    
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
    digitalWrite(INDICATOR_PIN, LOW);
  }
}

void updatestatus() {
  statusval.setValue(1);
}


