#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/app_version.h>
#include <lib/mylib.h>

#define SLEEP_TIME_MS   1000

int main(void)
{
	int i = 0;
	char str[128];

	while (1) {
		printf("Hello Witekio ! " APP_VERSION_STRING "\r\n");
		mylib_get_val(str, i);
		printf("Cumputing %s\r\n", str);

		i = (i + 1)%60;

		k_msleep(SLEEP_TIME_MS/4);
	}
	return 0;
}
