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
#include "UART.h"

#define USART1_RX_BUFFER_SIZE  128
u8 receive_data[USART1_RX_BUFFER_SIZE ];
void DMA_init(void)
{
   DMA_InitTypeDef    DMA_Initstructure;
   /*����DMAʱ��*/
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
   /*DMA����*/
   DMA_Initstructure.DMA_PeripheralBaseAddr =  (u32)(&USART1->DR);;
   DMA_Initstructure.DMA_MemoryBaseAddr     = (u32)receive_data;
   DMA_Initstructure.DMA_DIR = DMA_DIR_PeripheralSRC;
   DMA_Initstructure.DMA_BufferSize = USART1_RX_BUFFER_SIZE;
   DMA_Initstructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
   DMA_Initstructure.DMA_MemoryInc =DMA_MemoryInc_Enable;
   DMA_Initstructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
   DMA_Initstructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
   DMA_Initstructure.DMA_Mode = DMA_Mode_Normal;
   DMA_Initstructure.DMA_Priority = DMA_Priority_VeryHigh;//DMA_Priority_High;
   DMA_Initstructure.DMA_M2M = DMA_M2M_Disable;
   DMA_Init(DMA1_Channel5,&DMA_Initstructure);
	 
	 DMA_ClearFlag(DMA1_FLAG_TC5);
	 DMA_ITConfig(DMA1_Channel5,DMA_IT_TC,ENABLE);
	 DMA_Cmd(DMA1_Channel5,ENABLE);  
}



void USART1_Init(unsigned long bound)
{
  NVIC_InitTypeDef NVIC_InitStructure;//����NVIC��ʼ���ṹ��
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  
  USART_InitStructure.USART_BaudRate = bound;//
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8bits
  USART_InitStructure.USART_StopBits = USART_StopBits_1;//stop bit is 1
  USART_InitStructure.USART_Parity = USART_Parity_No;//no parity
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//no Hardware Flow Control
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//enable tx and rx
  USART_Init(USART1, &USART_InitStructure);//
  
  //USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//rx interrupt is enable	
  //USART_Cmd(USART1, ENABLE);
	USART_ITConfig(USART1,USART_IT_IDLE, ENABLE);//������⴮�ڿ���״̬�ж�
	USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);//-------USART_DMACmd(LUMMOD_UART, USART_DMAReq_Rx, ENABLE); // ��������DMA����
	USART_Cmd(USART1,ENABLE);
	DMA_init();	
  
  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//���ȼ����2������μ�misc.h line80
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//�����ж�1����Ӧɽ����λ����������
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


void UART1_Send(unsigned char tx_buf)
{
  while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);//���������fputcʱ��һ����
  USART_SendData(USART1 , tx_buf);//�����ַ�������ĵ����ַ�
  while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
}

void USART1_Send(unsigned char *tx_buf, int len)
{
  USART_ClearFlag(USART1, USART_FLAG_TC);
  USART_ClearITPendingBit(USART1,USART_FLAG_TXE);
  while(len--)
  {
    USART_SendData(USART1, *tx_buf);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != 1);
    USART_ClearFlag(USART1, USART_FLAG_TC);
    USART_ClearITPendingBit(USART1, USART_FLAG_TXE);
    tx_buf++;
  } 
}


//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
//#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
    
void _sys_exit(int x) { x = x; }//����_sys_exit()�Ա���ʹ�ð�����ģʽ 

int fputc(int ch, FILE *f)//�ض���fputc���� 
{      
  USART_SendData(USART1, (unsigned char) ch);
  while (!(USART1->SR & USART_FLAG_TXE));
  return (ch);
}
#endif 


//void USART1_IRQHandler(void)
//{ 
//  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
//  {
//    //NCLink_Data_Prase_Prepare(USART_ReceiveData(USART1));
//		//NRF_TxPacket_AP(buf,cnt);
//    USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//  }
//}

//u8 rxd1_buf[512];			//��������
//u8 rxd1_len;				//�������ݳ���
//u8 rxd1_flag;				//���ձ�־

