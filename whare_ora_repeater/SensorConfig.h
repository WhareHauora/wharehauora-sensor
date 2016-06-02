//int nodeId = 99;
#define TIME_BETWEEN_SOIL_READINGS 500

#define LED_DISPLAY_TIME 3000 // time to leave LEDs up

#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1
#define CHILD_ID_SOIL 2

// The 3x leds, can recieve commands remotely.
#define CHILD_ID_LED_T 3
#define CHILD_ID_LED_H 4
#define CHILD_ID_LED_P 5

#define CHILD_ID_BUTTON 6

#define HUMIDITY_SENSOR_DIGITAL_PIN 4
#define SOIL_PIN_1 5
#define SOIL_PIN_2 6
#define SOIL_SENSOR_PIN A0
#define NEOPIXELS_PIN 8
#define PUSHBUTTON_PIN 7

// the order on the wire, to find each neopixel
#define NEOPIXEL_LED_T 0
#define NEOPIXEL_LED_H 1
#define NEOPIXEL_LED_P 2

#define NODE_ID 52
#define REPEATER_MODE_ON true
