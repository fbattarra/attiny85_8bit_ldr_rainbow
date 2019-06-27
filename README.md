# DigiSpark clone 8x WS2812B rainbow wheel with ambient light LED brightness adjustment
[![Watch the video](https://img.youtube.com/vi/2wXzP9xPV1U/maxresdefault.jpg)](https://youtu.be/2wXzP9xPV1U)


## Bill Of Materials:
* 1x Digispark mounting an Attiny85
* 1x 8xWS2812B rigid led bar
* 1x LDR ("5528" used in the project)
* 1x 10KΩ resistor

## Wiring Diagram
![Wiring Diagram (made with Fritzing)](https://user-images.githubusercontent.com/14162452/60257214-53070080-98d3-11e9-91a5-7275b371b019.png)

## Tested Working Development Environment:
* IDE : PlatformIO (v2.1.0, on Visual Studio Code v1.35.0)
* OS: MacOS 10.13.6 (Hig Sierra)


## Libraries/Dependencies:
* [RunningMedian](https://platformio.org/lib/show/1361/RunningMedian)
* [Adafruit NeoPixel](https://platformio.org/lib/show/28/Adafruit%20NeoPixel)


## Nice To Know:
* To upload the code, make sure to have an USB cable with every pin wired: cheap charging cables often have just +5V and ground wired
* Uploading from PlatformIO to DigiSpark needs you to plug the DigiSpark __after__ compiling, even though the console doesn't warn "now it's time to plug your DigiSpark", as Arduino IDE does.
* Quick fix for issue in uploading to DigiSpark from PlatformIO on MacOS: [PIO issue 111](https://github.com/platformio/platform-atmelavr/issues/111)
* Cheap USB chargers may provide dirty/noisy output, which could make LEDs oddly flicker expecially at low brightness: make sure to have a clean 5VDC source, or to filter adding a capacitor or a more proper circuit like this one:

[![this one:](http://andybrown.me.uk/wp-content/images//usbnoise/schematic.png)](http://andybrown.me.uk/2015/07/24/usb-filtering/)
