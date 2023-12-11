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
	
	==========�˺�����oledlibͼ�ο���ۺϲ��Ժ��� ������ʹ�õ����������������==================
	
	Ŀǰ����˵��:
		����ʹ�õ�0.96��7����oled ʹ��SPIͨ�ŷ�ʽ(�����oled_drive.c)
		D0  = SCK  ->	PA4		(��Ļ���β�ͬ˿ӡ���ܲ�ͬ)
		D1  = SDA  ->	PA5
		RES = RES  ->	PA6
		DC  = DC   ->	PA7
		CS  = SCS  ->	PA8
		
	���ģ��:
		oled	spi����
		beep	������ ��ʾ����Ϊled��ʾ����״̬
		timer3	�ж�1ms ��Ϊͼ�ο��ṩʱ���׼
		uart	����Ϊ�������ӵ��Դ�ӡ����xinxi
		delay	ϵͳ�Դ���ʱ���������ṩ��ʱ����
	
	��Ƶ��ʾ��Ϣ:
		��Ƭ�� --- STM32F103
		oled   --- ����4��SPI��7����0.96��ڰ�˫ɫoled
	
	ͼ�ο⹦��:
		��oledlib�ļ������������c�ļ��ķ��� ÿ��c�ļ��Ŀ�ͷ���жԸ��ļ��ļ�Ҫ˵��
		������� ���� ���� ������ Բ ��Բ Բ�Ǿ��� �ı�Ե�����
		������ �ַ���ʾ ������ʾ λͼ��ʾ
		����� oledģ�⴮��printf��debug
		
	�ַ���ʾ:
		������ַ���4�ִ�С0-1-2-3 ����μ�SetFontSize()
		���ڴ�ҵ�ʹ��ϰ��
		0��һ����ϰ���õ�			��ʱyֻ��Ϊ0-7��Ӧ��ʾ��7���� 		ע��:��ʱxΪ�ػ����� yΪ�ڼ���
		2 3���ǻ���1�ĵȱ����Ŵ�	��ʱy��Ϊ0-6x��Ӧ��ʾ��ÿһС��		��ʱΪ��������ϵ xΪ�ڼ�С�� yΪ�ڼ���
		
	���ĺ�����ʾ:	
		���ĺ��ֵĴ�СΪ16x16		��ʱyҲֻ��Ϊ0-7��Ӧ��ʾ��7����		ע��:��ʱxΪ�ػ����� yΪ�ڼ���
		
	ȡģ˵��:
		ȡģ�������PCtoLCD2002
		�ַ� ���� �� λͼ��ȡģ��ʽ�����ö���font.c��bmp.c����ע��
		
	�û����ú���:
		��draw_api.h���ṩ�����к����Ľӿ� �������в鿴���к����ļ�Ҫ����
		
	��ֲ˵��:
		1.��ֲͼ�ο����Ҫ׼���õײ����� ��oled_driver.c�������޸ļ��� �ڸ�c�ļ���ͷ��˵��
		2.����Ҫ��test.c�еĶ���Ч�����в��� ����ҪΪ����OledTimeMsFunc()�ṩʱ���׼
		3.�⺯��ʹ�õ���ʱ������DelayMs() ��ֲ���ɵ�Ƭ���ͺŲ������DelayMs()
		
	ͼ�οⱾ��:
		��ͼ�οⱾ��Ϊ��һ������в��� Ȼ��ˢ���������鵽��Ļ��ʵ��Ч��
		������Ƶ�����(oled/TFT/��С�ߴ�/����/Һ��)Ҳ����ʹ�� �������ؿɲμ�oled_config.h
		
	��ϸ��ע��:
		�����ʹ��Ϊ��; �˽�test.c��draw_api.c���� ����������ڵ�UI����
		�ڱ����Ķ������ע�͵Ĺ����� ���ֺܶ�ṹ�ͺ�����ֵ��ѧϰ ��ϸ������ 
		
	GUI�ͱ�ͼ�ο�Ĺ�ϵ:
		gui��һ����ͼ�ν����������˻�������ϵͳ gui��ӵ�д��ڡ��˵����ؼ����Ի���Ƚ�����ͼ�νӿ�
		���ֻ��һ��ͼ�ο� ������c++�ϵ�easyxͼ�ο� ��û��ͼ�νӿڵ� ֻ�ṩ��ͼ����ʾ�Ĺ���
		ͼ�ο��������gui��һ���֣�Ҳ�����Լ���ͼ�ο������װΪgui��
	
	��������:
		��ȥλͼ Code=26254 RO-data=3754 RW-data=100 ZI-data=4108  
		
	ԭ���Ļ�:
		Ϊ�����������ͼ�ο⣬�Ҳο��˺ܶ��������㷨,���˴���ʱ��ȥ����ֲ
		�Ż������вο�������github�е�arduboy��Ϸ�����󲿷�ͼ������ֲ���ģ�
		����������ĳ���汾,���кܶ�ط���Ҫ�Ż��Ľ�������Ҫ�����ͼ�ο�����
		��������������Ȥ�Ķ�������ģ�飬���붼������򵥵ķ�ʽ��д�ģ����ǿ�Դ�ġ�
		����Ҳ�����ע��˵�����ø������Ե�Ƭ����oled��������Ӳ����̣������
		ʹ���˸ÿ⣬�����������bվ��עoximeterg���ɻ�ȡ�ÿ�����°汾����Ϣ��
		ע�⣺��������ʵ�ĵ�ͼ�Σ�Ӱ��ˢ��Ч�ʣ����Ż��У�
