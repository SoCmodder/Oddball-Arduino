#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define PIN2       7
#define PIN3       8

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel eye2(NUMPIXELS, PIN2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel eye3(NUMPIXELS, PIN3, NEO_RGB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  eye2.begin();
  eye3.begin();
}

void loop() {
  fireEffectBlue();
  fireEffectBlueEye2();
  fireEffectForehead();
}

// https://codebender.cc/sketch:271084#Neopixel%20Flames.ino
void fireEffectBlue() {  
  //  Blue flame:
  int r = 0, g = 21, b = 156;

  //  Flicker, based on our initial RGB values
  for(int i=0; i<pixels.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    pixels.setPixelColor(i,r1,g1, b1);
  }
  pixels.show();

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(10,113));
}

void fireEffectBlueEye2() {  
  //  Red Flame:
  int r = 156, g = 0, b = 0;

  //  Flicker, based on our initial RGB values
  for(int i=0; i<eye2.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    eye2.setPixelColor(i,r1,g1, b1);
  }
  eye2.show();

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(10,113));
}

void fireEffectForehead() {  
  //  Blue flame:
  int r = 0, g = 21, b = 156;
  eye3.setPixelColor(0, r, g, b);
  eye3.show();

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(10,113));
}

void fireEffectRed() {
  //  Red Flame:
  int r = 156, g = 0, b = 0;

  //  Flicker, based on our initial RGB values
  for(int i=0; i<pixels.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    pixels.setPixelColor(i,r1,g1, b1);
  }
  pixels.show();

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(10,113));
}
