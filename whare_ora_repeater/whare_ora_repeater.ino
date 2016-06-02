#include <SPI.h>
#include <MySensor.h>
#include <DHT.h>
#include "SensorConfig.h"

MySensor gw;

void setup()
{

  Serial.begin(115200);

  gw.begin(NULL, AUTO, REPEATER_MODE_ON);
  gw.sendSketchInfo("repeater", "1.0");
}

void loop()
{
  gw.process();

}