*/


#include "test.h"
#include "draw_api.h"
#include "delay.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

void ShowStars(void);
void ShowWatch(void);
void ShowTest(void);
void ShowSnow(void);


void demo(void)
{
	int i,j;
	//demo��ʾ
	ClearScreen();
	DrawBitmap(0,0,Panda,128,64);
	UpdateScreen();
	DelayMs(1000);
	DelayMs(1000);
	DelayMs(1000);

	//�ַ�
	ClearScreen();
	SetFontSize(1);
	DrawString(0,0,"test");
	UpdateScreen();
	DelayMs(1000);
	
	SetFontSize(2);
	DrawString(0,8,"test");
	UpdateScreen();
	DelayMs(1000);
	
	SetFontSize(3);
	DrawString(0,24,"test");
	UpdateScreen();
	DelayMs(1000);
	
	//���ֲ���
	ClearScreen();
	OLED_ShowCHinese(0,0,"һֻ����Ե");
	UpdateScreen();
	DelayMs(1000);
	OLED_ShowCHinese(2,0,"һֻ����Եһֻ����Եһֻ����Եһֻ����Ե");
	UpdateScreen();
	DelayMs(1000);
	DelayMs(1000);
	
	//���ֲ���
	ClearScreen();
	for(i=0;i<300;i++)
	{
		SetFontSize(0);
		DrawNum(0,96,i,4);
		SetFontSize(1);
		DrawNum(0,16,i,4);
		SetFontSize(2);
		DrawNum(0,24,i,4);
		SetFontSize(3);
		DrawNum(0,40,i,4);
		UpdateScreen();
		DelayMs(1);
	}
	
	//����debug
	DelayMs(1000);
	ClearScreen();
	for(i=0;i<256;i++)
	{
		OledPrintf("num:%d cha:%c hex:%x\r\n",i,i,i);
		DelayMs(7);
	}
	DelayMs(1000);
	
	//����
	ClearScreen();
	for(i=0;i<20;i++)
	{
		DrawLine(0,0,i*10,63);
		UpdateScreen();
		DelayMs(100);
	}
	for(i=0;i<20;i++)
	{
		DrawLine(128,0,128-i*10,63);
		UpdateScreen();
		DelayMs(100);
	}
	DelayMs(1000);

	//����
	for(j=0;j<2;j++)
	{
		if(j==0)
		ClearScreen();
		for(i=0;i<31;i+=2)
		{
			DrawRect2(i*2,i,128-i*4,64-2*i);//���������
			UpdateScreen();
			DelayMs(100);
		}
		if(j==0)
		ClearScreen();
		DelayMs(500);
		for(i=31;i>0;i-=2)
		{
			DrawFillRect2(i*2,i,128-i*4,64-2*i);//��ʵ�ľ���
			UpdateScreen();
			DelayMs(100);
		}
		SetDrawColor(pix_black);//������ɫ
		SetFillcolor(pix_black);//�����ɫ
	}
	SetDrawColor(pix_white);
	SetFillcolor(pix_white);
	
	//Բ�Ǿ���
	for(j=0;j<2;j++)
	{
		if(j==0)
		ClearScreen();
		for(i=0;i<25;i+=2)
		{
			DrawRoundRect(i*2,i,128-i*4,64-2*i,8);
			UpdateScreen();
			DelayMs(100);
		}
		if(j==0)
		ClearScreen();
		DelayMs(500);
		for(i=25;i>2;i-=2)
		{
			DrawfillRoundRect(i*2,i,128-i*4,64-2*i,8);
			UpdateScreen();
			DelayMs(100);
		}
		SetDrawColor(pix_black);
		SetFillcolor(pix_black);
	}
	SetDrawColor(pix_white);
	SetFillcolor(pix_white);
	DelayMs(1000);
	
	//��Բ
	ClearScreen();
	DrawEllipse(63,31,63,31);
	UpdateScreen();
	DelayMs(1000);
	ClearScreen();
	DrawEllipse(63,31,16,31);
	UpdateScreen();
	DelayMs(1000);
	ClearScreen();
	DrawFillEllipse(63,31,63,31);
	UpdateScreen();
	DelayMs(1000);
	ClearScreen();
	DrawFillEllipse(63,31,16,31);
	UpdateScreen();
	DelayMs(1000);
	
	//Բ
	ClearScreen();
	DrawCircle(63,31,30);
	UpdateScreen();
	DelayMs(1000);
	ClearScreen();
	DrawFillCircle(63,31,30);
	UpdateScreen();
	DelayMs(1000);

	//������
	ClearScreen();
	DrawTriangle(5,10,100,30,60,50);
	UpdateScreen();
	DelayMs(1000);
	ClearScreen();
	DrawFillTriangle(5,10,100,30,60,50);
	UpdateScreen();
	DelayMs(1000);
	
	//����ͼ��ͼƬ λͼ
	ClearScreen();
	DrawBitmap(0,0,BmpTest1,16,16);
	UpdateScreen();
	DelayMs(1000);
	DrawBitmap(16,0,BmpTest2,32,32);
	UpdateScreen();
	DelayMs(1000);
	DrawBitmap(48,0,BmpTest3,64,64);
	UpdateScreen();
	DelayMs(1000);
	
	//Բ��
	ClearScreen();
	for(i=0;i<369;i++)
	{
		DrawArc(63,31,30,0,i);	//��Բ��
		UpdateScreen();
		ClearScreen();
	}
	DrawCircle(63,31,30);		//��Բ
	UpdateScreen();
	DelayMs(500);
	
	for(i=0;i<10;i++)
	{
		DrawFillCircle(63,31,i);	//���������Բ
		DrawCircle(63,31,30);
		UpdateScreen();
		ClearScreen();
		DelayMs(100);
	}

	//�Ƶ�
	for(i=0;i<720;i++)//ת720��2Ȧ
	{
		TypeXY temp;
		SetAngle(i);					//���ýǶ�
		SetRotateCenter(63,31);			//����Բ��
		temp=GetRotateXY(63,31+30);		//����֪������ת�Ƕ�
		DrawFillCircle(temp.x,temp.y,5);//���������λ��
		DrawCircle(63,31,30);			//�����켣
		DrawFillCircle(63,31,10);		//�������
		UpdateScreen();					//������Ļ
		ClearScreen();
	}
	
	//���ұ�ƽ��
	for(i=0;i<95;i++)
	{
		TypeXY temp;					//��ʵ�������������ת
		SetAngle(720+i);				//��ͼ��ʱ��x+ƫ����
		SetRotateCenter(63+i,31);
		temp=GetRotateXY(63+i,31+30);
		DrawFillCircle(temp.x,temp.y,5);
		DrawCircle(63+i,31,30);
		DrawFillCircle(63+i,31,10);
		UpdateScreen();
		ClearScreen();
	}

	//����
	ShowStars();	//�ǿն���
	ShowWatch();	//ʱ�Ӷ���
	ShowPolygon();	//����ζ���
	DelayMs(1000);

	//����
	ClearScreen();
	SetFontSize(2);
	DrawString(8,16," Show End ");	//��ʾ�ַ���
	UpdateScreen();
	DelayMs(1000);
	DelayMs(1000);
	ClearScreen();
	DrawBitmap(0,10,Like,128,40);	//����ͼƬ
	UpdateScreen();
	while(1);
}

