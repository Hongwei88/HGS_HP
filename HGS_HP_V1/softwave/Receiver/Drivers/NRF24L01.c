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
#include "NRF24L01.h"

//-----NRF24L01���ͽ��յ�ַ-----//
const u8 TX_ADDRESS[TX_ADR_WIDTH] = {'M','A','T','C','H'}; //���͵�ַ
const u8 RX_ADDRESS[RX_ADR_WIDTH] = {'M','A','T','C','H'}; //���յ�ַ

//-----NRF24L01��������-----//
u8 g_NRFRevData[RX_PLOAD_WIDTH]={0,0};
//-----NRF24L01��������-----//
u8 g_NRFSendData[TX_PLOAD_WIDTH]={0};


/********************************
��������void NRF24L01_Init(void)
˵������ʼ��24L01
��ڣ���
���ڣ���
��ע����
*********************************/
void NRF24L01_Init(void)
{
	NRF24L01_CE_L; 			//ʹ��24L01
	NRF24L01_CSN_H;			//SPIƬѡȡ��  
}

/******************************
��������u8 NRF24L01_Check(void)
˵�������24L01�Ƿ����
��ڣ���
���ڣ�u8
0���ɹ�;
1��ʧ��	
��ע����
*******************************/
u8 NRF24L01_Check(void)
{
	u8 buf[5] = {0XA5,0XA5,0XA5,0XA5,0XA5}, i;
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,buf,5);//д��5���ֽڵĵ�ַ��TX_ADDRΪ��ַ��WRITE_REG_NRFΪ����
	NRF24L01_Read_Buf(TX_ADDR,buf,5);//����д��ĵ�ַ  
	for (i = 0; i < 5; i++)
	if (buf[i] != 0XA5)
	break;
	if (i != 5)
	return 1;//���24L01����	
	return 0;//��⵽24L01
}

/************************************************
��������void NRF24L01_Write_Reg(u8 reg, u8 value)
˵����SPIд�Ĵ���
��ڣ�u8 reg		�Ĵ�����ַ
u8 value	��Ҫд���ֵ
���ڣ���
��ע����
************************************************/
void NRF24L01_Write_Reg(u8 reg, u8 value)
{
	NRF24L01_CSN_L;                 	//ʹ��SPI����
	SPI2_ReadWriteByte(reg);			    //���ͼĴ����ţ�������Զ�ȡ���Ĵ�����״̬
	SPI2_ReadWriteByte(value);      		//д��Ĵ�����ֵ
	NRF24L01_CSN_H;                 	//��ֹSPI����	   
}

/************************************
��������u8 NRF24L01_Read_Reg(u8 reg)
˵������ȡSPI�Ĵ���ֵ
��ڣ�u8 reg		�Ĵ�����ַ
���ڣ�u8	״̬
��ע����
*************************************/
//
//reg:Ҫ���ļĴ���
u8 NRF24L01_Read_Reg(u8 reg)
{
	u8 reg_val;
	NRF24L01_CSN_L;          				//ʹ��SPI����		
	SPI2_ReadWriteByte(reg);   				//���ͼĴ�����
	reg_val = SPI2_ReadWriteByte(0XFF);	    //��ȡ�Ĵ������ݣ�ֻ��Ҫ��ȡ�������������⴫�����ݹ�ȥ
	NRF24L01_CSN_H;          			    //��ֹSPI����		    
	return(reg_val);           				//����״ֵ̬
}

/*******************************************************
��������void NRF24L01_Read_Buf(u8 reg, u8 *pBuf, u8 len)
˵������ָ��λ�ö���ָ�����ȵ�����
��ڣ�u8 reg		�Ĵ���(λ��)
u8 *pBuf	����ָ��
u8 len		���ݳ���
���ڣ���
��ע����
*******************************************************/
void NRF24L01_Read_Buf(u8 reg, u8 *pBuf, u8 len)
{
	u8 i;

	NRF24L01_CSN_L;           							//ʹ��SPI����
	SPI2_ReadWriteByte(reg);									//���ͼĴ���ֵ(λ��)  	   
	for (i = 0; i < len; i++)
	pBuf[i] = SPI2_ReadWriteByte(0XFF);		//��������
	NRF24L01_CSN_H;       									//�ر�SPI����
}

