

void setup() {
  // put your setup code here, to run once:

}
  
void loop() {
    // Checks state of Limit switch and prints out the current state of the switch
  if (digitalRead(LIMIT_SWITCH) == HIGH) {
    Serial.println("Limit switch is currently high");
  } else {
    Serial.println("Limit switch is currently low");
  }
  // Checks state of the toggle switch and prints out the current state of the switch
  if (digitalRead(TOGGLE_SWITCH) == HIGH) {
    Serial.println("Toggle switch is currently high");
  } else {
    Serial.println("Toggle switch is currently low");
  }
  // Prompts user to input a state for the motor
  if (Serial.available() > 0) {
    currentStatus = Serial.read();
    Serial.print("I received: ");
    Serial.print(currentStatus);
  } else {
    // moves motor in forward direction
    if (currentStatus == 'f') {
      digitalWrite(FORWARD_PIN, HIGH);
      Serial.println("Motor is currently moving forward");
    }
    // Stops the motor from moving
    if (currentStatus == 's') {
      digitalWrite(FORWARD_PIN, LOW);
      digitalWrite(REVERSE_PIN, LOW);
      Serial.println("Motor is currently not moving");
    }
    // moves motor in the reverse direction
    if (currentStatus == 'r') {
      digitalWrite(REVERSE_PIN, HIGH);
      Serial.println("Motor is currently moving in reverse");
    }
  }
}
