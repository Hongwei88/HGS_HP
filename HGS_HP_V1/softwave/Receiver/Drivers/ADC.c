/* Copyright (c)  2020-2030 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                ��Դ����������ѣ������ߵ���ʷ�Ѿ�֤�����ڹ�����������£���������Ŀ�Դ������������˰����ߣ��Է��ز�����
								Ŀ���Ƶķ�ʽ�в�ͨ���õĿ�Դ��Ŀ��Ҫ��רְ��Ա�����ۺ�����ְ��ֽ�ѧ��ͳ���û�����������ʵ������ɶԲ�
								Ʒ��һ�δ���������������������ۺϿ��ǣ������ɿؿ�Դ�����У������������˾���漤��ܴ��룬�汾������ʵ��
								���ܣ����ڹ�˾��Ʒ���������������Ӱ��ͻ�ѧϰ���������ȫ�����Ÿ��ͻ�ѧϰ���ͻ���ֲ�Ͷ��ο��������뱣����
								���Ȩ��
-----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ��������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------
*                                                 Ϊʲôѡ���������£�
*                                         �ж����ļ۸�������׵Ŀ�Դ�ɿأ�
*                                         ����ҵ������֮������µ��ۺ����
*                                         ׷�����û����飬��Ч����ѧϰ֮·��
*                                         ���²��ٹµ�������������տ�Դ�߶ȣ�
*                                         ��Ӧ���ҷ�ƶ���٣��ٽ��������ƹ�ƽ��
*                                         ��ʱ���ܶ�����ʣ����������˹�ͬ�塣 
-----------------------------------------------------------------------------------------------------------------------
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��2��Ⱥ465082224��1��Ⱥ540707961����Ա������
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrun����С��
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               ��˾����:www.nameless.tech
*               �������¹����׿�TI��Դ�ɿ���Ƴ��ԡ�֪��ר��:https://zhuanlan.zhihu.com/p/54471146
*               �޸�����:2020/09/01                  
*               �汾��׷����RC����OPENRC_DT_V1.0.1
*               ��Ȩ���У�����ؾ���
*               Copyright(C) 2020-2030 �人�������¿Ƽ����޹�˾ 
*               All rights reserved
-----------------------------------------------------------------------------------------------------------------------
*               ��Ҫ��ʾ��
*               �����Ա�����ת�ֵķɿء��������ѡ�����ѧ�ܵĶ����Խ��ۺ�Ⱥѧϰ������
*               ����ֱ�����������������������ϣ��������´�����������Ȩ�����˲��ý�
*               ���ϴ��봫���Ϲ��������أ�������ı��ΪĿ���������ϴ��룬�����д˲�
*               ���ߣ���˾����ǰ��֪����1���ڼ�ʱ�����������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/
#include "main.h"
#include "ADC.h"

uint16_t ADC_value[7];

/* �˿����ó�ʼ�� */
void ADC_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_initStructure;    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|
	                              GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;	    
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_AIN;								    
	GPIO_Init(GPIOA,&GPIO_initStructure);	
}


/* adc���� */ 
void ADC_Config(void)
{
		ADC_InitTypeDef ADC_initStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);

		ADC_initStructure.ADC_ContinuousConvMode = DISABLE;					          //����ת��ģʽ��ÿ���ɶ�ʱ��4ͨ��4����������ʼ		
		ADC_initStructure.ADC_DataAlign = ADC_DataAlign_Right;		          	//�����Ҷ���				
		ADC_initStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T4_CC4;	//�ⲿ��ʱ��4ͨ��4��ʱ����	
		ADC_initStructure.ADC_Mode = ADC_Mode_Independent;							
		ADC_initStructure.ADC_NbrOfChannel = 7;										
		ADC_initStructure.ADC_ScanConvMode = ENABLE;		                      //ɨ��ģʽ						
		ADC_Init(ADC1,&ADC_initStructure);

		ADC_Cmd(ADC1,ENABLE);

		ADC_DMACmd(ADC1,ENABLE);

		RCC_ADCCLKConfig(RCC_PCLK2_Div8);                           //ADCʱ�ӷ�Ƶ											
																																//ͨ�����ã�����ʱ������
		ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_71Cycles5);	
		ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_71Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_71Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_71Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_4,5,ADC_SampleTime_71Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_5,6,ADC_SampleTime_71Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_6,7,ADC_SampleTime_71Cycles5);

		ADC_ResetCalibration(ADC1);	                                              //��λУ׼				
		while(ADC_GetCalibrationStatus(ADC1));		                                //�ȴ�
		ADC_StartCalibration(ADC1);					                                			//����У׼
		while(ADC_GetCalibrationStatus(ADC1));		                                //�ȴ�У׼���

		ADC_ExternalTrigConvCmd(ADC1,ENABLE);	                                    //�ⲿ����ʹ��
}


void ADC_DMA_Config(void)
{
	DMA_InitTypeDef DMA_initStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_initStructure.DMA_BufferSize = 7;										
	DMA_initStructure.DMA_DIR = DMA_DIR_PeripheralSRC;	                        //���䷽������->�ڴ�						
	DMA_initStructure.DMA_M2M = DMA_M2M_Disable;								
  DMA_initStructure.DMA_MemoryBaseAddr = (u32)ADC_value;				        
	DMA_initStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;         //DMA������ڴ����ݴ�С������Ϊ��λ			
	DMA_initStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;						//�ڴ��ַ����
	DMA_initStructure.DMA_Mode = DMA_Mode_Circular;								
	DMA_initStructure.DMA_PeripheralBaseAddr = ((u32)&ADC1->DR);	            //�����ַ			
	DMA_initStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//DMA������������ݴ�С������Ϊ��λ
	DMA_initStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;			//�����ַ����
	DMA_initStructure.DMA_Priority = DMA_Priority_Medium;						
	DMA_Init(DMA1_Channel1,&DMA_initStructure);
    
  DMA_ClearITPendingBit(DMA1_IT_TC1);			    

	DMA_ITConfig(DMA1_Channel1,DMA_IT_TC,ENABLE);	
    
	DMA_Cmd(DMA1_Channel1,ENABLE);	
}


//��ʱ����ʼ��
void Tim4_Init(void)
{ 
	TIM_TimeBaseInitTypeDef TIM_timeBaseStucture;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_timeBaseStucture.TIM_ClockDivision = TIM_CKD_DIV1;       
	TIM_timeBaseStucture.TIM_Prescaler = 72-1;                	 
	TIM_timeBaseStucture.TIM_CounterMode = TIM_CounterMode_Up;	 
	TIM_timeBaseStucture.TIM_Period = 20000-1;		                //20ms����			
	TIM_TimeBaseInit(TIM4,&TIM_timeBaseStucture);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;			 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;	 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 5000;					        //5ms����	     
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);							 
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);			 
	
	TIM_Cmd(TIM4,ENABLE);	    
}


void ADC_Config_All(void)
{
	ADC_GPIO_Init();
	ADC_Config();
	ADC_DMA_Config();
	Tim4_Init();
}

