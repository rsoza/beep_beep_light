#include "stm32f4xx.h"

#define GPIOAEN			(1U<<0)
#define TIM3EN			(1U<<2)
#define LED_BLUE 		15			//PD15
#define PERIOD			100
#define DUTY			25

#define MODER_P13		(1U<<13)
#define AFRH7_29		(1U<<29)
#define CC4S			(1U<<9)
#define CC4P			(1U<<13)
#define OC4M_1			(1U<<14)
#define OC4M_2			(1U<<13)
#define OC4PE			(1U<<11)
#define ARPE			(1U<<7)
#define CC4E			(1U<<2)
#define CEN				(1U<<0)



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

void gpioa_init(void)
{
	// Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIOAEN;

	// Enable clock access to TIM3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Set PC7 as output pin TIM3_CH2
	GPIOD->MODER |= (1U<<15);

	// Enable AFR low bits
	GPIOD->AFR[0] |= AFRH7_29;
	//OR GPIO_AFRH_AFRH7_1
	//OR GPIO_AFRH_AFSEL15_1

	// Write to CCMR2, clear
//	1. Select the counter clock (internal, external, prescaler).
	// WANT A 00 FOR OUTPUT CONFIG
	TIM3->CCMR2 &=~ TIM_CCMR2_CC3S;

	// Select the polarity by writing the CCxP bit in CCER
	// starts high or low?
	// sET clock
	TIM3->CCER &=~ TIM_CCER_CC3P;

	// Select the PWM mode
	TIM3->CCMR2 |= TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1;

	// Program period ARR
	TIM3->PSC = 15999;

	TIM3->ARR = PERIOD;
	TIM3->CCR4 = DUTY;

	 // Preload bit 11 and 7
	TIM3->CCMR2 |= TIM_CCMR2_OC3PE;

	TIM3->CR1 |= TIM_CR1_ARPE;


	TIM3->CCER |= TIM_CCER_CC3E;
	TIM3->CR1 |= TIM_CR1_CEN;



}


