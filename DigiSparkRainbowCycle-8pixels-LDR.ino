/*
  05/06/2019
  Fabio Battarra - www.battarra.it
*/
#include <Adafruit_NeoPixel.h>

#define LED_PIN 0 // P0 on DigiSpark
#define N_LEDS 8  // number of addressable leds used
#define LED_TYPE NEO_RGB // WS2812B

#define LDR_PIN 1  // 5528 LDR + 10KΩ pullup (pin "P2" on DigiSpark)
#define V_DARK 0   // "dark index" in ar[Ldr/Led]Threshold
#define V_BRIGHT 1 // "bright index" in ar[Ldr/Led]Threshold
const int arLdrThreshold[] = {100, 900}; // LDR boundaries for dark ([0]) and bright ([1]) environments
const int arLedThreshold[] = {25, 255};  // LED brightness boundaries for dark ([0], min) and bright ([1], max) environments

int arLedBrightness[] = {0,0}; // used to store previous [0] and current [1] led brightness

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, LED_PIN, LED_TYPE);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(arLedBrightness[0]);
}

void loop() {
  rainbowCycle(10);
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i< strip.numPixels(); i++) {
      adjStripBrightness(analogRead(LDR_PIN));
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void adjStripBrightness(int ldrValue){
  arLedBrightness[1] = map(constrain(ldrValue,arLdrThreshold[V_DARK], arLdrThreshold[V_BRIGHT]), arLdrThreshold[V_DARK], arLdrThreshold[V_BRIGHT], arLedThreshold[V_DARK], arLedThreshold[V_BRIGHT]);

  if(int brightDiff = abs(arLedBrightness[1] - arLedBrightness[0]) > 1 ){
    for(int i= 0; i <= brightDiff; i++){
      if(arLedBrightness[1] > arLedBrightness[0])
        arLedBrightness[0] ++;
      else
        arLedBrightness[0] --;
        
      strip.setBrightness(arLedBrightness[0]);
    }
  }
}
