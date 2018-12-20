const int LIMIT_SWITCH = 4;
const int TOGGLE_SWITCH = 12;
const int FORWARD_PIN = 3;
const int REVERSE_PIN = 2;
const int BAUD_RATE = 9600;

void setup() {
  pinMode(TOGGLE_SWITCH, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH, INPUT_PULLUP);
  pinMode(FORWARD_PIN, OUTPUT);
  pinMode(REVERSE_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  // Moves finger in forward direction when switch is flipped
  if (digitalRead(TOGGLE_SWITCH) == LOW) {
    analogWrite(FORWARD_PIN, 145);
    digitalWrite(REVERSE_PIN, LOW);
    Serial.println("Motor is currently moving forward");
  }
  // Retracts finger after flipping switch backwards
  if (digitalRead(TOGGLE_SWITCH) == HIGH && digitalRead(LIMIT_SWITCH) == LOW) {
    digitalWrite(REVERSE_PIN, HIGH);
    digitalWrite(FORWARD_PIN, LOW);
    Serial.println("Motor is currently moving in reverse");
  }
  // Sets motor in off state when flip is switched off and the finger is resting on the limit switch
  if (digitalRead(TOGGLE_SWITCH) == HIGH && digitalRead(LIMIT_SWITCH) == HIGH) {
    digitalWrite(FORWARD_PIN, LOW);
    digitalWrite(REVERSE_PIN, LOW);
    Serial.println("Motor is currently not moving");
  }

}
