#include "drivers\glesk_ex_humid.h"

#define EX_HUMID_PIN	GPIO_Pin_11
#define EX_HUMID_PORT	GPIOD
#define EX_HUMID_PCLK	RCC_AHB1Periph_GPIOD
#define EX_HUMID_MODE	GPIO_MODER_MODER11
#define EX_HUMID_PuPd   GPIO_PuPd_UP
#define EX_HUMID_DAT_SZ	5

int ex_humid_init(void)
{
	GPIO_InitTypeDef  ex_humid_gpio_init;

	ex_humid_gpio_init.GPIO_Pin = EX_HUMID_PIN;
	ex_humid_gpio_init.GPIO_Mode = GPIO_Mode_OUT;
	ex_humid_gpio_init.GPIO_OType = GPIO_OType_OD;
	ex_humid_gpio_init.GPIO_PuPd  = GPIO_PuPd_UP;
	ex_humid_gpio_init.GPIO_Speed = GPIO_Speed_25MHz;  //originally 100MHz

	RCC_AHB1PeriphClockCmd(EX_HUMID_PCLK, ENABLE);
	GPIO_Init(EX_HUMID_PORT, &ex_humid_gpio_init);

	return 0;
}

int ex_humid_read(u8 *humid, u8 *temp,u32 *counter)
{
    u32 k=0;
	u8 got_response = 0;
	u8 bit_iter;
	u8 byte_iter;
	u8 data[EX_HUMID_DAT_SZ] = {0};

	GPIO_InitTypeDef  ex_humid_gpio_init;

		ex_humid_gpio_init.GPIO_Pin = EX_HUMID_PIN;
		ex_humid_gpio_init.GPIO_Mode = GPIO_Mode_OUT;
		ex_humid_gpio_init.GPIO_OType = GPIO_OType_OD;
		ex_humid_gpio_init.GPIO_PuPd  = GPIO_PuPd_UP;
		ex_humid_gpio_init.GPIO_Speed = GPIO_Speed_25MHz;  //originally 100MHz

		RCC_AHB1PeriphClockCmd(EX_HUMID_PCLK, ENABLE);
		GPIO_Init(EX_HUMID_PORT, &ex_humid_gpio_init);



	if (!temp || !humid) return -1;

	GPIO_ResetBits(EX_HUMID_PORT, EX_HUMID_PIN);

	delay_milis(4500); //delay_us(18000);	 //20ms

	//GPIO_SetBits(EX_HUMID_PORT, EX_HUMID_PIN);


	// Change mode to input
	EX_HUMID_PORT->MODER &= ~EX_HUMID_MODE;    // due to Pull up R automatically High...
	EX_HUMID_PORT->PUPDR &= ~EX_HUMID_PuPd;    // due to Pull up R automatically High...

	//ex_humid_gpio_init.GPIO_Mode = GPIO_Mode_IN;
	//ex_humid_gpio_init.GPIO_PuPd  = GPIO_PuPd_NOPULL;


	delay_milis(10);//delay_us(40);   // 34 wait for 25us
	 //if (!(GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN)))

	// If low

	if (!(GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN))) {

		delay_milis(21); //delay_us(80);   // wait for 90us

		if((GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN))) got_response=1;

		 while ((GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN)));  // wait for low...
	}

	if (!got_response) { return -1; }


	for (byte_iter = 0; byte_iter < 5; ++byte_iter) {
		u8 i=0;
		for (bit_iter = 0; bit_iter < 8; bit_iter++) {
			// Wait for high
			while (!(GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN))); // wait for HIGH
			delay_milis(10); //delay_us(40);   // wait for 30us



			if((GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN))==0)
			{
			 i&= ~(1<<(7-bit_iter));   // write 0
			}
		    else  i|= (1<<(7-bit_iter));  // if the pin is high, write 1

			while (GPIO_ReadInputDataBit(EX_HUMID_PORT, EX_HUMID_PIN));    // Wait for LOW
		} // end of bit_iter loop
	 data[byte_iter]=i;
	}

	//if (data[4] != (u8)(data[3] + data[2] + data[1] + data[0])) return -1;

	*humid = data[0];
	*temp = data[2];
	return 0;
}
