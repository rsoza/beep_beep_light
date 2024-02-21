#include "buzzer.h"
#include "stm32f4xx.h"

#define PIN9		(1U<<9)
#define BUZZER		PIN9
int main(void)
{
	gpioa_init();
	while(1);
}
