# DigiSpark (clone) LDR Brightness controlled 8x WS2812B rigid strip, with Adafruit NeoPixel


##Bill of materials:
* 1x Digispark mounting an Attiny85
* 1x 8xWS2812B rigid led bar
* 1x LDR ("5528" used in the project)
* 1x 10KΩ resistor


##Tested working development environment
* IDE : PlatformIO (v2.1.0, on Visual Studio Code v1.35.0)
* OS: MacOS 10.13.6 (Hig Sierra)


##Libraries/Dependencies:
* [RunningMedian](https://platformio.org/lib/show/1361/RunningMedian)
* [Adafruit NeoPixel](https://platformio.org/lib/show/28/Adafruit%20NeoPixel)


##Nice to know:
* Quick fix for issue in uploading to DigiSpark from PlatformIO on MacOS: [PIO issue 111](https://github.com/platformio/platform-atmelavr/issues/111)
* Cheap USB chargers may provide a dirty output which could make LEDs oddly flicker when at low brightness: make sure to have a clean 5V source (or to filter adding a capacitor or a more proper circuit like [this one](http://andybrown.me.uk/wp-content/images//usbnoise/schematic.png)) 
