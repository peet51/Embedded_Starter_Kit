This is simple program for testing 2.8 inch 320*240 SPI Serial TFT LCD Module Display Screen 



PINOUT tested on STM32F407VET6 and build with STM32CubeIDE, Touch Pins are not used.

This example draws circle filled with random color and on random x,y position of screen

Example shows basic drawing routines for display using ILI 9341 driver and SPI communication.


There is short video-example  "TFT_display_test[1].mp4" in this folder. 

If you want to play it, you have to download it first and then play it locally.


Display Pinout:

SPI1 Pins (Fastest bandwidth 42Mbit/s from SPIx on STM32F4xx)

SDI   Pin    A7   (MOSI)

SDO   Pin    A6   (MISO)  

SCK   Pin    A5  

CS    Pin    A4

DC    Pin    D13  (WRX)

RST   Pin    D12

Power:

LED   3.3 V

Ucc   3.3 V

GND  


Display Pinout for Touch:

IRQ   Pin    D8

CS    Pin    B12

CLK   Pin    B13

SDO   Pin    B14  (MISO)

SDI   Pin    B15  (MOSI)
