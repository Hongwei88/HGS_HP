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
#include "sbus.h"

#define LEN_DMA_RECV_BUF 256
u8 dma_send_buf[LEN_DMA_RECV_BUF];


void sbus_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO
                         |RCC_APB2Periph_GPIOA , ENABLE);//����2
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);//����2 ����
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//  //	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  
  USART_InitStructure.USART_BaudRate = 100000;//
  USART_InitStructure.USART_WordLength = USART_WordLength_9b;//8bits
  USART_InitStructure.USART_StopBits = USART_StopBits_2;//stop bit is 1
  USART_InitStructure.USART_Parity = USART_Parity_Even;//no parity
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//no Hardware Flow Control
  USART_InitStructure.USART_Mode = USART_Mode_Tx;//enable tx and rx
  USART_Init(USART2, &USART_InitStructure);//
  
//  NVIC_InitTypeDef NVIC_InitStructure;//����NVIC��ʼ���ṹ��
//  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//�����ж�2
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure); 

	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Channel7);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART2->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)dma_send_buf;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = 0;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel7, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel7, DISABLE);
	DMA_ClearFlag(DMA1_FLAG_GL7);

  USART_ITConfig(USART2,USART_IT_RXNE,DISABLE);//rx interrupt is enable
  USART_Cmd(USART2, ENABLE);
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
}


void USART2_Send(unsigned char *tx_buf, int len)
{
  USART_ClearFlag(USART2, USART_FLAG_TC);
  USART_ClearITPendingBit(USART2, USART_FLAG_TXE);
  while(len--)
  {
    USART_SendData(USART2, *tx_buf);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TC) != 1);
    USART_ClearFlag(USART2, USART_FLAG_TC);
    USART_ClearITPendingBit(USART2, USART_FLAG_TXE);
    tx_buf++;
  }
}


void USART2_Send_DMA(u8 *bytes, u8 bytes_len)
{
	DMA_Cmd(DMA1_Channel7, DISABLE);
	memcpy(dma_send_buf, bytes, bytes_len);
	DMA_SetCurrDataCounter(DMA1_Channel7, bytes_len);
	DMA_Cmd(DMA1_Channel7, ENABLE);
	//while(DMA_GetCurrDataCounter(DMA1_Channel7));
	//while(USART_GetFlagStatus(USART2, USART_FLAG_TC) != SET);
}


void UART2_Send(unsigned char tx_buf)
{
  while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);//���������fputcʱ��һ����
  USART_SendData(USART2 , tx_buf);//�����ַ�������ĵ����ַ�
  while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);
}



void USART2_IRQHandler(void)//����GPS�����UBLOX  PVTЭ��
{
  //unsigned char ch;
  if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
  { 
		//ch=USART_ReceiveData(USART2);
	}
}

systime  sbus_dealt;
uint16_t channels[16]={0};
uint8_t packet[25];
void sbus_output()
{
	  Get_Systime(&sbus_dealt);
		uint8_t stateByte = 0x00;
		if(nrf_sbus_update==0) 
		{
			stateByte |= SBUS_STATE_SIGNALLOSS;
		}
		if(nrf_soft_rssi<30)//�ź�ǿ��30% 
		{
			stateByte |= SBUS_STATE_FAILSAFE;
		}
		for(uint16_t i=0;i<16;i++)
		{
			channels[i]=(uint16_t)((float)(RC_Data.rcdata[i]-SBUS_SCALE_OFFSET)/SBUS_SCALE_FACTOR+0.5f);
		}
				
    packet[0] = SBUS_FRAME_HEADER; 
		packet[1] = (uint8_t) (channels[0] & 0x07FF);
    packet[2] = (uint8_t) ((channels[0] & 0x07FF)>>8 | (channels[1] & 0x07FF)<<3);
    packet[3] = (uint8_t) ((channels[1] & 0x07FF)>>5 | (channels[2] & 0x07FF)<<6);
    packet[4] = (uint8_t) ((channels[2] & 0x07FF)>>2);
    packet[5] = (uint8_t) ((channels[2] & 0x07FF)>>10 | (channels[3] & 0x07FF)<<1);
    packet[6] = (uint8_t) ((channels[3] & 0x07FF)>>7 | (channels[4] & 0x07FF)<<4);
    packet[7] = (uint8_t) ((channels[4] & 0x07FF)>>4 | (channels[5] & 0x07FF)<<7);
    packet[8] = (uint8_t) ((channels[5] & 0x07FF)>>1);
    packet[9] = (uint8_t) ((channels[5] & 0x07FF)>>9 | (channels[6] & 0x07FF)<<2);
    packet[10] = (uint8_t) ((channels[6] & 0x07FF)>>6 | (channels[7] & 0x07FF)<<5);
    packet[11] = (uint8_t) ((channels[7] & 0x07FF)>>3);
    packet[12] = (uint8_t) ((channels[8] & 0x07FF));
    packet[13] = (uint8_t) ((channels[8] & 0x07FF)>>8 | (channels[9] & 0x07FF)<<3);
    packet[14] = (uint8_t) ((channels[9] & 0x07FF)>>5 | (channels[10] & 0x07FF)<<6);  
    packet[15] = (uint8_t) ((channels[10] & 0x07FF)>>2);
    packet[16] = (uint8_t) ((channels[10] & 0x07FF)>>10 | (channels[11] & 0x07FF)<<1);
    packet[17] = (uint8_t) ((channels[11] & 0x07FF)>>7 | (channels[12] & 0x07FF)<<4);
    packet[18] = (uint8_t) ((channels[12] & 0x07FF)>>4 | (channels[13] & 0x07FF)<<7);
    packet[19] = (uint8_t) ((channels[13] & 0x07FF)>>1);
    packet[20] = (uint8_t) ((channels[13] & 0x07FF)>>9 | (channels[14] & 0x07FF)<<2);
    packet[21] = (uint8_t) ((channels[14] & 0x07FF)>>6 | (channels[15] & 0x07FF)<<5);
    packet[22] = (uint8_t) ((channels[15] & 0x07FF)>>3);
    packet[23] = 0x00;
    packet[24] = SBUS_FRAME_FOOTER;	
    //USART2_Send(packet,25);
		USART2_Send_DMA(packet,25);
		nrf_sbus_update=0;
}


