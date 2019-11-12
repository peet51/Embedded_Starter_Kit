#include <stdio.h>
#include <stdlib.h>
#include "drivers/clock_config.h"
#include "drivers/DISPLAY_WH1602B_4Bit.h"
#include "drivers/Buttons.h"

int main(void)
{
	u8 humid;
	u8 temp;
   u32 counter;
	printf("Program start\r\n");

	Display_clear();
	setup_Display();
	//Init_ONBOARD_BUTTONs();


	char tmp[32];
	uint16_t len = 0;


while(1)
{


	 if (ex_humid_read(&humid, &temp,&counter) == 0) {
		printf("Humidity: %d percent\r\n", humid);
		printf("Temp: %d C\r\n", temp);
	 } else {
		printf("Can't get data\r\n");
	 	 	}
      delay_milis1(200);


     sprintf(tmp, "%d", humid);
     len = strlen(tmp);

		Display_Write_Ins(GO_TO_START_FIRST_LINE);
		Display_Write_Data_Array("HUMIDITY: ",10);
		Display_Write_Ins(GO_TO_START_FIRST_LINE+13);

		Display_Write_Data_Array(tmp, len);
		Display_Write_Ins(GO_TO_START_FIRST_LINE+15);
		Display_Write_Data_Array("%",1);


		sprintf(tmp, "%d", temp);
		len = strlen(tmp);
		Display_Write_Ins(GO_TO_START_SECOND_LINE);
		Display_Write_Data_Array("TEMPERATURE: ",12);
		Display_Write_Ins(GO_TO_START_SECOND_LINE+13);
		Display_Write_Data_Array(tmp, len);

}

	printf("Program end\r\n\r\n");
	return 0;
}
