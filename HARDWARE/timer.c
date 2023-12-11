#include "timer.h"
#include "draw_api.h"

extern u8 flag1s;

/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//
//����������������ʱ��־λ�������� ��ʱ1ms  10-1 7200-1
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);		//ʹ��TIM3ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Period		=	arr;	//��ʼ����ʱ��3
	TIM_TimeBaseInitStructure.TIM_Prescaler		=	psc;
	TIM_TimeBaseInitStructure.TIM_CounterMode	=	TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision	=	TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);				//����ʱ��3�����ж�
	
	NVIC_InitStructure.NVIC_IRQChannel 						=	TIM3_IRQn;	//��ʼ��NVIC
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	=	0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority			=	0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd 					=	ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM3,ENABLE);									//ʹ�ܶ�ʱ��3
}

void TIM3_IRQHandler(void)
{
	static u16 tmrms=0;
	
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET)
	{
		OledTimeMsFunc();	//ʵʱʱ��-- ��0Ϊֹ
		tmrms++;
		if(tmrms>=1000)
		{
			tmrms=0;
			flag1s=1;			//����1s
		}
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
}
	 
