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
*               �汾��׷����RC����OPENRC_HP_V1.0.1
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
#include "ppm.h"

#define ppm_offset (0)
#define ppm_scale 1


#define PPM_OUT_H  {GPIO_WriteBit(GPIOC,GPIO_Pin_8,Bit_SET)  ;GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_SET);}	//����ߵ�ƽ
#define PPM_OUT_L  {GPIO_WriteBit(GPIOC,GPIO_Pin_8,Bit_RESET);GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_RESET);}//����͵�ƽ


//��ʱ����ʼ����PPM������ų�ʼ��
void ppm_init(void)
{
		GPIO_InitTypeDef  GPIO_InitStructure;  	  
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
	
	
		NVIC_InitTypeDef NVIC_InitStructure;//����NVIC��ʼ���ṹ��
	
	  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	  TIM_DeInit(TIM3);
		TIM_TimeBaseStructure.TIM_Period=500-1;
		TIM_TimeBaseStructure.TIM_Prescaler=systemclk_mhz/ppm_scale-1;
		TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
		TIM_ClearFlag(TIM3, TIM_FLAG_Update);
		TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
		TIM_Cmd(TIM3, ENABLE);

	
	
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure); 
		PPM_OUT_L;
}



systime  tim3_dealt;
uint16_t ppm_test[8]={1000,1500,1400,1300,1600,1750,1850,1950};
void TIM3_IRQHandler(void)
{
	uint16_t time=0;
	static uint8_t ppm_count=1;  //�������
	static uint16_t toal_time=0;//�ܵ�ͨ����+�͵�ƽʱ��
  if( TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET )
  {
    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);		
		switch(ppm_count)
    {
    case 1://��һͨ����ʼ  -----------------------------��1��
        PPM_OUT_H;
				time=RC_Data.rcdata[0]-500;//(ͨ���ߵ�ƽʱ����500us~1500us��
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 2://��һͨ������,��ʼ0.5ms�͵�ƽ---------------��2��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 3://�ڶ�ͨ����ʼ------------------------------��3��
        PPM_OUT_H;
				time=RC_Data.rcdata[1]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 4://�ڶ�ͨ������,��ʼ0.5ms�͵�ƽ
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 5://����ͨ����ʼ
        PPM_OUT_H;
				time=RC_Data.rcdata[2]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 6://����ͨ������,��ʼ0.5ms�͵�ƽ
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 7://����ͨ����ʼ
        PPM_OUT_H;
        time=RC_Data.rcdata[3]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 8://����ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 9://��5ͨ����ʼ
        PPM_OUT_H;
        time=RC_Data.rcdata[4]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 10://��5ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 11://��6ͨ����ʼ
        PPM_OUT_H;
        time=RC_Data.rcdata[5]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 12://��6ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 13://��7ͨ����ʼ
        PPM_OUT_H;
        time=RC_Data.rcdata[6]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 14://��7ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 15://��8ͨ����ʼ
        PPM_OUT_H;
        time=RC_Data.rcdata[7]-500;
				toal_time+=time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 16://��8ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
        PPM_OUT_L;
				toal_time+=500;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
        ppm_count++;
        break;
    case 17://8·�ź�ȫ��������20msʣ�µ�ʱ��ߵ�ƽ----------��5��
        PPM_OUT_H;
				time=19500-toal_time;
		    time=ppm_scale*time+ppm_offset;
        TIM_SetAutoreload(TIM3,(uint16_t)(time-1));
        ppm_count++;
        break;
    case 18://���¿�ʼ---------------------------------��6��
        PPM_OUT_L;
        TIM_SetAutoreload(TIM3,500*ppm_scale-1);
				toal_time=0;//ͨ���ߵ�ƽ���㣬���¿�ʼ
        ppm_count=1;
		    Get_Systime(&tim3_dealt);
				break;
    }		
  }
}
//void TIM2_IRQHandler(void)
//{
//	uint16_t time=0;
//	static uint8_t ppm_count=1;  //�������
//	static uint16_t toal_time=0;//�ܵ�ͨ����+�͵�ƽʱ��
//  if( TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET )
//  {		
//		switch(ppm_count)
//    {
//    case 1://��һͨ����ʼ  -----------------------------��1��
//        PPM_OUT_H;
//				time=RC_Data.rcdata[0]-500;//(ͨ���ߵ�ƽʱ����500us~1500us��
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 2://��һͨ������,��ʼ0.5ms�͵�ƽ---------------��2��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 3://�ڶ�ͨ����ʼ------------------------------��3��
//        PPM_OUT_H;
//				time=RC_Data.rcdata[1]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 4://�ڶ�ͨ������,��ʼ0.5ms�͵�ƽ
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 5://����ͨ����ʼ
//        PPM_OUT_H;
//				time=RC_Data.rcdata[2]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 6://����ͨ������,��ʼ0.5ms�͵�ƽ
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 7://����ͨ����ʼ
//        PPM_OUT_H;
//        time=RC_Data.rcdata[3]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 8://����ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 9://��5ͨ����ʼ
//        PPM_OUT_H;
//        time=RC_Data.rcdata[4]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 10://��5ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 11://��6ͨ����ʼ
//        PPM_OUT_H;
//        time=RC_Data.rcdata[5]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 12://��6ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 13://��7ͨ����ʼ
//        PPM_OUT_H;
//        time=RC_Data.rcdata[6]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 14://��7ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 15://��8ͨ����ʼ
//        PPM_OUT_H;
//        time=RC_Data.rcdata[7]-500;
//				toal_time+=time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 16://��8ͨ������,��ʼ0.5ms�͵�ƽ---------------��4��
//        PPM_OUT_L;
//				toal_time+=500;
//        TIM_SetAutoreload(TIM2,499);
//        ppm_count++;
//        break;
//    case 17://8·�ź�ȫ��������20msʣ�µ�ʱ��ߵ�ƽ----------��5��
//        PPM_OUT_H;
//				time=19500-toal_time;
//        TIM_SetAutoreload(TIM2,(uint16_t)(time-1));
//        ppm_count++;
//        break;
//    case 18://���¿�ʼ---------------------------------��6��
//        PPM_OUT_L;
//        TIM_SetAutoreload(TIM2,499);
//				toal_time=0;//ͨ���ߵ�ƽ���㣬���¿�ʼ
//        ppm_count=1;
//		    Get_Systime(&tim2_dealt);
//				break;
//    }
//    TIM_ClearITPendingBit(TIM2,TIM_IT_Update);		
//  }
//}

