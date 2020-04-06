This is simple program for testing 2.8 inch 320*240 SPI Serial TFT LCD Module Display Screen 

with Touch Panel Driver IC ILI9341, PINOUT tested on STM32F407VET6 and build with STM32CubeIDE

Display Pinout for Touch:

IRQ   Pin    D8

CS    Pin    B12

CLK   Pin    B13

SDO   Pin    B14  (MISO)

SDI   Pin    B15  (MOSI)

Display Pins:

DC    Pin    D13  (WRX)

CS    Pin    A4

RST   Pin    D12

SDI   Pin    A7   (MOSI)

SCK   Pin    A5 

Power:

LED   3.3 V

Ucc   3.3 V

GND  

If you push the touch panel on menu, you have to press on screen for some time (and not too soft) to change the state...

Only text icon in upper right corner and imagefile icon in bottom right corner of menu will respond to press...

If you want to add custom image, at first you have to convert it to C array, with help of this tool:

https://www.digole.com/tools/PicturetoC_Hex_converter.php


Example video on youtube:

https://www.youtube.com/watch?v=RWziBFmwKZ4&feature=youtu.be


Wikipage about display:

http://www.lcdwiki.com/2.8inch_SPI_Module_ILI9341_SKU:MSP2807


This is only one of many implementations and just for ilustration.

