void morse(int number) {
  if (number == 0) {
    blinkLED(40);
  } else if (number == 1) {
    
  } else {
    digitalWrite( LED, HIGH );
    delay( MORSE_UNIT_LENGTH * 4 );
    digitalWrite( LED, LOW );
    for (int i = 0; i <= number; i++) {
      digitalWrite( LED, HIGH );
      delay( MORSE_UNIT_LENGTH );
      digitalWrite( LED, LOW );
      delay( MORSE_UNIT_LENGTH );
    }
  }
}
void dot(){
  digitalWrite( LED, HIGH );
  delay( MORSE_UNIT_LENGTH );
  digitalWrite( LED, LOW );
  delay( MORSE_UNIT_LENGTH );
}
void dash(){
  digitalWrite( LED, HIGH );
  delay( MORSE_UNIT_LENGTH*3 );
  digitalWrite( LED, LOW );
  delay( MORSE_UNIT_LENGTH );
}
void gap(){
  delay( MORSE_UNIT_LENGTH*3 );
}
