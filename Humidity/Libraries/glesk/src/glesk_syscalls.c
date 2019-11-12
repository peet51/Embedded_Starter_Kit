#include "C:\Users\peter.klco\Downloads\GL-SK-FWLIB-master\GL-SK-FWLIB-master\07_humidity\Libraries\glesk\inc\glesk_uart.h"

int _write(int fd, char *str, int len)
{
	int ret;

	if (fd != 1) return -1;

	ret = uart_init(PRINTF_UART_NUM, PRINTF_UART_SPEED);
	if (ret < 0) return -1;

	ret = uart_write(PRINTF_UART_NUM, str, len);
	if (ret < 0) return -1;

	return len;
}