/********************************************************
��������void NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 len)
˵������ָ��λ��дָ�����ȵ�����
��ڣ�u8 reg		�Ĵ���(λ��)
u8 *pBuf	����ָ��
u8 len		���ݳ���
���ڣ���
��ע����
********************************************************/
void NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 len)
{
	u8 i;

	NRF24L01_CSN_L;          						//ʹ��SPI����
	SPI2_ReadWriteByte(reg);							//���ͼĴ���ֵ(λ��)
	for	(i = 0; i < len; i++)
	SPI2_ReadWriteByte(*pBuf++); 			//д������	 
	NRF24L01_CSN_H;       							//�ر�SPI����
}

systime  nrf_tx_dealt;
/***************************************
��������u8 NRF24L01_TxPacket(u8 *txbuf)
˵��������NRF24L01����һ������
��ڣ�u8 *txbuf	�����������׵�ַ
���ڣ�U8	�������״��
��ע����
****************************************/
u8 NRF24L01_TxPacket(u8 *txbuf,u8 len)
{
	u8 sta;
  u16 i=0;	
	NRF24L01_CE_L;																						//Ƭѡ
	NRF24L01_Write_Buf(WR_TX_PLOAD, txbuf, len);		//д���ݵ�TX BUF  32���ֽ�TX_PLOAD_WIDTH
	NRF24L01_CE_H;//��������
	while(NRF24L01_IRQ!=0)																		//�ȴ��������
	{
		i++;
		if(i==255) break;
	}
	Get_Systime(&nrf_tx_dealt);
	sta = NRF24L01_Read_Reg(STATUS);  												//��ȡ״̬�Ĵ�����ֵ
	NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta); 					//���TX_DS��MAX_RT�жϱ�־
	if (sta & MAX_TX)																					//�ﵽ����ط�����
	{
		NRF24L01_Write_Reg(FLUSH_TX, 0xFF);											//���TX FIFO�Ĵ��� 
		return MAX_TX;
	}
	if (sta & TX_OK)																					//�������
	{
		return TX_OK;
	}
		return 0xFF;																							//����ԭ����ʧ��
}

/***************************************
��������u8 NRF24L01_RxPacket(u8 *rxbuf)
˵��������NRF24L01����һ������
��ڣ�u8 *txbuf	�����������׵�ַ
���ڣ�u8	0���������
1�����ղ��ɹ�
��ע����
****************************************/
u8 NRF24L01_RxPacket(u8 *rxbuf)
{
	u8 sta;		    							    
	sta = NRF24L01_Read_Reg(STATUS);  							//��ȡ״̬�Ĵ�����ֵ    	 
	NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS,sta); 			//���TX_DS��MAX_RT�жϱ�־
	if (sta & RX_OK)											//���յ�����
	{
	NRF24L01_Read_Buf(RD_RX_PLOAD, rxbuf, RX_PLOAD_WIDTH);	//��ȡ����
	NRF24L01_Write_Reg(FLUSH_RX, 0xFF);						//���RX FIFO�Ĵ��� 
	return 0; 
	}
	return 1;													//û�յ��κ�����
}

