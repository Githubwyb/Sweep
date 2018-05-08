#ifndef _TIMER_H_
#define _TIMER_H_

#include "types.h"

#define TIMER_UART_RECV TIMER_1
#define TIMER_LED_BUZZER_START TIMER_2
#define TIMER_LED_BUZZER_END TIMER_3

int timer_init(void);
int timer_update_IT(void);
int timer_start(TIMER_ENUM id, u32 period, TIMER_CB pFun);
int timer_stop(TIMER_ENUM id);
int timer_isTimerStart(TIMER_ENUM id);
void TIMER_IRQ_HANDLE(void *context);

#endif // !_TIMER_H_
