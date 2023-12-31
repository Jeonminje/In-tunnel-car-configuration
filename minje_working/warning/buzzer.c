#include "buzzer.h"

void init_buzzer()
{
    
    pinMode(BUZZER_PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
}

void setNote(int note)
{
    pwmSetClock(RAS_CLOCK);
    pwmSetRange(MICROSECOND/note);
    pwmWrite(BUZZER_PIN, MICROSECOND/note * DUTY_CYCLE);
}

void *frontWarningSound()
{
    setNote(NOTE_D6);

    turnRed();
    delay(200);
    pwmWrite(BUZZER_PIN,0);
    offRed();
    delay(100);

    setNote(NOTE_D6);

    turnRed();
    delay(100);
    pwmWrite(BUZZER_PIN,0);
    offRed();
    delay(500);
	buzzer_flag = 0;
	
	return;
}

void *sideLaneWarningSound()
{
    turnRed();
    for(int i = NOTE_D4; i< NOTE_G5;i++){
        setNote(i);
        delay(10);
    }
    offRed();
	buzzer_flag = 0;
	
	return;
}