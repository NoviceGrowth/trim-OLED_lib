/*
	Copyright (c) [2019] [һֻ����Ե jiezhuo]
	[https://gitee.com/jiezhuonew/oledlib] is licensed under the Mulan PSL v1.
	You can use this software according to the terms and conditions of the Mulan PSL v1.
	You may obtain a copy of Mulan PSL v1 at:
		http://license.coscl.org.cn/MulanPSL
	THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
	PURPOSE.
	See the Mulan PSL v1 for more details.
	
	ͼ�ο����˵��: ��ת����test.c����
*/

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"
#include "timer.h"
#include "test.h"
#include "draw_api.h"

u8 flag1s;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init();
	BEEP_Init();
	uart_init(115200);
	TIM3_Int_Init(10-1,7200-1);
	InitGraph();
	
	while(1)
	{
		demo();
	}
} 
