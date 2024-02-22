#include "stm32f4xx.h"
#include "buzzer.h"



int main(void)
{

	gpio_init();
	tim2_init();


	while(1)
	{
		for (int i=0;i<RATE;i++)
		{
			TIM2->CCR1=i;
			TIM2->CCR2=RATE-i;
			systick_Delay_Ms(5);
		}
		for (int i=RATE;i>0;i--)
		{
			TIM2->CCR1=i;
			TIM2->CCR2=RATE-i;
			systick_Delay_Ms(5);
		}
	}
}