/*****************************************************
��������void NRF24L01_RX_Mode(void)
˵������ʼ��NRF24L01��RXģʽ
��ڣ���
���ڣ���
��ע��
����RX��ַ,дRX���ݿ��,ѡ��RFƵ��,�����ʺ�LNA HCURR
��CE��ߺ�,������RXģʽ,�����Խ���������
******************************************************/
void NRF24L01_RX_Mode(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_ClearITPendingBit(EXTI_Line12);//����жϱ�־ 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12); //ѡ���жϹܽ�PB12
	//����EXTI�ṹ��
	//���ڷ���ģʽ���Ѿ����ж����жϣ����Ե��л��ɽ���ģʽʱ����Ҫ������������
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;							//EXTI���жϿ�ͨ
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				    //����Ϊ�жϻ����¼�
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;				//�½��ش���
	EXTI_InitStructure.EXTI_LineCmd = DISABLE;							//ʹ��EXTI���ж�
	EXTI_Init(&EXTI_InitStructure);

	NRF24L01_CE_L;
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);//дRX�ڵ��ַ
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_AA,0x01);    						//ʹ��ͨ��0���Զ�Ӧ��    
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_RXADDR,0x01);						//ʹ��ͨ��0�Ľ��յ�ַ  	 
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,40);	    						//����RFͨ��Ƶ��		  
	NRF24L01_Write_Reg(WRITE_REG_NRF+RX_PW_P0,RX_PLOAD_WIDTH);				//ѡ��ͨ��0����Ч���ݿ�� 	    
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x0f);						//����TX�������,0db����,2Mbps,���������濪��   
	NRF24L01_Write_Reg(WRITE_REG_NRF+NRF24L01_CONFIG,0x0f);				//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ 
	NRF24L01_CE_H; 																																	//CEΪ��,�������ģʽ 
}

/*****************************************************************************************
��������void NRF24L01_TX_Mode(void)
˵������ʼ��NRF24L01��TXģʽ
��ڣ���
���ڣ���
��ע��
����TX��ַ,дTX���ݿ��,����RX�Զ�Ӧ��ĵ�ַ,���TX��������,ѡ��RFƵ��,�����ʺ�LNA HCURR
PWR_UP,CRCʹ��
CEΪ�ߴ���10us,����������
******************************************************************************************/
void NRF24L01_TX_Mode(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;//����EXTI�ṹ��
	//���ڽ���ģʽ�µ�IRQ��������Ϊ�ж��������ţ����Ե��л��ɷ���ģʽʱ����Ҫ���ж��������ŵĹ���ȡ��
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;//EXTI���жϿ�ͨ
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//����Ϊ�жϻ����¼�
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
	EXTI_InitStructure.EXTI_LineCmd = DISABLE;//ʧ��EXTI���ж�
	EXTI_Init(&EXTI_InitStructure);

	NRF24L01_CE_L;	    
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH); 	//����TX�ڵ��ַ,��ҪΪ��ʹ��ACK
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_AA,0x01); //ʹ��ͨ��0�Զ�Ӧ��    
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_RXADDR,0x01); //ʹ��ͨ��0�Ľ��յ�ַ  
	NRF24L01_Write_Reg(WRITE_REG_NRF+SETUP_RETR,0x1a);//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:15��
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,40);//����RFͨ��Ϊ40
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x0f);//����TX�������,0db����,2Mbps,���������濪��   
	NRF24L01_Write_Reg(WRITE_REG_NRF+NRF24L01_CONFIG,0x0e);//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�
	NRF24L01_CE_H;															    //CEΪ��,10us����������
}	

void NRF24L01_Mode(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_ClearITPendingBit(EXTI_Line12);//����жϱ�־ 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12); //ѡ���жϹܽ�PB12
	//����EXTI�ṹ��
	//���ڷ���ģʽ���Ѿ����ж����жϣ����Ե��л��ɽ���ģʽʱ����Ҫ������������
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;							//EXTI���жϿ�ͨ
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//����Ϊ�жϻ����¼�
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//�½��ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;							//ʹ��EXTI���ж�
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
	NVIC_Init(&NVIC_InitStructure); 
	

	NRF24L01_CE_L;
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);//дRX�ڵ��ַ
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_AA,0x01);    						//ʹ��ͨ��0���Զ�Ӧ��    
	NRF24L01_Write_Reg(WRITE_REG_NRF+EN_RXADDR,0x01);						//ʹ��ͨ��0�Ľ��յ�ַ
	NRF24L01_Write_Reg(WRITE_REG_NRF+SETUP_RETR,0x1a);					//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:15��	
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,40);	    						//����RFͨ��Ƶ��		  
	//NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x0f);						//����TX�������,0db����,2Mbps,���������濪��
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_SETUP,0x07); 							//����TX�������,0db����,1Mbps,���������濪��
	
