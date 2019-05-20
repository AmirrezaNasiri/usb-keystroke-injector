void setupDipComponent() {
  pinMode(DIP_EMULATE, INPUT_PULLUP);
  pinMode(DIP_DEBUG, INPUT_PULLUP);
  pinMode(DIP_MODE, INPUT_PULLUP);
  pinMode(DIP_4, INPUT_PULLUP);
  pinMode(DIP_5, INPUT_PULLUP);
  pinMode(DIP_6, INPUT_PULLUP);

  emulate = isDipOn(DIP_EMULATE);
  debug = false;//isDipOn(DIP_DEBUG);
  mode = isDipOn(DIP_MODE) ? 's' : 'b'; 
  dip4 = isDipOn(DIP_4);
  dip5 = isDipOn(DIP_5);
  dip6 = isDipOn(DIP_6);
  

  if (!emulate) {
    reportln("[x] emulation is toggeled off.");
    morse(WARN_EMULATION_OFF);
    while(true);
  }
}

boolean isDipOn(int pin) {
  return !digitalRead(pin);
}

#if DEBUG_DIP
void handleDebugDIP() {
  char text[50];
  reportln("DIP debug result:");

  // Emulation
  sprintf (text, "emulate switch [@%i]: ", DIP_EMULATE);
  Serial.print(text);
  Serial.println( emulate ? "on" : "off" );

  // debug switch
  sprintf (text, "debug switch [@%i]: ", DIP_DEBUG);
  Serial.print(text);
  Serial.println( debug ? "on" : "off" );

  // Mode
  sprintf (text, "input mode switch [@%i]: ", DIP_MODE);
  Serial.print(text);
  switch(mode) {
    case 's':
      Serial.println("sd-card");
      break;
    case 'b':
      Serial.println("bluetooth");
      break;
    default:
      Serial.println("[NOT_SET]");
      break;      
  }

  // dip 4 option switch
  sprintf (text, "dip4 option switch [@%i]: ", DIP_4);
  Serial.print(text);
  Serial.println( dip4 ? "on" : "off" );

  // dip 5 option switch
  sprintf (text, "dip5 option switch [@%i]: ", DIP_5);
  Serial.print(text);
  Serial.println( dip5 ? "on" : "off" );

 // dip 6 option switch
  sprintf (text, "dip6 option switch [@%i]: ", DIP_6);
  Serial.print(text);
  Serial.println( dip6 ? "on" : "off" );

  Serial.println("debug done. will terminate.");
  while(1);
}
#endif
