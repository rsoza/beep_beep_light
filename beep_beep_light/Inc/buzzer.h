
#ifndef BUZZER_H_
#define BUZZER_H_


#include "stm32f4xx.h"
void gpio_init(void);
void tim2_init();
void systick_Delay_Ms(int delay);
void set_note(void);

#endif /* BUZZER_H_ */
