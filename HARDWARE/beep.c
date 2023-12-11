#include "beep.h"
#include "delay.h"

void BEEP_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(BEEP_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin		=	GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode	=	GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed	=	GPIO_Speed_50MHz;
	
	GPIO_Init(BEEP_PORT,&GPIO_InitStructure);
	
	
	BEEP=1;
	delay_ms(100);
	BEEP=0;
}
