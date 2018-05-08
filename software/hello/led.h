#ifndef _LED_H_
#define _LED_H_

#include "types.h"

int led_init(void);
int led_write(u8 state);
int led_change(u8 led);
int led_start(void);
int led_end(void);

#endif //! _LED_H_
