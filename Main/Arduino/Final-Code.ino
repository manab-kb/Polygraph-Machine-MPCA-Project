
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
 
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int PulseWire = 0; 
const int LED13 = 13;
int Threshold = 550;

PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWire); 
  pulseSensor.setThreshold(Threshold);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.begin();
  dht.begin();
}
void loop() {
  delay(20);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int myBPM=pulseSensor.getBeatsPerMinute();
  float f = dht.readTemperature(true);
  if (isnan(t) || isnan(f)isnan(h) ||) { 
   return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("\t");
  Serial.print("BPM: ");                        
  Serial.println(myBPM);
  
  
}
/*
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
}*/
