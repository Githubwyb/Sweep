#include "led.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "timer.h"

int led_init(void)
{
	IOWR_ALTERA_AVALON_PIO_DIRECTION(LED_BASE, 0x0);
    return F_SUCCESS;
}

int led_write(u8 state)
{
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, state);
    return F_SUCCESS;
}

int led_change(u8 led)
{
    return F_SUCCESS;
}

static int led_timer_startCb(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		flag = 1;
		IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0x01);
		led_write(0x03);
	}
	else
	{
		flag = 0;
		IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0x00);
		led_write(0x01);
	}
	timer_start(TIMER_LED_BUZZER_START, 200, led_timer_startCb);
	return F_SUCCESS;
}

int led_start(void)
{
	timer_start(TIMER_LED_BUZZER_START, 200, led_timer_startCb);
	return F_SUCCESS;
}

static int led_timer_endCb(void)
{
	led_write(0x01);
	IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0x00);
	return F_SUCCESS;
}

int led_end(void)
{
	led_write(0x03);
	IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0x01);
	timer_stop(TIMER_LED_BUZZER_START);
	timer_start(TIMER_LED_BUZZER_END, 1000, led_timer_endCb);
	return F_SUCCESS;
}
