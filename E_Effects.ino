//############################################################################################################################################################
//ColorWipe - FASTLED
//############################################################################################################################################################
void colorWipe(uint32_t rc, uint32_t gc, uint32_t bc, uint8_t wait) {
 int i;
 FastLED.setBrightness(BRIGHTNESS);
    for(int i = 0; i < NUM_LEDS; i++) {
      //leds[i].setHSV(c, 200, 200);
      leds[i] = CRGB( rc, gc, bc);
      delay(wait);
      FastLED.show();
    }
    
}

//############################################################################################################################################################
//Sineflow - Create smooth Transition
//############################################################################################################################################################
void sineflow()
{
  FastLED.setBrightness(BRIGHTNESS);
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB( rsin, gsin, bsin);
    }
    FastLED.show();
}




//############################################################################################################################################################
//cylon - FASTLED - LED sweeps back and forth, with the color, delay and number of cycles of your choice 
//############################################################################################################################################################
void cylon(CRGB color, uint16_t wait, uint8_t number_of_cycles)
{
  FastLED.setBrightness(BRIGHTNESS);
  for (uint8_t times = 0; times<=number_of_cycles; times++)
  {
    // Make it look like one LED is moving in one direction
    for(int led_number = 0; led_number < NUM_LEDS; led_number++)
    {
      //Apply the color that was passed into the function
      leds[led_number] = color;
      //Actually turn on the LED we just set
      FastLED.show();
      // Turn it back off
      leds[led_number] = CRGB::Black;
      // Pause before "going" to next LED
      delay(wait);
    }
    // Now "move" the LED the other direction
    for(int led_number = NUM_LEDS-1; led_number >= 0; led_number--)
    {
      //Apply the color that was passed into the function
      leds[led_number] = color;
      //Actually turn on the LED we just set
      FastLED.show();
      // Turn it back off
      leds[led_number] = CRGB::Black;
      // Pause before "going" to next LED
      delay(wait);
    }
  }
  return;
}
//############################################################################################################################################################
//rainbow - FASTLED -
//############################################################################################################################################################
void rainbow() 
{
  FastLED.setBrightness(BRIGHTNESS);
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  FastLED.show();
}
 //############################################################################################################################################################
//rainbow2 - FASTLED -
//############################################################################################################################################################
void rainbow2(int brightness, int speed, int width, int direction, int pairOfLeds) {
  /* Helligkeit(brightness)                   0 - 100%          0 - 255
   * Geschwindigkeit(speed)          langsam - schnell            1 - 5
   * Farbabstufungen(width)               eine - viele            0 - x
   * Richtung(direction)                  o <<<< Links                0
   *                                     >>>> o Rechts                1
   *                                   <<o>> Explosion                2
   *                                   >>o<< Implosion                3
   * Anzahl Leds einer Farbe(pairOfLeds)         1 - x            1 - x */

  const int MIN_DURATION = 1E3;
  const int MAX_DURATION = 3E4;
  const int MIN_SPEED = 1;
  const int MAX_SPEED = 5;
  const int SATURATION = 255;

  if (speed < MIN_SPEED) speed = MIN_SPEED;
  else if (speed > MAX_SPEED) speed = MAX_SPEED;
  long duration = (speed - MIN_SPEED) * (MIN_DURATION - MAX_DURATION) / (MAX_SPEED - MIN_SPEED) + MAX_DURATION;

  int numLeds = NUM_LEDS / pairOfLeds;
  if (pairOfLeds > 1) width = width / pairOfLeds;
  int hue[NUM_LEDS];
  int shift = (255 * millis() / duration) % 255;

  if (direction <= 0) {
    for (int i = 0; i < numLeds; i++) hue[i] = (i * 255 / width + shift) % 255;
  }
  else if (direction == 1) {
    for (int i = 0; i < numLeds; i++) hue[numLeds - 1 - i] = (i * 255 / width + shift) % 255;
  }
  else if (direction == 2) {
    if (numLeds % 2 == 0) {
      for (int i = 0; i < numLeds; i++) {
        if (i < numLeds / 2) hue[i] = (i * 255 / width + shift) % 255;
        else hue[i] = ((numLeds - 1 - i) * 255 / width + shift) % 255;
      }
    }
    else {
      for (int i = 0; i < numLeds; i++) {
        if (i <= numLeds / 2) hue[i] = (i * 255 / width + shift) % 255;
        else hue[i] = ((numLeds - 1 - i) * 255 / width + shift) % 255;
      }
    }
  }
  else {
    if (numLeds % 2 == 0) {
      for (int i = 0; i < numLeds; i++) {
        if (i < numLeds / 2) hue[i] = ((numLeds - 1 - i) * 255 / width + shift) % 255;
        else hue[i] = (i * 255 / width + shift) % 255;
      }
    }
    else {
      for (int i = 0; i < numLeds; i++) {
        if (i <= numLeds / 2) hue[i] = ((numLeds - 1 - i) * 255 / width + shift) % 255;
        else hue[i] = (i * 255 / width + shift) % 255;
      }
    }
  }

  // Leds setzen
  for (int i = 0; i < numLeds; i++) {
    int led = i*pairOfLeds;
    leds[led] = CHSV(hue[i], SATURATION, brightness);
    // Wenn "pairOfLeds" > 1 ist, setzte die benachbarten Leds
    for (int j = 1; j < pairOfLeds; j++) leds[led + j] = CHSV(hue[i], SATURATION, brightness);
  }
  FastLED.show();
}