//	NRF24L01_Write_Reg(WRITE_REG_NRF+RX_PW_P0,RX_PLOAD_WIDTH);	//ѡ��ͨ��0����Ч���ݿ�� 	    	   
//	NRF24L01_Write_Reg(WRITE_REG_NRF+NRF24L01_CONFIG,0x0f);			//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ 
	
//	NRF24L01_Write_Reg(WRITE_REG_NRF + NRF24L01_CONFIG, 0x0e);   		 // IRQ�շ�����жϿ���,16λCRC,������
//	NRF24L01_Write_Reg(FLUSH_TX,0xff);
//	NRF24L01_Write_Reg(FLUSH_RX,0xff);
//	SPI2_ReadWriteByte(0x50);
//	SPI2_ReadWriteByte(0x73);
//	NRF24L01_Write_Reg(WRITE_REG_NRF+0x1c,0x01);
//	NRF24L01_Write_Reg(WRITE_REG_NRF+0x1d,0x06);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	NRF24L01_Write_Reg(FLUSH_TX,0xff);
	NRF24L01_Write_Reg(FLUSH_RX,0xff);
	NRF24L01_Write_Reg(WRITE_REG_NRF + NRF24L01_CONFIG, 0x0f);   		 // IRQ�շ�����жϿ���,16λCRC,������

	SPI2_ReadWriteByte(0x50);
	SPI2_ReadWriteByte(0x73);
	NRF24L01_Write_Reg(WRITE_REG_NRF+0x1c,0x01);
	NRF24L01_Write_Reg(WRITE_REG_NRF+0x1d,0x06);

	NRF24L01_CE_H; 																							     //CEΪ��,�������ģʽ 	
	u8 sta= NRF24L01_Read_Reg(STATUS);
	NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta);
}


unsigned char Transparent_Data[128];
unsigned char Transparent_Update=0;
unsigned char Transparent_Cnt=0;


systime  nrf_rssi_delta;
float nrf_last_time=0;
float nrf_soft_rssi=0;
uint8_t nrf_soft_rssi_update=0;
uint32_t last_nrf_rx_ok_cnt=0;
uint32_t nrf_tx_max_cnt=0,nrf_tx_ok_cnt=0,nrf_rx_ok_cnt=0;
uint8_t nrf_rc_update=0,nrf_sbus_update=0;
uint8_t rx_fifo_len=0;
void NRF24L01_State_Check(unsigned char * Rx_Buf)
{
  u8 sta= NRF24L01_Read_Reg(STATUS);  											//��ȡ״̬�Ĵ�����ֵ
	if(sta & RX_OK)//���յ�����
	{
		nrf_rx_ok_cnt++;
		rx_fifo_len=NRF24L01_Read_Reg(R_RX_PL_WID);//��ȡ�������ݳ���
    if(rx_fifo_len<33)
		{
			NRF24L01_Read_Buf(RD_RX_PLOAD, Rx_Buf, rx_fifo_len);	//��ȡ����
			NRF24L01_Write_Reg(FLUSH_RX, 0xFF);											//���RX FIFO�Ĵ���
			nrf_rc_update=1;
			nrf_sbus_update=1;
			memcpy(Transparent_Data,Rx_Buf,rx_fifo_len*sizeof(unsigned char));
			Transparent_Cnt=rx_fifo_len;
			Transparent_Update=1;
		}
		else
		{
		  NRF24L01_Write_Reg(FLUSH_RX, 0xFF);											//���RX FIFO�Ĵ���
		}
		NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta); 					//���TX_DS��MAX_RT�жϱ�־
	}
	
  if (sta & MAX_TX)																					//�ﵽ����ط�����
	{
		NRF24L01_Write_Reg(FLUSH_TX, 0xFF);											//���TX FIFO�Ĵ���
    nrf_tx_max_cnt++;	
    NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta); 				//���TX_DS��MAX_RT�жϱ�־		
	}
	
	if (sta & TX_OK)																					
	{
		nrf_tx_ok_cnt++;
		NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta); 					//���TX_DS��MAX_RT�жϱ�־
	}
}