//void USART1_IRQHandler(void)                	
//{
//	u8 clear = clear;	//����������ⵯ��clear������ûʹ�õľ���
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)		//�����ж�
//	{
//		//if(rxd1_len<32)
//		{
//			rxd1_buf[rxd1_len++] = USART1->DR;						//�ѽ��յ������ݴ浽rxd1_buf����
//		}
//		//else
//		{
//			//clear = USART1->DR;
//		}
//  }
//	else if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)	//�����߿�����˵��һ�����ݽ�������
//	{
//		clear = USART1->SR;										//���Ĵ����͵�����Ĵ���
//		clear = USART1->DR;										//���Ĵ����͵�����Ĵ���
//		rxd1_flag = 1;											  //���ڽ��ձ�־λ��1
//		
////		NRF_TxPacket_AP(rxd1_buf, rxd1_len);//NRF24L01��������
////		rxd1_len = 0;												//�������ݳ�����0
////		rxd1_flag = 0;									  	//���ڽ��ձ�־λ��0
//		
//		if(rxd1_flag==1)
//		{
//			NRF_TxPacket_AP(rxd1_buf, rxd1_len);						//NRF24L01��������
//			rxd1_len = 0;											//�������ݳ�����0
//			rxd1_flag = 0;									  //���ڽ��ձ�־λ��0
//		}
//		
//	}
//	USART_ClearITPendingBit(USART1,USART_IT_ORE);				//���USART1_ORE��־λ
//}





void USART1_IRQHandler(void)
{
	unsigned char num=0;
	if(USART_GetITStatus(USART1,USART_IT_IDLE) == SET)
	{
		 num = USART1->SR;
		 num = USART1->DR; //��USART_IT_IDLE��־
		 DMA_Cmd(DMA1_Channel5,DISABLE);    //�ر�DMA
		
//		DMA_ClearITPendingBit(DMA1_IT_TC2);	// Clear Transfer Complete flag
//		DMA_ClearITPendingBit(DMA1_IT_TE2);	// Clear Transfer error flag

		 num = 128 -  DMA_GetCurrDataCounter(DMA1_Channel5);//�õ������������ݸ���  
		 //receive_data[num] = '\0';
		 DMA1_Channel5->CNDTR=USART1_RX_BUFFER_SIZE;//�������ý������ݸ���
		 DMA_Cmd(DMA1_Channel5,ENABLE);  //����DMA
		 //printf("%s ",receive_data );
     NRF_TxPacket_AP(receive_data, num);//NRF24L01��������		
		 //NRF24L01_TxPacket(receive_data, num);
	}
}














DMA_InitTypeDef DMA_InitStructure;
uint16_t DMA1_MEM_LEN;//����DMAÿ�����ݴ��͵ĳ���
/*
DMA1�ĸ�ͨ����������Ĵ�����ʽ�ǹ̶���,���Ҫ���ݲ�ͬ��������޸�
�Ӵ洢��->����ģʽ/8λ���ݿ��/�洢������ģʽ
DMA_CHx:DMAͨ��CHx      cpar:�����ַ
cmar:�洢����ַ         cndtr:���ݴ�����
*/
void Quad_DMA_Config(DMA_Channel_TypeDef* DMA_CHx,uint32_t cpar,uint32_t cmar,uint16_t cndtr)
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//ʹ��DMA����
  DMA_DeInit(DMA_CHx);   											        //��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ
  DMA1_MEM_LEN=cndtr;
  DMA_InitStructure.DMA_PeripheralBaseAddr = cpar;  //DMA�������ַ
  DMA_InitStructure.DMA_MemoryBaseAddr =cmar;				//DMA�ڴ����ַ
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;//������Ϊ���ݴ����Ŀ�ĵ�
  DMA_InitStructure.DMA_BufferSize = cndtr;  												//DMAͨ����DMA����Ĵ�С
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //�����ַ�Ĵ�������
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  					//�ڴ��ַ�Ĵ�������
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//���ݿ��Ϊ8λ
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;        //���ݿ��Ϊ8λ
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  									       //��������������ģʽ
  DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;                  //DMAͨ�� xӵ�������ȼ�
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                           //DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
  DMA_Init(DMA_CHx, &DMA_InitStructure);//����DMA_InitStruct��ָ���Ĳ�����ʼ��DMA��ͨ��USART1_Tx_DMA_Channel����ʶ�ļĴ���
}

void Quad_DMA_Enable(DMA_Channel_TypeDef*DMA_CHx)//����һ��DMA����
{
  DMA_Cmd(DMA_CHx, DISABLE );
  //�ر�USART1 TX DMA1��ָʾ��ͨ��
  DMA_InitStructure.DMA_BufferSize =DMA1_MEM_LEN;
  DMA_Init(DMA1_Channel4, &DMA_InitStructure);
  DMA_Cmd(DMA_CHx, ENABLE);  //ʹ��USART1 TX DMA1 ��ָʾ��ͨ��
}

void Quad_DMA1_USART1_SEND(u32 SendBuff,u16 len)//DMA---USART1����
{
  Quad_DMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,len);//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,����len.
  USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  Quad_DMA_Enable(DMA1_Channel4);
  //while(DMA_GetFlagStatus(DMA1_FLAG_TC4) != SET);
  //DMA_ClearFlag(DMA1_FLAG_TC4);//���������ɱ�־
}

