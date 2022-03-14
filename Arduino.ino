#include "Wire.h"
#include "DFRobot_SHT20.h"
DFRobot_SHT20    sht20;
void setup()
{
Serial.begin(9600);
sht20.initSHT20(); // Init SHT20 Sensor
delay(100);
sht20.checkSHT20(); // Check SHT20 Sensor
}
void loop()
{
float humd = sht20.readHumidity(); // Read Humidity
float temp = sht20.readTemperature(); // Read Temperature
Serial.print(temp, 2);
Serial.print(",");
Serial.print(analogRead(A3)); // Read Pulse sensor value
Serial.print(",");
Serial.print(humd, 1);
Serial.print(",");
Serial.println(analogRead(A2)); // Read Breath rate 
//Code to be inserted for threshold post testing
}
