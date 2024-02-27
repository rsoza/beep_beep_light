# Beep Beep Light Player with STM32F411

This project utilizes an STM32F411 microcontroller to play the song "Boom Boom Pow" through a buzzer while synchronizing LED interrupts with tone changes. The buzzer generates the tones of the song, and the LED blinks each time the tone changes. The name "Beep Beep Light" is a pun to [Boom Boom Pow by The Black Eyed Peas](https://www.youtube.com/watch?v=mlpq2GKJ-G0).

## Components Used

- [STM32F411 microcontroller](https://www.amazon.com/NUCLEO-F411RE-Nucleo-64-Development-STM32F411RE-connectivity/dp/B07JYF8RRB/ref=asc_df_B07JYF8RRB/?tag=hyprod-20&linkCode=df0&hvadid=644617763239&hvpos=&hvnetw=g&hvrand=817221734410163284&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9024235&hvtargid=pla-944644321144&psc=1&mcid=4a6fdcb2ef17389bb1202cfdf9fc3466)
- [Buzzer](https://www.amazon.com/QMseller-Terminals-Raspberry-Electronic-Continous/dp/B07VRK7ZPF/ref=sr_1_1_sspa?crid=2QL7ZNGOX3UVV&dib=eyJ2IjoiMSJ9.4IGa0thexcVgIQxIW1PL536r0ei-T1TJhvMiTNt6V_gL3u5F0Nbge1vNtF8nbAvOzzYjh5KaZfhSd0lnUjsTZo5mydz2X9yhnd4tij1YrB3RHFsK1Q2rLyw8YsbvXOE9YHRNbO2D26hblmQgFDCllgRqKkyGsmDiGayRmpQ9Pl0qgDLGqSGiU9rlxBdIVM5ANQtikf1AA1r1zHj2l1VWtetsMgphB_7hUwoDXHJ3KEHTP5_wR2xvgncrSSvMOlnew-J46vpdQIYnvclJCxPDpT-NMPR2NJ_EMgacfPKAiN0.eBkA4AIW6oSlyW47F9_1B1nJMoV0gEui-hXmDgsesis&dib_tag=se&keywords=buzzer&qid=1708528486&s=electronics&sprefix=buzzer%2Celectronics%2C182&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- [LED](https://www.amazon.com/BOJACK-Lighting-Electronics-Components-Emitting/dp/B09XDMJ6KY/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.vYCFu-GM_5Pnzq-33rIP56Ci4oCoDfcyqBjmVdG_FmyjQ7UfXnDz_gRnlw1UO6JcQM5XkHZ__wBN-vLW_xgrRF6dYg2VsOX3kzGKURNWac3RK4x9MEs51Oc27x2Y4VLM9mKXq8wjPf5dssQNWJs2AziVlQsoR_WHv4ROHBpiW7grr6MUx6oTGpJVwzIFyz3xTSkl0iMMsrFoVtbfn653bga4JUzGTn0uSqO-ELkdeM2gsXQ9WiXdRigIxS3Kc7vZ0WrKFYcJC1LtYCToLhp28kGXGjEgRmm5CozrDwllF6Y.8HbO_IQJDpO9SLUOKurBlxSpWeC4jbfQjRr5X88kJ6M&dib_tag=se&keywords=led&qid=1708528508&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

## Features

- Plays the song "Boom Boom Pow" through the buzzer.
- Synchronizes LED interrupts with tone changes in the song.
- Utilizes PWM for controlling the buzzer tones.

## PWM

The most important pary to understand here is pulse width modulation. This technique is a function of a timer with a technique to control analoguy circuit with digital output from the MCU.

I will explain two things:
1. Piezo Buzzer
2. Timer - PWM

### 1. Piezo Buzzer

This buzzer was part of a breadboard kit that I decided to mess around with here. The component produces sound through piezoelectric materials that deform when alternating voltage applied. The voltage that can be applied is 3.3V to 5V.
 
I am altering the sound of the buzzer by manipulating the frequency within a period. The material of the piezoceramic material stretches and compresses with the frequency calculated, thus creating screeching noise to potentially make a song!


### 2. Time - PWM

I am fairly new to understanding this so I could butcher the technicalities. Please review [this](https://controllerstech.com/pwm-in-stm32/), [this](https://www.steppeschool.com/pages/blog/stm32-pwm-stm32cubemx), and [this](https://labs.dese.iisc.ac.in/embeddedlab/generating-pwm-with-microcontroller-using-timer-counter/#:~:text=The%20PWM%20timer%20is%20configured,of%20the%20final%20PWM%20output.) for accurate information. 

What I gathered to be most valuable to conduct the specific frequencies needed is understanding the mode applied for the GPIO pin to timer mode to PWM. Once the modes are applied, configuring the period through the Auto-relaod register (ARR) and delay allowed for the frist four seconds of "Boom Boom Pow" to play.


## Next Steps

- Create an interrupt to blink the LED every time there is pause between sets.