void nrf_soft_rssi_get(void)
{
	Get_Systime(&nrf_rssi_delta);
	if(nrf_rssi_delta.current_time-nrf_last_time>=1000)
	{
		nrf_soft_rssi=100.0f*(nrf_rx_ok_cnt-last_nrf_rx_ok_cnt)/200;
		nrf_last_time=nrf_rssi_delta.current_time;
		last_nrf_rx_ok_cnt=nrf_rx_ok_cnt;
		nrf_soft_rssi_update=1;
	}
}

void NRF_TxPacket_AP(uint8_t * tx_buf,uint8_t len)
{	
	NRF24L01_CE_L;		 //StandBy Iģʽ	
	NRF24L01_Write_Buf(0xa8, tx_buf, len); 			 // װ������ WR_TX_PLOAD
	NRF24L01_CE_H;		 //�ø�CE
}



pair_data rc_pair;
uint32_t cpu_id[3];
void rc_pair_run(void)
{
	rc_pair.tx_addr[0]=TX_ADDRESS[0];
  rc_pair.tx_addr[1]=TX_ADDRESS[1];
  rc_pair.tx_addr[2]=TX_ADDRESS[2];
	rc_pair.tx_addr[3]=TX_ADDRESS[3];
	rc_pair.tx_addr[4]=TX_ADDRESS[4];
	
	rc_pair.rx_addr[0]=RX_ADDRESS[0];
	rc_pair.rx_addr[1]=RX_ADDRESS[1];
	rc_pair.rx_addr[2]=RX_ADDRESS[2];
	rc_pair.rx_addr[3]=RX_ADDRESS[3];
	rc_pair.rx_addr[4]=RX_ADDRESS[4];
	if(GPIO_ReadInputDataBit(_button.state[UP].port,_button.state[UP].pin)==0)
	{	
		while(1)
		{
			u8 sta= NRF24L01_Read_Reg(STATUS);  											//��ȡ״̬�Ĵ�����ֵ
			if(sta & RX_OK)//���յ�����
			{
				nrf_rx_ok_cnt++;
				rx_fifo_len=NRF24L01_Read_Reg(R_RX_PL_WID);   //��ȡ�������ݳ���
				NRF24L01_Read_Buf(RD_RX_PLOAD, g_NRFRevData, rx_fifo_len);	//��ȡ����
				NRF24L01_Write_Reg(FLUSH_RX, 0xFF);										//���RX FIFO�Ĵ��� 
			}

			if(sta & MAX_TX)																					//�ﵽ����ط�����
			{
				NRF24L01_Write_Reg(FLUSH_TX, 0xFF);											//���TX FIFO�Ĵ���
				nrf_tx_max_cnt++;
			}

			if(sta & TX_OK)																					//�ﵽ����ط�����
			{
				nrf_tx_ok_cnt++;
			}
			NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta);			
			delay_ms(50);
			GPIO_SetBits(GPIOA , GPIO_Pin_4);   
			delay_ms(50);
			GPIO_ResetBits(GPIOA , GPIO_Pin_4);
			
			
			if(nrf_rx_ok_cnt>=10)
			{
				WriteFlashParameter_Three(NRF24L01_TX_ADDR0,
																	g_NRFRevData[0],
																	g_NRFRevData[1],
																	g_NRFRevData[2],
																	&Table_Parameter);
				WriteFlashParameter_Two(NRF24L01_TX_ADDR3,
																g_NRFRevData[3],
																g_NRFRevData[4],
																&Table_Parameter);
				
				WriteFlashParameter(NRF24L01_RF_CHL,
													  g_NRFRevData[10],
													  &Table_Parameter);
				break;
				
			}
		}
	}
	nrf_tx_max_cnt=0;
	nrf_tx_ok_cnt=0;
	nrf_rx_ok_cnt=0;	
	ReadFlashParameterThree(NRF24L01_TX_ADDR0,
											 &Table_Parameter_Read[NRF24L01_TX_ADDR0],
											 &Table_Parameter_Read[NRF24L01_TX_ADDR1],
											 &Table_Parameter_Read[NRF24L01_TX_ADDR2]);
	
	ReadFlashParameterTwo(NRF24L01_TX_ADDR3,
											 &Table_Parameter_Read[NRF24L01_TX_ADDR3],
											 &Table_Parameter_Read[NRF24L01_TX_ADDR4]);


	ReadFlashParameterOne(NRF24L01_RF_CHL,
											 &Table_Parameter_Read[NRF24L01_RF_CHL]);

	
	if(isnan(Table_Parameter_Read[NRF24L01_TX_ADDR0])==0
	 &&isnan(Table_Parameter_Read[NRF24L01_TX_ADDR1])==0
	 &&isnan(Table_Parameter_Read[NRF24L01_TX_ADDR2])==0
	 &&isnan(Table_Parameter_Read[NRF24L01_TX_ADDR3])==0
	 &&isnan(Table_Parameter_Read[NRF24L01_TX_ADDR4])==0
	 &&isnan(Table_Parameter_Read[NRF24L01_RF_CHL])==0)
	{
		rc_pair.tx_addr[0]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR0]);
		rc_pair.tx_addr[1]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR1]);
		rc_pair.tx_addr[2]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR2]);
		rc_pair.tx_addr[3]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR3]);
		rc_pair.tx_addr[4]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR4]);

		rc_pair.rx_addr[0]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR0]);
		rc_pair.rx_addr[1]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR1]);
		rc_pair.rx_addr[2]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR2]);
		rc_pair.rx_addr[3]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR3]);
		rc_pair.rx_addr[4]=(uint8_t)(Table_Parameter_Read[NRF24L01_TX_ADDR4]);
		
		rc_pair.chl[3]=(uint8_t)(Table_Parameter_Read[NRF24L01_RF_CHL]);
		
	}
	NRF24L01_CE_L;
	NRF24L01_Write_Reg(WRITE_REG_NRF+RF_CH,rc_pair.chl[3]);//����RFͨ��
	NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)rc_pair.tx_addr,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
	NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)rc_pair.rx_addr,RX_ADR_WIDTH);//дRX�ڵ��ַ