/////////////////////////////////////////////////////////////////////////////////////////////
//�ǿն���
void ShowStars(void)
{
	int i;
	int count=0;
	int fps=60;
	typedef struct START
	{
		short x;
		short y;
		short speed;
		unsigned char speedcount;
		unsigned char isexist;
	}Star;
	
	Star star[128]={0};
	srand(2);
	for(i=0;i<128;i++)
	{
		if(star[i].isexist==0)
		{
			//����128��()���ǵĳ�ʼ��Ϣ
			star[i].x=rand()%127;		//������ɳ�ʼx����
			star[i].y=rand()%64;		//�������y������
			star[i].speedcount=0;
			star[i].speed=rand()%8+1;	//1-8����
			star[i].isexist=1;
		}
	}
	while(1)
	{
		if(FrameRateUpdateScreen(fps)==1)	//�ڴ˺����ж�ʱˢ����
		{
			count++;
			if(count>=fps*10)   			//10����ʱ�䵽��֮������ѭ����������
				return;
		}
		
		//�˶κ���һֱ������
		//���λ���128������
		for(i=0;i<128;i++)
		{
			//�����һ�������Ѿ��ƶ����˳���Ļ����
			//�����������������һ��������
			if(star[i].isexist==0)
			{
				star[i].x=0;
				star[i].y=rand()%64;
				star[i].speed=rand()%6+1;
				star[i].speedcount=0;		
				star[i].isexist=1;
			}
			else
			{
				star[i].speedcount++;
				if(star[i].x>=124)			//����Ѿ��˳���Ļ
					star[i].isexist=0;
				
				//�����һ��ʱ�̻�������(��β��) ������û�в��� �������������
				SetDrawColor(pix_black);	
				DrawLine(star[i].x,star[i].y,star[i].x,star[i].y);
				
				SetDrawColor(pix_white);	
				if(star[i].speedcount==star[i].speed)	//����ʱ�䵽��һ���ĳ���
				{
					star[i].speedcount=0;				//��λ����ʱ�䲢������һ��
					star[i].x+=1;						//��֮���ǵĽ�����Ҫ���⾭��124��
				}										//ֻ�����еĸ��� �����ƶ�����
				//��ͷ��β������������ ���������Ƿ��Ѿ��仯
				DrawLine(star[i].x, star[i].y, star[i].x+(6/star[i].speed)-1, star[i].y);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
//ʱ�Ӷ���
//�� Сʱ ���� �룬
void RoundClock(int hours ,int minute ,int sec)
{
	unsigned char i=0;
	TypeXY hourspoint,minutepoint,secpoint,tmp1,tmp2;
	
	//ʱ��
	SetRotateValue(63,31,hours*30+(minute*30)/60,1);
	hourspoint=GetRotateXY(63-14,31);
	DrawLine(63,31,hourspoint.x,hourspoint.y);
	//����
	SetRotateValue(63,31,minute*6+(sec*6)/60,1);
	minutepoint=GetRotateXY(63-21,31);
	DrawLine(63,31,minutepoint.x,minutepoint.y);	
	//����
	SetRotateValue(63,31,sec*6,1);
	secpoint=GetRotateXY(63-28,31);
	DrawLine(63,31,secpoint.x,secpoint.y);
	//����
	for(i=0;i<12;i++)
	{
		SetRotateValue(63,31,i*30,1);
		tmp1=GetRotateXY(63-29,31);
		tmp2=GetRotateXY(63-24,31);
		DrawLine(tmp1.x,tmp1.y,tmp2.x,tmp2.y);
	}
	DrawFillCircle(63,31,2);
	DrawCircle(63,31,30);
	UpdateScreen();
	ClearScreen();
}

void ShowWatch(void)
{
	int i,j,z;
	int count=0;
	
	for(i=0;i<12;i++)
		for(j=0;j<60;j++)
			for(z=0;z<60;z++)
			{
				RoundClock(i,j,z);
				count++;
				if(count>=800)
				return;
			}
}

/////////////////////////////////////////////////////////////////////////
//����ζ���
void ShowPolygon(void)
{
	int x0=63,y0=31;		//������ε����Բ��Բ��
	unsigned char i =0,j;
	int n=1,r=31;			//����n���� ��С�뾶31
	int v=1,count=0;		//ÿ�����ڵĶ���θ�1 ��count�κ��˳�
	int x[30],y[30];
	
	while(1)
	{
		ClearScreen();
		for(i=0;i<n;i++)
		{
			x[i]=r*cos(2*3.1415926*i/n)+x0;
			y[i]=r*sin(2*3.1415926*i/n)+y0;
		}
		for(i=0;i<=n-2;i++)
		{
			for(j=i+1;j<=n-1;j++)
				DrawLine(x[i],y[i],x[j],y[j]);
		}
		n+=v;
		if(n==20||n==0)
			v=-v;
		
		DelayMs(100);		//��ʱͣ��100ms
		UpdateScreen();
		if(++count==90)
		{
			count=0;
			return ;
		}
	}
}
	
//��ѩ�ĺ��� ���ǿ����� �Ͳ�չʾ��
void ShowSnow(void)
{
	int a[66],i,num=0;
	struct Snow
	{
	 short x;
	 short y;
	 short speed;
	}snow[100];

	srand(1);
	for(i=0;i<66;i++)
	 a[i]=(i-2)*10;
	ClearScreen();
	while(1)
	{
		if(num!=100)
		{
			snow[num].speed=1+rand()%4;
			i=rand()%66;
			snow[num].x=a[i];
			snow[num].y=0;
				num++;
		}
		for(i=0;i<num;i++)
		{
			snow[i].y+=snow[i].speed;
			DrawPixel(snow[i].x,snow[i].y+1);
			DrawPixel(snow[i].x+1,snow[i].y);
			DrawPixel(snow[i].x,snow[i].y);
			DrawPixel(snow[i].x-1,snow[i].y);
			DrawPixel(snow[i].x,snow[i].y-1);
			if(snow[i].y>63)
			{
				snow[i].y=0;		
			}	
		}
		DelayMs(30);
		UpdateScreen();
		ClearScreen();
	}
}

