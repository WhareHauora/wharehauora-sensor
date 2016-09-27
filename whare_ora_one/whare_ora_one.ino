#define MY_RADIO_NRF24 
#define MY_DEBUG_VERBOSE
#define NODE_ID 80
#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1

#define HUMIDITY_SENSOR_DIGITAL_PIN 4

#include <SPI.h>
#include <MySensors.h>
#include <DHT.h>

unsigned long SLEEP_TIME = 45000; // Sleep time between reads (in milliseconds)

DHT dht;

MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);

void setup(){
  Serial.begin(115200);
//  begin(NULL, NODE_ID, REPEATER_MODE_ON);
  dht.setup(HUMIDITY_SENSOR_DIGITAL_PIN);

  present(CHILD_ID_HUM, S_HUM);
  present(CHILD_ID_TEMP, S_TEMP);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  
  //Temperature
  float temperature = dht.getTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed reading temperature from DHT");
  }
  else  {
    send(msgTemp.set(temperature, 1));
    Serial.print("T: ");
    Serial.println(temperature);
  }

  // humidity
  float humidity = dht.getHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed reading humidity from DHT");
  }
  else {
    send(msgHum.set(humidity, 1));
    Serial.print("H: ");
    Serial.println(humidity);
  }

  sleep(SLEEP_TIME); //sleep a bit
}





