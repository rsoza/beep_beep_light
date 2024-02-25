#include "buzzer.h"
#include "notes.h"

void song(int frequency, int duration);

int wholenote = (60000 * 4) / 85;

int main(void)
{

	// Boom Boom Pow... i think
	// https://www.hooktheory.com/hookpad/iframe/lamkvqOLoDM?enableYouTube=true&showPianoInstrument=false&showRewindControl=false&tabPlayType=tab-play-type-youtube
	int melody[] = {
	  NOTE_A1,8, NOTE_A1,8, NOTE_AS1,16, 0, 10,
	  NOTE_A1,8, NOTE_A1,8, NOTE_AS1,16, 0, 10,
	  NOTE_A1,8, NOTE_A1,8, NOTE_AS1,16, 0, 10,
	  NOTE_A1,8, NOTE_A1,8, NOTE_AS1,16, 0, 10,
	  NOTE_F6,8, NOTE_F6,8, NOTE_FS6,16, 0, 10,
	  NOTE_F6,8, NOTE_F6,8, NOTE_FS6,16, 0, 10,
	  NOTE_F6,8, NOTE_F6,8, NOTE_D4,16, 0, 10,
	  NOTE_F6,8, 0, 10, 0, 10,

	};



	gpio_init();
	tim2_init();


	while(1){
	for (int i = 0; i < (sizeof(melody) / sizeof(melody[0])) -1; i+=2) {
	        song(melody[i], melody[i+1]);
	    }

	}
}


void song(int frequency, int duration) {

	duration = duration > 0 ? duration : abs(duration);
    TIM2->ARR = 450000 / frequency; // Set PWM period for the desired frequency
    TIM2->CCR1 = TIM2->ARR /2 ; // duty cycle percentage
    systick_Delay_Ms(duration * 60);
    TIM2->CCR1 = 0; // off -PWM
    systick_Delay_Ms(10);
}