void USART1_Send_Dma(uint8_t *dma_buf,uint16_t dma_cnt)
{
	Quad_DMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)dma_buf,dma_cnt);//DMA1ͨ��4,����Ϊ����1,�洢��Ϊdma_buf,����dma_cnt
  USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  Quad_DMA_Enable(DMA1_Channel4);
}



#define USART3_RX_BUFFER_SIZE  128
u8 receive_data3[USART3_RX_BUFFER_SIZE ];


void USART3_DMA_Init()
{
	DMA_InitTypeDef DMA_InitStructure;	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);                      //ʹ��DMA1ʱ��  
	DMA_DeInit(DMA1_Channel3);                                              //��ʼ��DMA1ͨ��3  ����3����ͨ��
	DMA_InitStructure.DMA_PeripheralBaseAddr = 0x40004804;                  //����3�������ݵĵ�ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)receive_data3;      //���ݴ�ŵĸ���
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      //���ݴ��ͷ���  ����3��Ϊ����Դ
	DMA_InitStructure.DMA_BufferSize = USART3_RX_BUFFER_SIZE;                    //�������ݸ���       
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        //��Χ�豸 ����3 ��ַ������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // DMA�洢��ַ����
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //��Χ�豸 ����3 ���ݿ�� 8bits
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;         //DMA�洢 ���ݿ�� 8bits
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         //ѭ����ȡ����
	//DMA_Mode_Normal��ֻ����һ�Σ�, DMA_Mode_Circular ����ͣ�ش��ͣ�
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;                   //����3ͨ������Ϊ�е�
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            //�ر��ڴ浽�ڴ�
	DMA_Init(DMA1_Channel3, &DMA_InitStructure);
	 
	 
	USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);  //ʹ�ܴ���3 DMA����
	DMA_Cmd(DMA1_Channel3, ENABLE);
} 
 

void USART3_Init(unsigned long bound)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  USART_InitStructure.USART_BaudRate = bound;//
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8bits
  USART_InitStructure.USART_StopBits = USART_StopBits_1;//stop bit is 1
  USART_InitStructure.USART_Parity = USART_Parity_No;//no parity
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//no Hardware Flow Control
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//enable tx and rx
  USART_Init(USART3, &USART_InitStructure);//

	
	USART_ITConfig(USART3,USART_IT_TC,DISABLE);  //�رշ����ж� 
	USART_ITConfig(USART3,USART_IT_RXNE,DISABLE);//�رս����ж�  
	USART_ITConfig(USART3,USART_IT_IDLE,DISABLE); //�������߿����ж� 
	USART_Cmd(USART3, ENABLE);	      // ʹ�� USART3
	//USART3_DMA_Init();	
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
}

void USART3_Send(unsigned char tx_buf)
{
  while(USART_GetFlagStatus(USART3, USART_FLAG_TC) != 1);
  USART_SendData(USART3, tx_buf);
  USART_ClearFlag(USART3, USART_FLAG_TC);
  USART_ClearITPendingBit(USART3, USART_FLAG_TXE);
}
void UART3_Send(unsigned char *tx_buf, int len)
{
  USART_ClearFlag(USART3, USART_FLAG_TC);
  USART_ClearITPendingBit(USART3, USART_FLAG_TXE);
  while(len--)
  {
    USART_SendData(USART3, *tx_buf);
    while(USART_GetFlagStatus(USART3, USART_FLAG_TC) != 1);
    USART_ClearFlag(USART3, USART_FLAG_TC);
    USART_ClearITPendingBit(USART3, USART_FLAG_TXE);
    tx_buf++;
  }
}



void USART3_IRQHandler(void)                	
{
	unsigned char num=0;
	if(USART_GetITStatus(USART3, USART_IT_IDLE) != RESET)		//����3	���߿���	
	{
  	USART_ClearITPendingBit(USART3, USART_IT_IDLE);  //������λ
		DMA_Cmd(DMA1_Channel3, DISABLE);//�ر�DMA1ͨ��3
    num = USART3_RX_BUFFER_SIZE -  DMA_GetCurrDataCounter(DMA1_Channel3);//�õ������������ݸ��� 
		DMA1_Channel3->CNDTR=USART3_RX_BUFFER_SIZE;//�������ý������ݸ���//DMA_SetCurrDataCounter(DMA1_Channel3,GPS_Rev_Buf_Size);  //�������ݸ��� 
		DMA_Cmd(DMA1_Channel3, ENABLE);                          //����DMA1ͨ��3
    NRF_TxPacket_AP(receive_data3, num);//NRF24L01��������		
	}	
}

