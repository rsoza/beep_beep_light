#include "buzzer.h"
#include "notes.h"

uint16_t pwmData[16];
uint16_t durData[16];

int main(void)
{

	// for the ccr = duty cycle
	pwmData[0]= 392;
	pwmData[1]= 262;
	pwmData[2]= 311;
	pwmData[3]= 349;
	pwmData[4]= 392;
	pwmData[5]= 262;
	pwmData[6]= 311;
	pwmData[7]= 349;
	pwmData[8]= 392;
	pwmData[9]= 262;
	pwmData[10]= 311;
	pwmData[11]= 349;
	pwmData[12]= 392;
	pwmData[13]= 262;
	pwmData[14]= 311;
	pwmData[15]= 349;

	durData[0]= 8;
	durData[1]= 8;
	durData[2]= 16;
	durData[3]= 16;
	durData[4]= 8;
	durData[5]= 8;
	durData[6]= 16;
	durData[7]= 16;
	durData[8]= 8;
	durData[9]= 8;
	durData[10]= 16;
	durData[11]= 16;
	durData[12]= 8;
	durData[13]= 8;
	durData[14]= 16;
	durData[15]= 16;

	gpio_init();
	tim2_init();


//	while(1)
//	{
		for (int i=0;i<16;i++)
		{
			TIM2->CCR1=pwmData[i];
			TIM2->CCR2=16-i;
			systick_Delay_Ms(durData[i]*10);

		}
//		for (int i=RATE;i>0;i--)
//		{
//			TIM2->CCR1=i;
//			TIM2->CCR2=RATE-i;
//			systick_Delay_Ms(10);
//		}
//	}
}
