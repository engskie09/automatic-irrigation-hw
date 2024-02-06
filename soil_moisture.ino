const int moistureSensorPin = A0;
float moistureValue;
float moisturePercentage;

// thresholds
float maxAnalogValue = 539.00;
float minWetPercentage = 70.00;

void setup(){
  Serial.begin(9600);
}

void loop() {
  delay(500);

  moistureValue = analogRead(moistureSensorPin);
  moisturePercentage = (moistureValue/maxAnalogValue)*100;

  Serial.print(moisturePercentage);
  Serial.println('%');

  Serial.println("moisturePercentage");
  Serial.println(moisturePercentage);

  Serial.println("minWetPercentage");
  Serial.println(minWetPercentage);;
  
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");

  if (moisturePercentage>minWetPercentage) {
    Serial.println("Wet");
  }
  else {
    Serial.println("Dry");
  }

  delay(500);
}