//NRF24L01_Write_Buf(WRITE_REG_NRF+TX_ADDR,(u8*)TX_ADDRESS,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
//NRF24L01_Write_Buf(WRITE_REG_NRF+RX_ADDR_P0,(u8*)RX_ADDRESS,RX_ADR_WIDTH);//дRX�ڵ��ַ	
	

	NRF24L01_Write_Reg(FLUSH_TX,0xff);
	NRF24L01_Write_Reg(FLUSH_RX,0xff);
	u8 sta= NRF24L01_Read_Reg(STATUS);
	NRF24L01_Write_Reg(WRITE_REG_NRF + STATUS, sta);
	NRF24L01_CE_H;
	
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 	
}

typedef enum
{
  TX_MODE=0,
  RX_MODE
}NRF_MODE;

uint16_t tx_cnt=0;      //���ʹ�������
uint16_t rx_cnt=0;      //���մ�������
#define nrf_err_max 2
NRF_MODE _nrf_mode=RX_MODE;
void nrf_tx_rx_exchange(void)
{
  if(_nrf_mode==TX_MODE)//����ģʽ��
	{
	  if(NRF24L01_TxPacket(g_NRFSendData,32)==TX_OK)
		{
			_nrf_mode=RX_MODE;
			NRF24L01_RX_Mode();//һ�����ͳɹ����ɽ���ģʽ
		}
	}
  else//����ģʽ��
	{
		if(NRF24L01_RxPacket(g_NRFRevData)==0)//һ�����ճɹ����ɷ���ģʽ��
		{
			_nrf_mode=TX_MODE;
			NRF24L01_TX_Mode();
		}
	}
}



systime  nrf_isr_dealt;
extern uint32_t lose_ctrl_cnt;
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line12)!=RESET)//�ж�ĳ�����ϵ��ж��Ƿ��� 
	{
			Get_Systime(&nrf_isr_dealt);
			NRF24L01_State_Check(g_NRFRevData);
			if(nrf_rc_update==1)
			{
				Remote_Ctrl_Prase();
				nrf_rc_update=0;
				lose_ctrl_cnt/=5;
			}
			EXTI_ClearITPendingBit(EXTI_Line12);   //��� LINE �ϵ��жϱ�־λ
	}     
}

