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
#include "rc.h"

void Tim1_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;//����NVIC��ʼ���ṹ��

  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_DeInit(TIM1);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  TIM_TimeBaseStructure.TIM_Period=2500-1;
  TIM_TimeBaseStructure.TIM_Prescaler= (systemclk_mhz-1);
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
  TIM_ClearFlag(TIM1, TIM_FLAG_Update);
  TIM_ITConfig(TIM1,TIM_IT_Update|TIM_IT_Trigger,ENABLE);
  TIM_Cmd(TIM1, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);   
}


//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period = 1000-1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ     ������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler =systemclk_mhz-1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx����

}



uint16_t rc_gps_cnt=0;
rc RC_Data;
void RC_All_Init(void)
{	
	RC_Data.rcdata[RC_ROLL_CHANNEL]=1500;
	RC_Data.rcdata[RC_PITCH_CHANNEL]=1500;
	RC_Data.rcdata[RC_THR_CHANNEL]=1000;
	RC_Data.rcdata[RC_YAW_CHANNEL]=1500;
			
	RC_Data.rcdata[RC_SWA_CHANNEL]=1000;
	RC_Data.rcdata[RC_SWB_CHANNEL]=1000;
	RC_Data.rcdata[RC_SWC_CHANNEL]=1000;
	RC_Data.rcdata[RC_SWD_CHANNEL]=1000;

	RC_Data.rcdata[RC_VRA_CHANNEL]=1000;
	RC_Data.rcdata[RC_VRB_CHANNEL]=1000;	
	
	RC_Data.lose_ctrl_protect=0;
	RC_Data.lose_ctrl_protect_channel=7;
	RC_Data.lose_ctrl_protect_value=1000;
	
	Tim1_Init();
	TIM3_Init();
}

void Remote_Ctrl_Prase(void)
{
  if(g_NRFRevData[0]==0xA2&&g_NRFRevData[1]==0xA1
	 &&g_NRFRevData[27]==0xFC&&g_NRFRevData[28]==0xFF)
	{	
		if(g_NRFRevData[2]==0x01)
		{
			uint8_t sum1 = 0,sum2 = 0;
			for(uint8_t i=0;i<29;i++)  sum1 ^= g_NRFRevData[i];
			for(uint8_t i=0;i<29;i++)  sum2 += g_NRFRevData[i];
			if(sum1!=g_NRFRevData[29])  return;
			if(sum2!=g_NRFRevData[30])  return;
			
			
			RC_Data.rcdata[RC_ROLL_CHANNEL]=g_NRFRevData[3]<<8|g_NRFRevData[4];
			RC_Data.rcdata[RC_PITCH_CHANNEL]=g_NRFRevData[5]<<8|g_NRFRevData[6];
			RC_Data.rcdata[RC_THR_CHANNEL]=g_NRFRevData[7]<<8|g_NRFRevData[8];
			RC_Data.rcdata[RC_YAW_CHANNEL]=g_NRFRevData[9]<<8|g_NRFRevData[10];
					
			RC_Data.rcdata[RC_SWA_CHANNEL]=g_NRFRevData[11]<<8|g_NRFRevData[12];
			RC_Data.rcdata[RC_SWB_CHANNEL]=g_NRFRevData[13]<<8|g_NRFRevData[14];
			RC_Data.rcdata[RC_SWC_CHANNEL]=g_NRFRevData[15]<<8|g_NRFRevData[16];
			RC_Data.rcdata[RC_SWD_CHANNEL]=g_NRFRevData[17]<<8|g_NRFRevData[18];

			RC_Data.rcdata[RC_VRA_CHANNEL]=g_NRFRevData[19]<<8|g_NRFRevData[20];
			RC_Data.rcdata[RC_VRB_CHANNEL]=g_NRFRevData[21]<<8|g_NRFRevData[22];
			
			
			RC_Data.lose_ctrl_protect=g_NRFRevData[23];
			RC_Data.lose_ctrl_protect_channel=g_NRFRevData[24];
			RC_Data.lose_ctrl_protect_value=g_NRFRevData[25]<<8|g_NRFRevData[26];
		}
		else if(g_NRFRevData[2]==0x02)
		{
			RC_Data.gps_ok=g_NRFRevData[3];
			RC_Data.gps_lng =((int32_t)(*(g_NRFRevData+4)<<24)|(*(g_NRFRevData+5)<<16)|(*(g_NRFRevData+6)<<8)|*(g_NRFRevData+7));
			RC_Data.gps_lat =((int32_t)(*(g_NRFRevData+8)<<24)|(*(g_NRFRevData+9)<<16)|(*(g_NRFRevData+10)<<8)|*(g_NRFRevData+11));
			
			if(RC_Data.gps_ok==1)
			{
				NCLink_GS_Send_GPS_Guide_Flight(RC_Data.gps_lng,RC_Data.gps_lat);
				rc_gps_cnt++;
			}
		}
		RC_Data.prase_success=1;
	}
  else
	{
	  RC_Data.prase_success=0;
	}		
}


uint16_t sbus_output_cnt=0;
uint32_t lose_ctrl_cnt=0;
systime  tim1_dealt;
void TIM1_UP_IRQHandler(void)//5msˢ��һ��
{
  if( TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET )
  {
		Get_Systime(&tim1_dealt);
   lose_ctrl_cnt++;
	 if(lose_ctrl_cnt>5000) lose_ctrl_cnt=5000;
	 if((lose_ctrl_cnt>=1000||nrf_soft_rssi<10)//�ź�ǿ��С��10% 
		 &&RC_Data.lose_ctrl_protect==1)//����2.5Sδ��⵽ң�������ݣ�ִ��ʧ�ر���
	 {
	   RC_Data.rcdata[RC_Data.lose_ctrl_protect_channel-1]=RC_Data.lose_ctrl_protect_value;
	 }
 
	 if(Transparent_Update==1&&RC_Data.prase_success==0)
	 {
		 Transparent_Update=0;
		 USART1_Send_Dma(Transparent_Data,Transparent_Cnt);
	 }

	 
    sbus_output_cnt++;
		if(sbus_output_cnt%6==0)//15ms
		{
		  sbus_output();
		}
		Bling_Working(0);
    TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
  }
}

systime  tim3_dealt;
//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ
	{
		Get_Systime(&tim3_dealt);
		//NRF24L01_State_Check(g_NRFRevData);
		nrf_soft_rssi_get();
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ
	}
}


