// Smart Home Automation and Security System

// Pin definitions
const int PIR_PIN = 4;
const int LDR_PIN = 3;

const int RELAY1 = 7;
const int RELAY2 = 8;

const int BUZZER = 9;
const int RED_LED = 10;
const int GREEN_LED = 11;

void setup() {
  // Input pins
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);

  // Output pins
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Start with outputs OFF
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(BUZZER, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  Serial.begin(9600);

  Serial.println("Smart Home System Started");
}

void loop() {

  // Read sensors
  int motion = digitalRead(PIR_PIN);
  int lightStatus = digitalRead(LDR_PIN);

  // Print sensor values
  Serial.print("PIR: ");
  Serial.print(motion);
  Serial.print(" | LDR: ");
  Serial.println(lightStatus);

  // -------- LDR AUTOMATIC LIGHT --------
  // The logic may need to be reversed depending on your LDR module
  if (lightStatus == LOW) {
    // Darkness detected
    digitalWrite(RELAY1, LOW);
    Serial.println("Dark - Light ON");
  } else {
    // Bright environment
    digitalWrite(RELAY1, HIGH);
    Serial.println("Bright - Light OFF");
  }

  // -------- PIR SECURITY SYSTEM --------
  if (motion == HIGH) {
    Serial.println("MOTION DETECTED!");

    digitalWrite(RED_LED, HIGH);
    digitalWrite(RELAY2, LOW);

    tone(BUZZER, 1000);
    delay(500);
    noTone(BUZZER);

  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY2, HIGH);
  }

  delay(500);
}
