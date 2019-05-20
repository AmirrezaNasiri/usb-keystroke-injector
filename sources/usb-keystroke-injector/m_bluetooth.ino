void setupBluetoothComponent() {
  pinMode(BLUETOOTH_STATE, INPUT);
  while (!bluetoothConnected) {
    morse(WARN_WAITING_FOR_BLUETOOTH);
    if ( digitalRead(BLUETOOTH_STATE)==HIGH) {
      bluetoothConnected = true;
      reportln("bluetooth connected");
    }
  }
}

// Check the Serial port and gather any pending data 
boolean processSerial() {
  while (Serial1.available()) {
   char inChar = (char)Serial1.read(); 

   if ((inChar == '\n') || (inChar == '\r')) {
    return true;
   }
  
   if (strLen < (MAX_PAYLOAD_LEN - 1)) {
     strPayload[strLen++] = inChar;
     strPayload[strLen]   = '\0';
   }
  }

 return false;
}
