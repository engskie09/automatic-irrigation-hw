#include <Servo.h>

const int moistureSensorPin = A0;
float moistureValue;
float moisturePercentage;

// thresholds
float maxAnalogValue = 539.00;

char* const getMoisture() {
  moistureValue = analogRead(moistureSensorPin);
  moisturePercentage = (moistureValue / maxAnalogValue)*100;

  Serial.print(moisturePercentage);
  Serial.println('%');

  Serial.println("moistureValuev");
  Serial.println(moistureValue);
  
  Serial.println("moisturePercentage");
  Serial.println(moisturePercentage);
  
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");
  Serial.println("--------------DIVIDER--------------");
  Serial.println("--------------DIVIDER--------------");
  Serial.println("--------------DIVIDER--------------");
  Serial.println("-----------------------------------");
  Serial.println("-----------------------------------");

  if (moisturePercentage > 70.00) {
    return ("WET");
  } else if (moisturePercentage < 30.00) {
    return ("DRY");
  } else {
    return ("MILD");
  }
}

const bool OPEN_GATE = false;
const int GATE_PIN = 2;
Servo gateServo;
int pos = 0;

void initGate() {
  pinMode(GATE_PIN, OUTPUT);
  gateServo.attach(9, 500, 2500);
}

void openGate() {
  digitalWrite(GATE_PIN, HIGH);
}

void closeGate() {
  digitalWrite(GATE_PIN, LOW);
}

void setup(){
  initGate();
  Serial.begin(9600);
}

void loop() {
  char* const humidity = getMoisture();

  if (humidity == "DRY" || humidity == "MILD") {
    openGate();
  } else if (humidity == "WET") {
    closeGate();
  }

  delay(500);

  for (pos = 0; pos <= 360; pos += 1) {
    gateServo.write(pos);
  }
}
