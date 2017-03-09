#!/bin/bash
set -uv

echo "Download arduino"
wget https://downloads.arduino.cc/arduino-1.6.13-linux64.tar.xz
echo "Install arduino"
tar xf arduino-1.6.13-linux64.tar.xz
sudo mv arduino-1.6.13 /usr/local/share/arduino
sudo ln -s /usr/local/share/arduino/arduino /usr/local/bin/arduino

echo "Download DHT library"
wget https://github.com/adafruit/DHT-sensor-library/archive/1.3.0.tar.gz
tar -vzxf 1.3.0.tar.gz

echo "Download MySensors"
wget https://github.com/mysensors/MySensors/archive/2.0.0.tar.gz
tar -vzxf 2.0.0.tar.gz

echo "Download Adafruit DHT unified"
wget https://github.com/adafruit/Adafruit_DHT_Unified/archive/1.0.0.tar.gz
tar -vzxf 1.0.0.tar.gz

echo "Download Adafruit unified sensor library"
wget https://github.com/adafruit/Adafruit_Sensor/archive/1.0.2.tar.gz
tar -vzxf 1.0.2.tar.gz

echo "Install libraries"
sudo mv Adafruit_DHT_Unified-1.0.0 Adafruit_Sensor-1.0.2 MySensors-2.0.0 DHT-sensor-library-1.3.0 /usr/local/share/arduino/libraries/
