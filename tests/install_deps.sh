#!/bin/bash
set -uv

wget https://github.com/adafruit/DHT-sensor-library/archive/1.3.0.tar.gz
tar -vzxf 1.3.0.tar.gz

wget https://github.com/mysensors/MySensors/archive/2.0.0.tar.gz
tar -vzxf 2.0.0.tar.gz

wget https://github.com/adafruit/Adafruit_DHT_Unified/archive/1.0.0.tar.gz
tar -vzxf 1.0.0.tar.gz

wget https://github.com/adafruit/Adafruit_Sensor/archive/1.0.2.tar.gz
tar -vzxf 1.0.2.tar.gz

sudo mv Adafruit_DHT_Unified-1.0.0 Adafruit_Sensor-1.0.2 MySensors-2.0.0 DHT-sensor-library-1.3.0 /usr/local/share/arduino/libraries/
