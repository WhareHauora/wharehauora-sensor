# whareora-sensor

[![Build Status](https://travis-ci.org/WhareHauora/wharehauora-sensor.svg?branch=master)](https://travis-ci.org/WhareHauora/wharehauora-sensor)
[![Stories in Ready](https://badge.waffle.io/WhareHauora/wharehauora-sensor.png?label=ready&title=Ready)](https://waffle.io/WhareHauora/wharehauora-sensor)

# Dependencies

Tested on arduino 1.6.12

## Installing arduino

```
wget http://downloads.arduino.cc/arduino-1.6.12-linux64.tar.xz
tar xf arduino-1.6.12-linux64.tar.xz
sudo mv arduino-1.6.12 /usr/local/share/arduino
sudo ln -s /usr/local/share/arduino/arduino /usr/local/bin/arduino
```

## Programming a sensor

We are working with a fork of the
[sensebender|https://www.openhardware.io/view/1/Sensebender-Micro]
micro circuit. A (only slightly modified) copy of their
example arduino sketch is in `sense_bender` folder. Boards
purchased from sensebender (and assembled) then programmed
with this sketch will talk happily to the Whare Hauora cloud.

See also:
[Sensor Bender Board gitub](https://github.com/mysensors/SensebenderMicro)
