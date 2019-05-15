
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

volatile int ticks=0;
extern "C" void SysTicks_Handler(){
	ticks++;
}
void delay_ms(int interval){
	int temp=ticks+interval;
	while (ticks<temp);
}

int main(void)
{
  int i = 0;


  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  SysTick_Config(168000);


  while (1)
  {
	  	STM_EVAL_LEDOn(LED3);
	  	delay_ms(100);
	  	STM_EVAL_LEDOff(LED3);

	  	STM_EVAL_LEDOn(LED3);
		delay_ms(100);
		STM_EVAL_LEDOff(LED3);

	    STM_EVAL_LEDOn(LED3);
		delay_ms(100);
		STM_EVAL_LEDOff(LED3);

		STM_EVAL_LEDOn(LED3);
		delay_ms(100);
		STM_EVAL_LEDOff(LED3);

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
extern "C" void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
extern "C" uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
