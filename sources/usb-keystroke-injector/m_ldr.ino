void setupPhotoresistor(){
  pinMode(LDR_PIN, INPUT);
  ldrIndicator = getLdrValue();
}

int getLdrValue() {
  return analogRead(LDR_PIN) / 4;
}

int isDarkEnough(){
  ldrValue = getLdrValue();
  if (ldrValue < 0) {
    ldrReadyTries = 0;
  } else if (ldrValue <= ldrIndicator - (ldrIndicator * LDR_TOLERATE)) {
    if (ldrReadyTries == 10) {
      return true;
    } else {
      ldrReadyTries++;
    }
  } else {
    ldrReadyTries = 0;
  }
  return false;
}
