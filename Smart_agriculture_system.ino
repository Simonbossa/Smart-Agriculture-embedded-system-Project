const int soilMoistureSensorPin = 34; // Analog pin connected to the soil moisture sensor
const int buzzerPin = 25; // Digital pin connected to the buzzer
const int moistureThreshold = 2000; // Threshold value for soil moisture (adjust as needed)

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  int soilMoistureValue = analogRead(soilMoistureSensorPin); // Read the soil moisture value
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  if (soilMoistureValue < moistureThreshold) {
    Serial.println("Soil is too dry! Water the plant.");
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    delay(1000); // Buzz for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  } else {
    Serial.println("Soil moisture level is adequate.");
  }

  delay(5000); // Wait for 5 seconds before the next reading
}
