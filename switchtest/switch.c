#include <stdio.h>
#include <wiringPi.h>

#define GPIO_testSwitch 15

void switch_toggle_callback()
{
	printf("%s\n", "Switch toggled");
}

int main()
{
  
	wiringPiSetupGpio();
	if(wiringPiISR(GPIO_testSwitch, INT_EDGE_RISING, &switch_toggle_callback) < 0)
	{
		printf("%s\n", "Interrupt setup Fail");
	}
   printf("%s\n", "test");
  while(1)
  {
    printf("%s\n","Loop");
    delay(100);
  }
	return 0;
}
	
