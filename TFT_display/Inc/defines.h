
#ifndef TM_DEFINES_H
#define TM_DEFINES_H

/**
 * @brief  This SPI pins are used on STM32F407 VET6 board
 */
// originally SPI3, PinsPack_2, CS_PIN = A15

#define ILI9341_SPI           SPI1
#define ILI9341_SPI_PINS      TM_SPI_PinsPack_1


/**
 * @brief  CS = Nss PIN for SPI, used as on STM32F407 VET6 board
 */
#define ILI9341_CS_PORT       GPIOA
#define ILI9341_CS_PIN        GPIO_PIN_4

/**
 * @brief  WRX PIN for data/command, used as on STM32F407 VET6 board
 */
#define ILI9341_WRX_PORT      GPIOD
#define ILI9341_WRX_PIN       GPIO_PIN_13

/**
 * @brief  RESET for LCD
 */
#define ILI9341_RST_PORT      GPIOD
#define ILI9341_RST_PIN       GPIO_PIN_12

//#define T_IRQ 	PIN D8  	//T_IRQ
#define T_IRQ_Pin	GPIO_PIN_8
#define T_IRQ_GPIO_Port	GPIOD

//#define T_DO 		PIN B14   	//T_MISO
#define T_DO_Pin	GPIO_PIN_14
#define T_DO_GPIO_Port	GPIOB

//#define T_DIN @ SPI2	PIN B15  	//T_MOSI
#define T_DIN_Pin	GPIO_PIN_15
#define T_DIN_GPIO_Port	GPIOB

//#define T_CLK @ SPI2	PIN B13  	//T_SCK
#define T_CLK_Pin	GPIO_PIN_13
#define T_CLK_GPIO_Port	GPIOB

//#define TCS @ SPI2 PIN B12  	//T_CS
#define T_CS_Pin	GPIO_PIN_12
#define T_CS_GPIO_Port	GPIOB



/* Put your global defines for all libraries here used in your project */

/* Change SPI3 baudrate prescaler APB2 / 2 */
/* STM32F429-Discovery board has LCD on SPI5 connected */
#define TM_SPI1_PRESCALER	SPI_BaudRatePrescaler_2

#endif
