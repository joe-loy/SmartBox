const int LIMIT_SWITCH = 4;
const int TOGGLE_SWITCH = 12;
const int FORWARD_PIN = 3;
const int REVERSE_PIN = 2;
const int BAUD_RATE = 9600;
unsigned long currTime;
unsigned long prevTime;
const int INTERVAL = 1000; // Time interval in ms of how long the finger waits after hitting the switch

void setup() {
  pinMode(TOGGLE_SWITCH, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH, INPUT_PULLUP);
  pinMode(FORWARD_PIN, OUTPUT);
  pinMode(REVERSE_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  currTime = millis();
  // Moves finger in forward direction when switch is flipped
  if (digitalRead(TOGGLE_SWITCH) == LOW) {
    prevTime = currTime;
    digitalWrite(FORWARD_PIN, HIGH);
    digitalWrite(REVERSE_PIN, LOW);
    Serial.println("Motor is currently moving forward");
  }
  if (digitalRead(TOGGLE_SWITCH) == HIGH && digitalRead(LIMIT_SWITCH) == LOW) {
    // Makes finger wait for a second after the switch becomes flipped
    if (currTime - prevTime < INTERVAL) {
      digitalWrite(REVERSE_PIN, LOW);
      digitalWrite(FORWARD_PIN, LOW);
    } else { // Retracts finger after the finger has waited for a second
      digitalWrite(REVERSE_PIN, HIGH);
      digitalWrite(FORWARD_PIN, LOW);
      Serial.println("Motor is currently moving in reverse");
    }
  }
  // Sets motor in off state when flip is switched off and the finger is resting on the limit switch
  if (digitalRead(TOGGLE_SWITCH) == HIGH && digitalRead(LIMIT_SWITCH) == HIGH) {
    prevTime = currTime;
    digitalWrite(FORWARD_PIN, LOW);
    digitalWrite(REVERSE_PIN, LOW);
    Serial.println("Motor is currently not moving");
  }
}
