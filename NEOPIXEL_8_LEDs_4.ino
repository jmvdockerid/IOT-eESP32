/*
ESP module: ESP-WROOM-32
Getest met: Arduino IDE
Sensor: LED strip van 8 LEDs WS2812B ;
Doel: willekeurige kleuren weergeven ;
Specs: I2C, 5V ;
Aansluiten (van sensor naar ESP)
5V naar 5V
GND naar GND
DIN naar GPIO 16
*/

#include <Adafruit_NeoPixel.h>

#define LED_PIN   16
#define LED_COUNT 8

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  strip.begin();           
  strip.show(); // Initialize all pixels to 'off'           
  strip.setBrightness(30); 
}

void loop() {
  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, random(255), random(255), random(255), 0); //(n, red, green, blue)
    strip.show();
    delay(50);
  }
  for(int i = strip.numPixels()-1; i >= 0; i--){
    strip.setPixelColor(i, 0, 0, 0, 0);
    strip.show();
    delay(50);
  }
}

// more info: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
