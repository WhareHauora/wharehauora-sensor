void setupSoilSensor() {
      //Set up soil pins
  pinMode(SOIL_PIN_1, OUTPUT);
  pinMode(SOIL_PIN_2, OUTPUT);
  pinMode(SOIL_SENSOR_PIN, INPUT);

}

void setSensorPolarity(boolean flip)
{
  if (flip)
  {
    digitalWrite(SOIL_PIN_1, HIGH);
    digitalWrite(SOIL_PIN_2, LOW);
  }
  else
  {
    digitalWrite(SOIL_PIN_1, LOW);
    digitalWrite(SOIL_PIN_2, HIGH);
  }
}




