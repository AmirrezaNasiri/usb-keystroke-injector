#include <SoftwareSerial.h>;
#include <SPI.h>
#include <SD.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "a_globals.h"


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  setupDipComponent();
  #if DEBUG_DIP == true
    morse(WARN_WAITING_FOR_SERIAL);
    while (!Serial);
    handleDebugDIP();
  #endif
  if (!emulate) {
    morse(WARN_EMULATION_OFF);
    reportln("[x] emulation mode is off.");
    while(true);
  }

  if (debug) {
    reportln("debug is on. waiting for bluetooth connection ...");
    setupBluetoothComponent();
  }

  switch (mode) {
    case 'b':
      if (!bluetoothConnected)
        setupBluetoothComponent();
    break;
    case 's':
      setupSdCardComponent();
    break;
  }

  setupKeyboardAndMouseComponent();

  setupPhotoresistor();
  
  reportln("setup done.");
}


void loop() {
  switch (mode) {
    case 'b':
      if (!bluetoothConnected)
        setupBluetoothComponent();
      resetPayload();
        if (processSerial()) {
          report(strPayload);
          type(strPayload);
          resetPayload();
          reportln(" [done]");
        }
      break;
      
    case 's':
      line = strtok(strPayload, "\n");
      while (line != NULL)
      {
        if (charsAre(line, "{LDR}")) {
          if (!bluetoothConnected)
            setupBluetoothComponent();
          char text[65];
          sprintf (text, "waiting for darkness: indicator: %i, tolerate: %f ...", ldrIndicator, LDR_TOLERATE);
          reportln(text);
          while(!isDarkEnough()) {
            sprintf (text, "progress %i, value %i", ldrReadyTries, ldrValue);
            reportln(text);
            delay(LDR_WAIT);
          }
          reportln("room is dark enough. proceeding ...");
        } else {
          report(line);
          type(line);
          reportln(" [done]");
        }
        line = strtok(NULL, "\n");
      }
      mode = 'b';
      reportln("[x] sd operation done. switched to bluetooth.");
      //Keyboard.end();
      //while(1);
      break;
  }
  delay(400);
}
