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
	
	��c�ļ����ڶ���ɫ���в���
	��������Ҫ�ǻ�������(һ��Ϊ��)�����(һ��Ϊ��)����ɫ
	(��oled.font�л���һ�����屳������ɫ(һ��Ϊ��))
	�ڻ��߻�ͼ�ʹ��ʱ������ʴ��ļ�������ȡ������ɫ
*/

#include "oled_color.h"

//������Ҫ�������Լ�����������ɫ ���ֱ�����ɫ��
static Type_color _Draw=pix_white;
static Type_color _fill=pix_white;


void SetDrawColor(Type_color value)	//���ǻ��� ��������ɫ
{
	_Draw=value;
}
Type_color GetDrawColor(void)
{
	return _Draw;
}

void SetFillcolor(Type_color value)	//������� ʵ��ͼ���ڵ���ɫ
{
	_fill=value;
}
Type_color GetFillColor(void)
{
	return _fill;
}
