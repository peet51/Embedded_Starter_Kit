#include "stm32f4xx.h"
#include "drivers/LEDs.h"
#include "drivers/Buttons.h"
#include "drivers/USART.h"
#include "drivers/peripheral_pinout.h"
#include "drivers/PWM_controller_PCA9685PW.h"
#include "drivers/DISPLAY_WH1602B_4Bit.h"
#include "drivers/clock_config.h"
#include "drivers/MEMS.h"

uint8_t cycle = 4;
int main(void)
{
	Display_clear();
	MEMS_example_with_menu();

}
