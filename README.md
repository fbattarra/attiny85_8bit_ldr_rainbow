# DigiSpark (clone) LDR Brightness Controlled 8x WS2812B Rigid Strip - Rainbow Wheel


## Bill Of Materials:
* 1x Digispark mounting an Attiny85
* 1x 8xWS2812B rigid led bar
* 1x LDR ("5528" used in the project)
* 1x 10KΩ resistor


## Tested Working Development Environment:
* IDE : PlatformIO (v2.1.0, on Visual Studio Code v1.35.0)
* OS: MacOS 10.13.6 (Hig Sierra)


## Libraries/Dependencies:
* [RunningMedian](https://platformio.org/lib/show/1361/RunningMedian)
* [Adafruit NeoPixel](https://platformio.org/lib/show/28/Adafruit%20NeoPixel)


## Nice To Know:
* Quick fix for issue in uploading to DigiSpark from PlatformIO on MacOS: [PIO issue 111](https://github.com/platformio/platform-atmelavr/issues/111)
* Cheap USB chargers may provide a dirty output which could make LEDs oddly flicker when at low brightness: make sure to have a clean 5V source (or to filter adding a capacitor or a more proper circuit like [this one](http://andybrown.me.uk/wp-content/images//usbnoise/schematic.png)) 