//############################################################################################################################################################
//confetti()  - FASTLED -
//############################################################################################################################################################
void confetti() 
{
  FastLED.setBrightness(BRIGHTNESS);
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), random8(64), random8(64));
  FastLED.show();
}

//############################################################################################################################################################
//sinelon()  - FASTLED -
//############################################################################################################################################################
void sinelon()
{
  FastLED.setBrightness(BRIGHTNESS);
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin8(13,0,NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
  FastLED.show();
}

//############################################################################################################################################################
//juggle()  - FASTLED -
//############################################################################################################################################################
void juggle() {
  FastLED.setBrightness(BRIGHTNESS);
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
  FastLED.show();
}




//############################################################################################################################################################
//ledsHeartbeatRandomColor  - FASTLED -
//############################################################################################################################################################
void ledsHeartbeatRandomColor(uint8_t saturation, uint8_t brightness, uint32_t duration)
{
  const uint8_t patternHeartbeat[56] =
  {
    0, 0, 0, 0, 1, 2, 3, 4,
    5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 15, 14, 13, 12,
    11, 10, 9, 8, 7, 6, 5, 4,
    3, 2, 1, 0, 0, 0, 0, 0
  };
  bool oddLeds = NUM_LEDS % 2;
  uint8_t ledFactor[NUM_LEDS];
  static uint8_t hue;

  for (int led = 0; led <= NUM_LEDS / 2; led++)
  {
    ledFactor[led] = map(led + 1, 1, (NUM_LEDS / 2), 1, 17);
    if (!oddLeds)
    {
      ledFactor[NUM_LEDS / 2] = 17; /* map befehl umschreiben!!!*/
    }
    ledFactor[NUM_LEDS - 1 - led] = map(led + 1, 1, (NUM_LEDS / 2), 1, 17);
  }

  static uint32_t lastMillis;
  static uint8_t ctPattern;
  if (millis() - lastMillis >= duration)
  {
    lastMillis = millis();
    ctPattern++;
    if (ctPattern >= 56)
    {
      ctPattern = 0;
      hue = millis() % 255;
    }
    for (int led = 0; led < NUM_LEDS; led++)
    {
      leds[led] = CHSV(hue, saturation, brightness * (ledFactor[led] * patternHeartbeat[ctPattern]) / 255);
    }
    FastLED.show();
  }
}

//############################################################################################################################################################
//Explosion()  - FASTLED -
//############################################################################################################################################################
void explosion(byte ledcount,byte rainbowWidth,byte sat, unsigned int duration) {
  FastLED.setBrightness(BRIGHTNESS);
  memset(leds,0,ledcount*3);
  byte hue[NUM_LEDS];
  // Farbverschiebung
  byte colorshift = (255*millis()/duration)%255;
  for(int i = 0; i < ledcount; i++) {
    hue[i] = (i*255/rainbowWidth+colorshift)%255;
  }
  // Farbton nach links verschieben (3 2 1 -> 4 3 2)
  for(int led = 0; led < ledcount/2; led++) {
    leds[led] = CHSV(hue[led], sat, 100);
  }
  // Gerade Anzahl Leds
  // Farbton nach rechts verschieben (1 2 3 -> 4 3 2)
  if(ledcount%2 == 0) {
    for(int led = ledcount/2; led < ledcount; led++) {
      leds[led] = CHSV(hue[ledcount-led], sat, 100);
    }
  }
  // Ungerade Anzahl Leds
  // Farbton nach rechts verschieben (1 2 3 -> 4 3 2)
  else { 
    for(int led = (ledcount/2)+1; led < ledcount; led++) {
      leds[led] = CHSV(hue[(ledcount-1)-led], sat, 100);
    }
    // Farbton nach links und rechts verschieben (2 1 2 -> 3 2 3)
    leds[(ledcount/2)] = CHSV(hue[(ledcount/2)], sat, 100);
  }
  FastLED.show();
}

//############################################################################################################################################################
//implosion()  - FASTLED -
//############################################################################################################################################################
void implosion(byte ledcount,byte rainbowWidth,byte sat, unsigned int duration) {
  FastLED.setBrightness(BRIGHTNESS);
  memset(leds,0,ledcount*3);
  byte hue[NUM_LEDS];
  // Farbverschiebung
  byte colorshift = (255*millis()/duration)%255;
  for(int i = 0; i < ledcount; i++) {
    hue[i] = (i*255/rainbowWidth+colorshift)%255;
  }
  // Farbton nach rechts verschieben (3 2 1 -> 2 3 4)
  for(int led = 0; led < ledcount/2; led++) {
    leds[led] = CHSV(hue[(ledcount/2)-led], sat, 100);
  }
  // Farbton nach links verschieben (3 2 1 -> 2 1 4)
  for(int led = ledcount/2; led < ledcount; led++) {
    leds[led] = CHSV(hue[led-(ledcount/2)], sat, 100);
  }
  FastLED.show();
}

//############################################################################################################################################################
//------ wettersimu
//############################################################################################################################################################
void wettersimu() {
  uint8_t hue = random(0x00,0xFF);
  uint8_t saturation = 0xFF;
  uint8_t brightness = 0xFF; // 0 -15
  uint8_t interval = random(0x10,0x50);
  uint8_t patternHeartbeat[0x30] = {
    0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, // 0x10
    8, 8, 9, 9, 8, 7, 6, 5, 4, 5, 6, 7, 8, 9, 9, 8, // 0x20
    8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, // 0x30
  };
  uint8_t ledFactor[NUM_LEDS];

  static bool init;
  if (!init) {
    for (int led = 0; led < NUM_LEDS / 2; led++) {
      ledFactor[led] = led+2;
      ledFactor[led] = map(led, 0, NUM_LEDS / 2, 0, 26/*28 + (brightness - 15)*/)+2;
      ledFactor[(NUM_LEDS - 1) - led] = map(led, 0, NUM_LEDS / 2, 0, 26/*28 + (brightness - 15)*/)+2;
      ledFactor[(NUM_LEDS - 1) - led] = led+1;
    }
    init = false;
  }

  static uint32_t lastMillis;
  static uint8_t ctPattern;
  if (millis() - lastMillis >= interval) {
    ctPattern++;
    if (ctPattern >= 0xFF) {
      ctPattern = random(100,255);
    }
    for (int led = 0; led < NUM_LEDS; led++) {
      leds[led] = CHSV(hue, saturation, ledFactor[led] * patternHeartbeat[ctPattern]);
    }
    FastLED.show();
    lastMillis = millis();
  }
}

//############################################################################################################################################################
//LarsonScanner  - FASTLED -
//############################################################################################################################################################
void larsonScanner(byte ledcount, byte hue, byte sat, byte duration) {
  FastLED.setBrightness(BRIGHTNESS);
  static unsigned long previousMillis = millis();
  static int i; // Schrittzaehler
  static int led = 0;
  static boolean reverse = false;
  byte dim;
  if(i > 32) {
    i = 0;
    if (reverse) led--; 
    else led++;
    // Anfang erreicht
    if (led < 0) {
      led = 0; 
      reverse =! reverse;
    }
    // Ende erreicht
    if (led >= ledcount) {
      led = ledcount-1; 
      reverse =! reverse;
    }
  }
  if (millis()-previousMillis > duration) {
    previousMillis = millis();
    memset(leds, 0, ledcount*3); // LED Array zuruecksetzen
    dim = i*4;
    i++;
    // Aktuelle Led-2
    if (led-2>=0 && !reverse) {
      leds[led-2] = CHSV(hue, sat, 128-dim); // FadeDown
    } 
    else if (led-2>=0 && reverse) {
      leds[led-2] = CHSV(hue, sat, dim); // FadeUp
    }
    // Aktuelle Led-1
    if (led-1>=0 && !reverse) {
      leds[led-1] = CHSV(hue, sat, 255-dim); // FadeDown
    }
    else if (led-1>=0 && reverse) {
      leds[led-1] = CHSV(hue, sat, 127+dim); // FadeUp
    }
    // Aktuelle Led
    leds[led] = CHSV(hue, sat, 255); 
    // Aktuelle Led+1
    if (led+1<ledcount && !reverse) {
      leds[led+1] = CHSV(hue, sat, 127+dim); // FadeUp
    }
    else if (led+1<ledcount && reverse) {
      leds[led+1] = CHSV(hue, sat, 255-dim); // FadeDown
    }
    // Aktuelle Led+2
    if (led+2<ledcount && !reverse) {
      leds[led+2] = CHSV(hue, sat, dim); // FadeUp
    }
    else if (led+2<ledcount && reverse) {
      leds[led+2] = CHSV(hue, sat, 128-dim); // FadeDown
    }
    FastLED.show(); 
  }
}

