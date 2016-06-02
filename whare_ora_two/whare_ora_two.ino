#include "SensorConfig.h"

#include "LedColours.h"
#include "PushButton.h"
#include "SoilSensor.h"
#include <SPI.h>
#include <MySensor.h>
#include <DHT.h>

MySensor gw;
DHT dht;
float lastTemp;
float lastHum;
float lastSoil;
boolean metric = true;

MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);
MyMessage msgSoil(CHILD_ID_SOIL, V_LEVEL);
MyMessage msgButton(CHILD_ID_BUTTON, V_STATUS);


/**
 * Read moisture (voltage change) across 2 pins
 * Then read in reverse.
 * Alternating polatity makes the metal in the pot last longer.
 */
float readPlantMoisture()
{

  //first read
  setSensorPolarity(true);
  
  gw.wait(TIME_BETWEEN_SOIL_READINGS);
  
  float val1 = analogRead(SOIL_SENSOR_PIN);
  gw.wait(TIME_BETWEEN_SOIL_READINGS);

  //second read, opposite polarity
  setSensorPolarity(false);

  gw.wait(TIME_BETWEEN_SOIL_READINGS);
  // invert the reading
  float val2 = 1023 - analogRead(SOIL_SENSOR_PIN);

  // put both pins low, to save the probes
  digitalWrite(SOIL_PIN_1, LOW);
  digitalWrite(SOIL_PIN_2, LOW);

  Serial.println("val1 = " + (String)val1);
  Serial.println("val2 = " + (String)val2);
  float avg = (val1 + val2) /2;
  Serial.println("average = " + (String) avg);


  
  return avg;
}


void setup()
{

  Serial.begin(115200);
  
  setupSoilSensor();
//  setupButton();
  setupLeds();

  Serial.println("Set leds to white");
  
  gw.begin(NULL, NODE_ID, REPEATER_MODE, PARENT_ID);
  dht.setup(HUMIDITY_SENSOR_DIGITAL_PIN);
//
//  // Send the Sketch Version Information to the Gateway
  gw.sendSketchInfo("soil", "1.0");
//
//  // Register all sensors to gw (they will be created as child devices)
  gw.present(CHILD_ID_HUM, S_HUM);
  gw.present(CHILD_ID_TEMP, S_TEMP);
  gw.present(CHILD_ID_SOIL, S_MOISTURE);
  gw.present(CHILD_ID_BUTTON, S_BINARY);

    // Register binary input sensor to gw (they will be created as child devices)
  // You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage. 
  // If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
  gw.present(CHILD_ID_BUTTON, S_DOOR);  
}

void loop()
{

  ControllerConfig config = gw.getConfig();


  //  checkButton();
  
  gw.wait(dht.getMinimumSamplingPeriod());
  
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
  
  // soil
  float soil = readPlantMoisture();
  gw.send(msgSoil.set(soil, 1));
    
  Serial.print("P: ");
  Serial.println(soil);

  lightUpLeds(temperature, humidity, soil);
 
  gw.sleep(SLEEP_TIME); //sleep a bit
}



