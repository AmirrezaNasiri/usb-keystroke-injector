/**
 * Report to monitoring serial with newline
 */
void reportln(char* message) {
  if (bluetoothConnected == true) {
    Serial1.println( message );
  } else if (Serial) {
    Serial.println(message);
  }
}

/**
 * Report to monitoring serial without newline
 */
void report(char* message) {
  if (bluetoothConnected == true) {
    Serial1.print( message );
  } else if (Serial) {
    Serial.print(message);
  }
}

void toggleLED() {
  digitalWrite(LED, !digitalRead(LED));
}

void blinkLED(int d) {
  digitalWrite(LED, HIGH);
  delay(d);
  digitalWrite(LED, LOW);
  delay(d);
}

boolean charsAre(char* first, char* second){
  return strcmp(first, second) == 0;
}

void resetPayload() {
  strPayload[0] = '\0';
  strLen        = 0; 
}
