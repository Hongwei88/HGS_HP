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
#include "softiic.h"
#include "delay.h"




//MPU IIC ��ʱ����
void SOFT_IIC_Delay(void)
{
	delay_us(2);
}

//��ʼ��IIC
void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//��ʹ������IO PORTBʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; // �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIO
	GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);			 //PB10,PB11 �����
}



//IO��������
void SOFT_SDA_IN(void)        
{                           
  GPIO_InitTypeDef  GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void SOFT_SDA_OUT(void)     
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1 ;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}


//����IIC��ʼ�ź�
void SOFT_IIC_Start(void)
{
	SOFT_SDA_OUT(); //sda�����
	SOFT_IIC_SDA = 1;
	SOFT_IIC_SCL = 1;
	SOFT_IIC_Delay();
	SOFT_IIC_SDA = 0; //START:when CLK is high,DATA change form high to low
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 0; //ǯסI2C���ߣ�׼�����ͻ��������
}
//����IICֹͣ�ź�
void SOFT_IIC_Stop(void)
{
	SOFT_SDA_OUT(); //sda�����
	SOFT_IIC_SCL = 0;
	SOFT_IIC_SDA = 0; //STOP:when CLK is high DATA change form low to high
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 1;
	SOFT_IIC_SDA = 1; //����I2C���߽����ź�
	SOFT_IIC_Delay();
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 SOFT_IIC_Wait_Ack(void)
{
	u8 ucErrTime = 0;
	SOFT_SDA_IN(); //SDA����Ϊ����
	SOFT_IIC_SDA = 1;
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 1;
	SOFT_IIC_Delay();
	while (SOFT_READ_SDA)
	{
		ucErrTime++;
		if (ucErrTime > 250)
		{
			SOFT_IIC_Stop();
			return 1;
		}
	}
	SOFT_IIC_SCL = 0; //ʱ�����0
	return 0;
}
//����ACKӦ��
void SOFT_IIC_Ack(void)
{
	SOFT_IIC_SCL = 0;
	SOFT_SDA_OUT();
	SOFT_IIC_SDA = 0;
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 1;
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 0;
}
//������ACKӦ��
void SOFT_IIC_NAck(void)
{
	SOFT_IIC_SCL = 0;
	SOFT_SDA_OUT();
	SOFT_IIC_SDA = 1;
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 1;
	SOFT_IIC_Delay();
	SOFT_IIC_SCL = 0;
}
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void SOFT_IIC_Send_Byte(u8 txd)
{
	u8 t;
	SOFT_SDA_OUT();
	SOFT_IIC_SCL = 0; //����ʱ�ӿ�ʼ���ݴ���
	for (t = 0; t < 8; t++)
	{
		SOFT_IIC_SDA = (txd & 0x80) >> 7;
		txd <<= 1;
		SOFT_IIC_SCL = 1;
		SOFT_IIC_Delay();
		SOFT_IIC_SCL = 0;
		SOFT_IIC_Delay();
	}
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
u8 SOFT_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i, receive = 0;
	SOFT_SDA_IN(); //SDA����Ϊ����
	for (i = 0; i < 8; i++)
	{
		SOFT_IIC_SCL = 0;
		SOFT_IIC_Delay();
		SOFT_IIC_SCL = 1;
		receive <<= 1;
		if (SOFT_READ_SDA)
			receive++;
		SOFT_IIC_Delay();
	}
	if (!ack)
		SOFT_IIC_NAck(); //����nACK
	else
		SOFT_IIC_Ack(); //����ACK
	return receive;
}
