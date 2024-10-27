/* Template app on which you can build your own. */

#include "ch32v003fun.h"
#include "ch32v003_GPIO_branchless.h"
#include <stdio.h>
#include <stdbool.h>

#define DTR_PIN GPIOv_from_PORT_PIN(GPIO_port_A, 2)
#define RTS_PIN GPIOv_from_PORT_PIN(GPIO_port_A, 1)
#define LED_PIN GPIOv_from_PORT_PIN(GPIO_port_D, 4)
#define EN_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 1)
#define BOOT_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 2)
#define SW_PIN GPIOv_from_PORT_PIN(GPIO_port_C, 4)

#define ENABLE_DEBUGGING 0

bool enable_led = false;

void setup()
{
	GPIO_port_enable(GPIO_port_A);
	GPIO_port_enable(GPIO_port_C);
	GPIO_port_enable(GPIO_port_D);

	GPIO_pinMode(DTR_PIN, GPIO_pinMode_I_floating, GPIO_Speed_10MHz);
	GPIO_pinMode(RTS_PIN, GPIO_pinMode_I_pullUp, GPIO_Speed_10MHz);
	GPIO_pinMode(SW_PIN, GPIO_pinMode_I_pullUp, GPIO_Speed_10MHz);
	GPIO_pinMode(EN_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
	GPIO_pinMode(BOOT_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);

	Delay_Ms(1);

#if !ENABLE_DEBUGGING
	if (GPIO_digitalRead(SW_PIN) == high)
	{
		enable_led = true;
		GPIO_pinMode(LED_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
		Delay_Ms(1);
		GPIO_digitalWrite_1(LED_PIN);
	}
#endif ENABLE_DEBUGGING
}

uint32_t current_tick_us()
{
	return SysTick->CNT / DELAY_US_TIME;
}

void shift_download_boot()
{
	if (enable_led)
	{
		GPIO_digitalWrite_0(LED_PIN);
	}

	GPIO_pinMode(EN_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
	GPIO_pinMode(BOOT_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
	Delay_Ms(100);
	GPIO_digitalWrite_0(BOOT_PIN);
	Delay_Ms(100);
	GPIO_digitalWrite_0(EN_PIN);
	Delay_Ms(100);
	GPIO_digitalWrite_1(EN_PIN);
	Delay_Ms(100);
	GPIO_digitalWrite_1(BOOT_PIN);
	Delay_Ms(100);

	if (enable_led)
	{
		GPIO_digitalWrite_1(LED_PIN);
	}
}

void send_reset()
{
	GPIO_pinMode(EN_PIN, GPIO_pinMode_O_pushPull, GPIO_Speed_10MHz);
	Delay_Ms(100);
	GPIO_digitalWrite_0(EN_PIN);
	Delay_Ms(100);
	GPIO_digitalWrite_1(EN_PIN);
	Delay_Ms(100);
}

void main_loop()
{
	uint32_t before_log_us = current_tick_us();
	bool before_dtr = GPIO_digitalRead(DTR_PIN);
	bool before_rts = GPIO_digitalRead(RTS_PIN);
	bool before_sw = GPIO_digitalRead(SW_PIN);

	while (1)
	{
		uint32_t now_us = current_tick_us();

		if (now_us < before_log_us)
		{
			before_log_us = 0;
		}

		bool dtr = GPIO_digitalRead(DTR_PIN);
		bool rts = GPIO_digitalRead(RTS_PIN);
		bool sw = GPIO_digitalRead(SW_PIN);

		if (dtr == low && before_dtr == high)
		{
#if ENABLE_DEBUGGING
			printf("[%012d] shift boot\n", now_us);
#endif
			shift_download_boot();
		}else if (rts == low && before_rts == high)
		{
#if ENABLE_DEBUGGING
			printf("[%012d] detect rts\n", now_us);
#endif
			send_reset();
		}
		if (sw == high && before_sw == low)
		{
#if ENABLE_DEBUGGING
			printf("[%012d] shift boot\n", now_us);
#endif
			shift_download_boot();
		}

		before_dtr = dtr;
		before_sw = sw;

		if (now_us - before_log_us > 1000000)
		{
			before_log_us = now_us;
#if ENABLE_DEBUGGING == 1
			printf("[%012d]", now_us);
			printf("DTR:%d, ", dtr);
			printf("RTS:%d, ", rts);
			printf("SW:%d\n", sw);
#endif
			GPIO_digitalWrite_1(EN_PIN);
			GPIO_digitalWrite_1(BOOT_PIN);
		}
	}
}

int main()
{
	SystemInit();

	setup();

	main_loop();
}
