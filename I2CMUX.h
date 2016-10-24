#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"
class I2CMUX8{
public:
    //Function to select port on I2C multiplexer.  Valid int argument range 0-7.
    bool setPort(int port);
private:
    int address = 0x70;
    int startPort = 0x08;
    byte status;
};