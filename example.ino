// This #include statement was automatically added by the Particle IDE.
#include "I2CMUX8.h"

I2CMUX8 mux;

String deviceList = "";

void setup() {
    Wire.begin();
    Particle.variable("Device_List", deviceList);
}

void loop() {
    String tempList = "";
    for(int i = 0; i < 8; i++){
        if(mux.setPort(i)){
            for(int k = 0; k < 128; k++){
                Wire.beginTransmission(k);
                if(Wire.endTransmission(k) == 0 && k != 0x70){
                    char buffer[50];
                    sprintf(buffer, "Device at address %i on port %i \n", k, i);
                    tempList.concat(buffer);
                }
            }
        }else{
            Serial.printf("Failed to set multiplexer to port %i \n", i);
        }
    }
    deviceList = tempList;
    Serial.println("Device List:");
    Serial.println(deviceList);
}