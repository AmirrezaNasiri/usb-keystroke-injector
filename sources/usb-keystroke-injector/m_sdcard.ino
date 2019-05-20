void setupSdCardComponent(){
  report("connecting to card ... ");
  if (!SD.begin(SD_CS)) {
    reportln(" [failed]");
    morse(WARN_SD_BEGIN_FAILED);
    while(1);
  }
  reportln(" [done]");
  processFile();
}

boolean processFile() {
  char filename[13];
  int payloadNumber = getPayloadNumber();
  sprintf(filename, "payload%i.txt", payloadNumber);
  report("openning: ");
  report(filename);
  myFile = SD.open(filename);
  if (!myFile) {
    reportln(" [failed]");
    morse(WARN_SD_OPEN_FAILED);
    while(1);
  }
  reportln(" [done]");
  
  while (myFile.available()) {
   char inChar = (char)myFile.read(); 
   if (strLen < (MAX_PAYLOAD_LEN - 1)) {
     strPayload[strLen] = inChar;
     strLen++;
     strPayload[strLen]   = '\0';
   }
  }
  myFile.close();
}

int getPayloadNumber() { 
  int num = 0;
  if (dip6)
    num += 1;
  if (dip5)
    num += 2;
  if (dip4)
    num += 4;
  return num;
}
