#include <Arduino.h>

/*
  Fabio Battarra [www.battarra.it] - June 2019
*/

#include <Adafruit_NeoPixel.h>
#include <RunningMedian.h>

// pixels
#define LED_PIN 0         // P0 on DigiSpark
#define LED_TYPE NEO_RGB  // WS2812
#define LEDS 8            // number of addressable leds
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, LED_PIN, LED_TYPE);

// LDR
#define LDR_PIN 1         // P2 on DigiSpark (5528 LDR + 10KΩ pullup)
#define LDR_READINGS 10   // readings for running medians
RunningMedian ldrSamples = RunningMedian(LDR_READINGS);

#define WHEEL_SPEED 10   // rainbow cycling speed

// indexes for boundaries' arrays (lower and upper values)
#define DARK 0
#define BRIGHT 1
// I/O boundaries ([0] = dark, [1] = bright environment)
const int arLdrBoundaries[] = {20, 950};
const int arLedBoundaries[] = {15, 255};

int arLedBrightness[] = {0,0};    // stores past ([0]) and current ([1]) brightness values

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(arLedBrightness[0]);
}

int getLdrSmoothedValue(int ldrReading){
  ldrSamples.add(constrain(ldrReading,arLdrBoundaries[DARK],arLdrBoundaries[BRIGHT]));
  return ldrSamples.getMedian();
}

uint32_t getWheel(byte WheelPos) {
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

void setStripBrightness(int ldrValue){
  arLedBrightness[1] = map(ldrValue, arLdrBoundaries[DARK], arLdrBoundaries[BRIGHT], arLedBoundaries[DARK], arLedBoundaries[BRIGHT]);

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

void rainbowCycle(int cycleSpeed) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i< strip.numPixels(); i++) {
      setStripBrightness(getLdrSmoothedValue(analogRead(LDR_PIN)));
      strip.setPixelColor(i, getWheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(cycleSpeed);
  }
}

void loop() {
  rainbowCycle(WHEEL_SPEED);
}
