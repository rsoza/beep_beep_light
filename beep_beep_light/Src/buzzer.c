#include "stm32f4xx.h"
#include "buzzer.h"
#include "notes.h"

#define GPIOAEN					(1U<<0)
#define TIM2EN					(1U<<0)


// SysTick values
#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSRC				(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)



/*Procedure:
1. Select the counter clock (internal, external, prescaler).
2. Write the desired data in the TIMx_ARR and TIMx_CCRx registers.
3. Set the CCxIE bit if an interrupt request is to be generated.
4. Select the output mode. For example:
– Write OCxM = 011 to toggle OCx output pin when CNT matches CCRx
– Write OCxPE = 0 to disable preload register
– Write CCxP = 0 to select active high polarity
– Write CCxE = 1 to enable the output
5. Enable the counter by setting the CEN bit in the TIMx_CR1 register*/



void gpio_init(void)
{
		// Enable clock access to GPIOA
		RCC->AHB1ENR |= GPIOAEN;

		// Set PA5 as output pin TIM2_CH1
		GPIOA->MODER |= (1U<<11);

		// Set alternate function
		GPIOA->AFR[0] |= (1U<<20);

		// Enable clock access to TIM2
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}


void tim2_init()
{
	TIM2->PSC=0;
	TIM2->CNT=0;
	TIM2->CCMR1=(1<<5)|(1<<6); //configure the pins as PWM
	TIM2->CCER |= TIM_CCER_CC1E;
	TIM2->CR1 |= TIM_CR1_CEN;
}



void systick_Delay_Ms(int delay)
{
	// In Cortex-M4 User Guide
	SysTick->LOAD = 16000;
	SysTick->VAL = 0;
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for (int i =0 ; i<delay; i++ ){
		//wait until the countflag is set
		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0 ){}
	}
	SysTick->CTRL = 0;
}



