#define MY_RADIO_NRF24
#define MY_DEBUG
#define MY_DEBUG_VERBOSE

#define HUMIDITY_SENSOR_DIGITAL_PIN 4
#define SLEEP_TIME 30000 // Sleep time between reads (in milliseconds)

#include <MySensors.h>
#include <SPI.h>
#include <DHT.h>

#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1

DHT dht;

MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);

void presentation() {
  present(CHILD_ID_HUM, S_HUM);
  present(CHILD_ID_TEMP, S_TEMP);
}

void setup() {
  dht.setup(HUMIDITY_SENSOR_DIGITAL_PIN);
}

void loop() {
  wait(dht.getMinimumSamplingPeriod());

  //Temperature
  float temperature = dht.getTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed reading temperature from DHT");
  }
  else {
    send(msgTemp.set(temperature, 1));
  }

  // humidity
  float humidity = dht.getHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed reading humidity from DHT");
  }
  else {
    send(msgHum.set(humidity, 1));
  }
  sleep(SLEEP_TIME); //sleep a bit
}



