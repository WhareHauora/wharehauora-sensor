#include <SPI.h>
#include <MySensor.h>
#include <DHT.h>
#include "SensorConfig.h"

unsigned long SLEEP_TIME = 15000; // Sleep time between reads (in milliseconds)

MySensor gw;
DHT dht;
float lastTemp;
float lastHum;

boolean metric = true;

MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);

void setup()
{

  Serial.begin(115200);

//  
  gw.begin(NULL, NODE_ID, REPEATER_MODE_ON);
  dht.setup(HUMIDITY_SENSOR_DIGITAL_PIN);
//
//  // Send the Sketch Version Information to the Gateway
  gw.sendSketchInfo("tahi", "1.0");
//
//  // Register all sensors to gw (they will be created as child devices)
  gw.present(CHILD_ID_HUM, S_HUM);
  gw.present(CHILD_ID_TEMP, S_TEMP);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  
  //Temperature
  float temperature = dht.getTemperature();
  if (isnan(temperature))
  {
    Serial.println("Failed reading temperature from DHT");
  }
  else if (temperature != lastTemp)
  {
    lastTemp = temperature;
    gw.send(msgTemp.set(temperature, 1));
    Serial.print("T: ");
    Serial.println(temperature);
  }

  // humidity
  float humidity = dht.getHumidity();
  if (isnan(humidity))
  {
    Serial.println("Failed reading humidity from DHT");
  }
  else if (humidity != lastHum)
  {
    lastHum = humidity;
    gw.send(msgHum.set(humidity, 1));
    Serial.print("H: ");
    Serial.println(humidity);
  }

//  gw.sendBatteryLevel(100, true);
  gw.process();
  gw.wait(SLEEP_TIME); //sleep a bit
}


void incomingMessage(const MyMessage &message) {
  Serial.println("We got a message!");
  // We only expect one type of message from controller. But we better check anyway.
//  if (message.type==V_LIGHT) {
//     // Change relay state
//     digitalWrite(RELAY_PIN, message.getBool()?RELAY_ON:RELAY_OFF);
//     // Store state in eeprom
////     gw.saveState(message.sensor, message.getBool());
////     // Write some debug info
//     Serial.print("Incoming change for sensor:");
//     Serial.print(message.sensor);
//     Serial.print(", New status: ");
//     Serial.println(message.getBool());
//   } 
}




