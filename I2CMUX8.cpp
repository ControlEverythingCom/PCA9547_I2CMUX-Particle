#include "I2CMUX8.h"


bool I2CMUX8::setPort(int port){
    Wire.beginTransmission(address);
    Wire.write(startPort+port);
    return(Wire.endTransmission() == 0);
}