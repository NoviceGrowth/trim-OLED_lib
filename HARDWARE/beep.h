#ifndef __BEEP_H
#define __BEEP_H

#include "sys.h"

#define BEEP_CLK	RCC_APB2Periph_GPIOB
#define BEEP_PORT	GPIOB
#define BEEP_PIN	GPIO_Pin_8

#define BEEP	PBout(8)

void BEEP_Init(void);

#endif

