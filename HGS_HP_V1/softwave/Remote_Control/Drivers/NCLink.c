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
#include "main.h"//�û��Լ��⺯��ͷ�ļ�
#include "NCLink.h"


uint8_t NCLink_Head[2]={0xFF,0xFC};//����֡ͷ
uint8_t NCLink_End[2] ={0xA1,0xA2};//����֡β
uint8_t NCLink_Send_Ask_Flag[10]={0};//�ɿؽ��ջ�ȡ�����������󣬸�����վ���ͱ�־λ
uint8_t NCLink_Send_Check_Flag[20]={0};//���ݽ����ɹ����ɿظ�����վ���ͱ�־λ
uint8_t nclink_databuf[100];//���������ݻ�����
uint8_t rc_update_flag=0;//ң�������ݸ��±�־λ
uint8_t unlock_flag=0x02,takeoff_flag=0;//��������ɱ�־λ
uint8_t move_flag=0,mode_order=0;//SDK�ƶ���־λ���ƶ�˳��
uint16_t move_distance=0;//SDK�ƶ�����
uint8_t cal_flag=0,cal_step=0,cal_cmd=0,shutdown_now_cal_flag=0;//������У׼��־λ
/***************************************************************************************
@��������Serial_Data_Send(uint8_t *buf, uint32_t cnt)
@��ڲ�����buf:����������
			     cnt:�������ֳ�
@���ڲ�������
�������������ڷ��ͺ���
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void Serial_Data_Send(uint8_t *buf, uint32_t cnt)  
{
	//USART1_Send(buf,cnt);//�û���ֲʱ����д�˴��ڷ��ͺ���
  USART1_Send_Dma(buf,cnt);
	USB_TxWrite(buf,cnt);
}

/***************************************************************************************
@��������Pilot_Status_Tick(void) 
@��ڲ�������
@���ڲ�������
�����������ɿؽ���״̬��ʾ
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void Pilot_Status_Tick(void)  
{
	Bling_Set(&Light_R,500,100,0.2,0,GPIOC,GPIO_Pin_12,0);//�û���ֲʱ����д�˺���
}


union
{
unsigned char floatByte[4];
float floatValue;
}FloatUnion;
/***************************************************************************************
@��������void Float2Byte(float *FloatValue, unsigned char *Byte, unsigned char Subscript)
@��ڲ�����FloatValue:floatֵ
			     Byte:����
		       Subscript:ָ��������ڼ���Ԫ�ؿ�ʼд��
@���ڲ�������
������������float����ת��4�ֽ����ݲ�����ָ����ַ
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void Float2Byte(float *FloatValue, unsigned char *Byte, unsigned char Subscript)
{
	FloatUnion.floatValue = (float)2;
	if(FloatUnion.floatByte[0] == 0)//С��ģʽ
	{
		FloatUnion.floatValue = *FloatValue;
		Byte[Subscript]     = FloatUnion.floatByte[0];
		Byte[Subscript + 1] = FloatUnion.floatByte[1];
		Byte[Subscript + 2] = FloatUnion.floatByte[2];
		Byte[Subscript + 3] = FloatUnion.floatByte[3];
	}
	else//���ģʽ
	{
		FloatUnion.floatValue = *FloatValue;
		Byte[Subscript]     = FloatUnion.floatByte[3];
		Byte[Subscript + 1] = FloatUnion.floatByte[2];
		Byte[Subscript + 2] = FloatUnion.floatByte[1];
		Byte[Subscript + 3] = FloatUnion.floatByte[0];
	}
}


/***************************************************************************************
@��������void Byte2Float(unsigned char *Byte, unsigned char Subscript, float *FloatValue)
@��ڲ�����Byte:����
			     Subscript:ָ��������ڼ���Ԫ�ؿ�ʼд��
		       FloatValue:floatֵ
@���ڲ�������
������������ָ����ַ��4�ֽ�����ת��float����
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void Byte2Float(unsigned char *Byte, unsigned char Subscript, float *FloatValue)
{
	FloatUnion.floatByte[0]=Byte[Subscript];
	FloatUnion.floatByte[1]=Byte[Subscript + 1];
	FloatUnion.floatByte[2]=Byte[Subscript + 2];
	FloatUnion.floatByte[3]=Byte[Subscript + 3];
	*FloatValue=FloatUnion.floatValue;
}


//��һ֡���ݣ�������0x01  ���ݳ���24
float pitch=0,roll=0,yaw=0;//��̬��
float pitch_gyro=0,roll_gyro=0,yaw_gyro=0;//��̬���ٶ�
float vbat=0;
float imu_temp=0;
uint8_t fly_mode=0;//����ģʽ
uint8_t armed_flag=0;//������־

//�ڶ�֡���ݣ�������0x02  ���ݳ���18
int16_t ax,ay,az;
int16_t gx,gy,gz;
int16_t mx,my,mz;


//����֡���ݣ�������0x03  ���ݳ���16
int16_t nrc[8];

//����֡���ݣ�������0x04  ���ݳ���14
double gps_lng=0,gps_lat=0,gps_alt=0;
int16_t gps_pdop=0;
uint8_t gps_state=0;
uint8_t gps_satellite_num=0;

//����֡���ݣ�������0x05  ���ݳ���8
float lat_pos_obs=0,lng_pos_obs=0;
float lat_vel_obs=0,lng_vel_obs=0;

//����֡���ݣ�������0x06  ���ݳ���16
float alt_obs_baro=0,alt_obs_ult=0;
float opt_vel_p=0,opt_vel_r=0;

//����֡���ݣ�������0x07  ���ݳ���8
float alt_pos_fus=0;//�ںϸ߶�
float alt_vel_fus=0;//�ںϸ߶�
float alt_accel_fus=0;//�ںϸ߶�

//�ڰ�֡���ݣ�������0x08  ���ݳ���24
float lat_pos_fusion=0,lng_pos_fusion=0;
float lat_vel_fusion=0,lng_vel_fusion=0;
float lat_accel_fusion=0,lng_accel_fusion=0;

//�ھ�֡���ݣ�������0x09  ���ݳ���36
float userdata[9]={0};

//��10��11��12��13��14��15֡���ݣ�������0x0A��0x0B��0x0C��0x0D��0x0E��0x0F  ���ݳ���18
uint16_t kp[18]={0};
uint16_t ki[18]={0};
uint16_t kd[18]={0};


//��16֡���ݣ�������11  ���ݳ���36
uint8_t gyro_auto_cal_flag=0;
float gyro_x_raw=0;
float gyro_y_raw=0;
float gyro_z_raw=0;
float acce_x_raw=0;
float acce_y_raw=0;
float acce_z_raw=0;
float mag_x_raw=0;
float mag_y_raw=0;
float mag_z_raw=0;


//��17֡���ݣ�������12  ���ݳ���56
float gyro_x_offset;
float gyro_y_offset;
float gyro_z_offset;
float acce_x_offset;
float acce_y_offset;
float acce_z_offset;
float acce_x_scale;
float acce_y_scale;
float acce_z_scale;
float mag_x_offset;
float mag_y_offset;
float mag_z_offset;
float pitch_offset;
float roll_offset;


//��16֡���ݣ�������0x10  ���ݳ���16
uint16_t targeheight,safeheight,safevbat,maxheight;
uint16_t maxradius,maxupvel,maxdownvel,maxhorvel;








/***************************************************************************************
@��������NCLink_Data_Prase_Prepare(uint8_t data)
@��ڲ�����data:����������
@���ڲ�������
�����������ɿؽ�������վ����׼�������������봮���жϺ�����
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void NCLink_Data_Prase_Prepare(uint8_t data)//����վ���ݽ���
{
  static uint8_t buf[100];
  static uint8_t data_len = 0,data_cnt = 0;
  static uint8_t state = 0;
  if(state==0&&data==NCLink_Head[0])//�ж�֡ͷ1
  {
    state=1;
    buf[0]=data;
  }
  else if(state==1&&data==NCLink_Head[1])//�ж�֡ͷ2
  {
    state=2;
    buf[1]=data;
  }
  else if(state==2&&data<0XF1)//�����ֽ�
  {
    state=3;
    buf[2]=data;
  }
  else if(state==3&&data<100)//��Ч���ݳ���
  {
    state = 4;
    buf[3]=data;
    data_len = data;
    data_cnt = 0;
  }
  else if(state==4&&data_len>0)//���ݽ���
  {
    data_len--;
    buf[4+data_cnt++]=data;
    if(data_len==0)  state = 5;
  }
  else if(state==5)//���У��
  {
    state = 6;
    buf[4+data_cnt++]=data;
  }
	else if(state==6&&data==NCLink_End[0])//֡β0
	{
			state = 7;
			buf[4+data_cnt++]=data;
	}
	else if(state==7&&data==NCLink_End[1])//֡β1
	{
			state = 0;
			buf[4+data_cnt]=data;
		  NCLink_Data_Prase_Process(buf,data_cnt+5);//���ݽ���
	}
  else state = 0;
}

/***************************************************************************************
@��������NCLink_Data_Prase_Process(uint8_t *data_buf,uint8_t num)
@��ڲ�����data_buf:����������֡
					 num:����֡��
@���ڲ�������
����������������ȡ��������֡������ÿһ֡��������
@���ߣ�����С��
@���ڣ�2020��01��17��
****************************************************************************************/
void NCLink_Data_Prase_Process(uint8_t *data_buf,uint8_t num)//�ɿ����ݽ�������
{
  uint8_t sum = 0;
  for(uint8_t i=0;i<(num-3);i++)  sum ^= *(data_buf+i);
  if(!(sum==*(data_buf+num-3)))    																					return;//�ж�sum	
	if(!(*(data_buf)==NCLink_Head[0]&&*(data_buf+1)==NCLink_Head[1]))         return;//�ж�֡ͷ
	if(!(*(data_buf+num-2)==NCLink_End[0]&&*(data_buf+num-1)==NCLink_End[1])) return;//֡βУ��  
		if(*(data_buf+2)==0X01)//�ɿ���̬������Ϣ
		{
			 roll =0.01f*((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
			 pitch=0.01f*((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
			 yaw  =0.01f*((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));

			 roll_gyro =0.01f*((int32_t)(*(data_buf+10)<<24)|(*(data_buf+11)<<16)|(*(data_buf+12)<<8)|*(data_buf+13));
			 pitch_gyro =0.01f*((int32_t)(*(data_buf+14)<<24)|(*(data_buf+15)<<16)|(*(data_buf+16)<<8)|*(data_buf+17));
			 yaw_gyro =0.01f*((int32_t)(*(data_buf+18)<<24)|(*(data_buf+19)<<16)|(*(data_buf+20)<<8)|*(data_buf+21));

			 imu_temp =0.01f*((int16_t)(*(data_buf+22)<<8)|*(data_buf+23));
			 vbat=0.01f*((int16_t)(*(data_buf+24)<<8)|*(data_buf+25));

			 fly_mode=*(data_buf+26);
			 armed_flag=*(data_buf+27);
			 Pilot_Status_Tick();
		}
		else if(*(data_buf+2)==0X02)//IMUԭʼ����
		{
			ax=(int16_t)(*(data_buf+4)<<8)|*(data_buf+5);
			ay=(int16_t)(*(data_buf+6)<<8)|*(data_buf+7);
			az=(int16_t)(*(data_buf+8)<<8)|*(data_buf+9);
			gx=(int16_t)(*(data_buf+10)<<8)|*(data_buf+11);
			gy=(int16_t)(*(data_buf+12)<<8)|*(data_buf+13);
			gz=(int16_t)(*(data_buf+14)<<8)|*(data_buf+15);
			mx=(int16_t)(*(data_buf+16)<<8)|*(data_buf+17);
			my=(int16_t)(*(data_buf+18)<<8)|*(data_buf+19);
			mz=(int16_t)(*(data_buf+20)<<8)|*(data_buf+21);
		}
	    else if(*(data_buf+2)==0X03)//ң��������ͨ������
    {
        nrc[0]=(int16_t)(*(data_buf+4)<<8)|*(data_buf+5);
        nrc[1]=(int16_t)(*(data_buf+6)<<8)|*(data_buf+7);
        nrc[2]=(int16_t)(*(data_buf+8)<<8)|*(data_buf+9);
        nrc[3]=(int16_t)(*(data_buf+10)<<8)|*(data_buf+11);
        nrc[4]=(int16_t)(*(data_buf+12)<<8)|*(data_buf+13);
        nrc[5]=(int16_t)(*(data_buf+14)<<8)|*(data_buf+15);
        nrc[6]=(int16_t)(*(data_buf+16)<<8)|*(data_buf+17);
        nrc[7]=(int16_t)(*(data_buf+18)<<8)|*(data_buf+19);
    }
    else if(*(data_buf+2)==0X04)//GPS��λ����
    {
        gps_lng=0.0000001f*((int32_t)(*(data_buf+4)<<24)|(*(data_buf+5)<<16)|(*(data_buf+6)<<8)|*(data_buf+7));
        gps_lat=0.0000001f*((int32_t)(*(data_buf+8)<<24)|(*(data_buf+9)<<16)|(*(data_buf+10)<<8)|*(data_buf+11));
        gps_alt=0.001f*((int32_t)(*(data_buf+12)<<24)|(*(data_buf+13)<<16)|(*(data_buf+14)<<8)|*(data_buf+15));
        gps_pdop=(int16_t)(*(data_buf+16)<<8)|*(data_buf+17);
        gps_state=*(data_buf+18);
        gps_satellite_num=*(data_buf+19);
    }
		else if(*(data_buf+2)==0X05)//GPS�ٶ�����
    {
        lat_pos_obs =0.01f*((int32_t)(*(data_buf+4)<<24)|(*(data_buf+5)<<16)|(*(data_buf+6)<<8)|*(data_buf+7));
        lng_pos_obs =0.01f*((int32_t)(*(data_buf+8)<<24)|(*(data_buf+9)<<16)|(*(data_buf+10)<<8)|*(data_buf+11));
        lat_vel_obs =0.01f*((int32_t)(*(data_buf+12)<<24)|(*(data_buf+13)<<16)|(*(data_buf+14)<<8)|*(data_buf+15));
        lng_vel_obs =0.01f*((int32_t)(*(data_buf+16)<<24)|(*(data_buf+17)<<16)|(*(data_buf+18)<<8)|*(data_buf+19));
		}
		else if(*(data_buf+2)==0X06)//GPS�ٶ�����
    {
        alt_obs_baro=0.01f*((int32_t)(*(data_buf+4)<<24)|(*(data_buf+5)<<16)|(*(data_buf+6)<<8)|*(data_buf+7));
        alt_obs_ult =0.01f*((int32_t)(*(data_buf+8)<<24)|(*(data_buf+9)<<16)|(*(data_buf+10)<<8)|*(data_buf+11));
        opt_vel_p   =0.01f*((int32_t)(*(data_buf+12)<<24)|(*(data_buf+13)<<16)|(*(data_buf+14)<<8)|*(data_buf+15));
        opt_vel_r   =0.01f*((int32_t)(*(data_buf+16)<<24)|(*(data_buf+17)<<16)|(*(data_buf+18)<<8)|*(data_buf+19));
		}
		else if(*(data_buf+2)==0X07)
    {
        alt_pos_fus=0.01f*((int32_t)(*(data_buf+4)<<24)|(*(data_buf+5)<<16)|(*(data_buf+6)<<8)|*(data_buf+7));
        alt_vel_fus=0.01f*((int32_t)(*(data_buf+8)<<24)|(*(data_buf+9)<<16)|(*(data_buf+10)<<8)|*(data_buf+11));
        alt_accel_fus=0.01f*((int32_t)(*(data_buf+12)<<24)|(*(data_buf+13)<<16)|(*(data_buf+14)<<8)|*(data_buf+15));
		}
		else if(*(data_buf+2)==0X08)
    {
        lat_pos_fusion   =0.01*((int32_t)(*(data_buf+4)<<24)|(*(data_buf+5)<<16)|(*(data_buf+6)<<8)|*(data_buf+7));
        lng_pos_fusion   =0.01*((int32_t)(*(data_buf+8)<<24)|(*(data_buf+9)<<16)|(*(data_buf+10)<<8)|*(data_buf+11));
        lat_vel_fusion   =0.01*((int32_t)(*(data_buf+12)<<24)|(*(data_buf+13)<<16)|(*(data_buf+14)<<8)|*(data_buf+15));
        lng_vel_fusion   =0.01*((int32_t)(*(data_buf+16)<<24)|(*(data_buf+17)<<16)|(*(data_buf+18)<<8)|*(data_buf+19));
        lat_accel_fusion =0.01*((int32_t)(*(data_buf+20)<<24)|(*(data_buf+21)<<16)|(*(data_buf+22)<<8)|*(data_buf+23));
        lng_accel_fusion =0.01*((int32_t)(*(data_buf+24)<<24)|(*(data_buf+25)<<16)|(*(data_buf+26)<<8)|*(data_buf+27));
		}
		else if(*(data_buf+2)==0X09)
    {
        Byte2Float(data_buf,4,&userdata[0]);
        Byte2Float(data_buf,8,&userdata[1]);
        Byte2Float(data_buf,12,&userdata[2]);
        Byte2Float(data_buf,16,&userdata[3]);
        Byte2Float(data_buf,20,&userdata[4]);
        Byte2Float(data_buf,24,&userdata[5]);
		}
		else if(*(data_buf+2)==0X0A)                             //PID1-3
    {
        kp[0]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[0]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[0]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[1]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[1]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[1]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[2]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[2]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[2]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
    }
    else if(*(data_buf+2)==0X0B)                             //PID4-6
    {
        kp[3]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[3]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[3]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[4]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[4]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[4]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[5]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[5]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[5]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
    }
    else if(*(data_buf+2)==0X0C)                             //PID7-9
    {
        kp[6]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[6]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[6]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[7]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[7]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[7]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[8]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[8]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[8]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
    }
    else if(*(data_buf+2)==0X0D)                             //PID7-9
    {
        kp[9]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[9]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[9]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[10]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[10]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[10]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[11]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[11]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[11]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
    }
    else if(*(data_buf+2)==0X0E)                             //PID7-9
    {
        kp[12]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[12]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[12]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[13]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[13]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[13]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[14]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[14]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[14]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
    }
    else if(*(data_buf+2)==0X0F)                             //PID7-9
    {
        kp[15]=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        ki[15]=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        kd[15]=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        kp[16]=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        ki[16]=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        kd[16]=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        kp[17]=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        ki[17]=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
        kd[17]=((int16_t)(*(data_buf+20)<<8)|*(data_buf+21));
       
    }
    else if(*(data_buf+2)==0X10)
    {
        targeheight=((int16_t)(*(data_buf+4)<<8)|*(data_buf+5));
        safeheight=((int16_t)(*(data_buf+6)<<8)|*(data_buf+7));
        safevbat=((int16_t)(*(data_buf+8)<<8)|*(data_buf+9));
        maxheight=((int16_t)(*(data_buf+10)<<8)|*(data_buf+11));
        maxradius=((int16_t)(*(data_buf+12)<<8)|*(data_buf+13));
        maxupvel=((int16_t)(*(data_buf+14)<<8)|*(data_buf+15));
        maxdownvel=((int16_t)(*(data_buf+16)<<8)|*(data_buf+17));
        maxhorvel=((int16_t)(*(data_buf+18)<<8)|*(data_buf+19));
    }
		else if(*(data_buf+2)==0X11)
    {
        gyro_auto_cal_flag=*(data_buf+4);
        Byte2Float(data_buf, 5,&gyro_x_raw);
        Byte2Float(data_buf, 9,&gyro_y_raw);
        Byte2Float(data_buf,13,&gyro_z_raw);
        Byte2Float(data_buf,17,&acce_x_raw);
        Byte2Float(data_buf,21,&acce_y_raw);
        Byte2Float(data_buf,25,&acce_z_raw);
    }
    else if(*(data_buf+2)==0X12)
    {
        Byte2Float(data_buf, 4,&mag_x_raw);
        Byte2Float(data_buf, 8,&mag_y_raw);
        Byte2Float(data_buf,12,&mag_z_raw);
    }
    else if(*(data_buf+2)==0X13)
    {
        Byte2Float(data_buf,4, &gyro_x_offset);
        Byte2Float(data_buf,8, &gyro_y_offset);
        Byte2Float(data_buf,12,&gyro_z_offset);
        Byte2Float(data_buf,16,&mag_x_offset);
        Byte2Float(data_buf,20,&mag_y_offset);
        Byte2Float(data_buf,24,&mag_z_offset);
    }
    else if(*(data_buf+2)==0X14)
    {
        Byte2Float(data_buf,4, &acce_x_offset);
        Byte2Float(data_buf,8, &acce_y_offset);
        Byte2Float(data_buf,12,&acce_z_offset);
        Byte2Float(data_buf,16,&acce_x_scale);
        Byte2Float(data_buf,20,&acce_y_scale);
        Byte2Float(data_buf,24,&acce_z_scale);

    }
    else if(*(data_buf+2)==0X15)
    {
        Byte2Float(data_buf,4, &pitch_offset);
        Byte2Float(data_buf,8, &roll_offset);
        //uint8_t ch=0x07;
        //emit redrawparameter(ch);
    }
}





void NCLink_GS_Send_RCData(uint16_t ch0,uint16_t ch1,uint16_t ch2,uint16_t ch3,
	                         uint16_t ch4,uint16_t ch5,uint16_t ch6,uint16_t ch7,
													 uint16_t ch8,uint16_t ch9,uint8_t unlock_flag,uint8_t takeoff_flag)//����վָ���RC����
{
  uint8_t data_to_send[50];
  uint8_t sum = 0,i=0,cnt=0;
  uint16_t _temp;
  data_to_send[cnt++]=NCLink_Head[1];
  data_to_send[cnt++]=NCLink_Head[0];
  data_to_send[cnt++]=0x09;
  data_to_send[cnt++]=0;

  _temp = ch0;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch1;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch2;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch3;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch4;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch5;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch6;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch7;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch8;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);
  _temp = ch9;
  data_to_send[cnt++]=BYTE1(_temp);
  data_to_send[cnt++]=BYTE0(_temp);


  data_to_send[cnt++]=BYTE0(unlock_flag);
  data_to_send[cnt++]=BYTE0(takeoff_flag);

  data_to_send[3] = cnt-4;
  for(i=0;i<cnt;i++) sum ^= data_to_send[i];
  data_to_send[cnt++]=sum;
  data_to_send[cnt++]=NCLink_End[0];
  data_to_send[cnt++]=NCLink_End[1];
//  
//	NRF24L01_CE_L;			//StandBy Iģʽ	
//	NRF24L01_Write_Buf(WRITE_REG_NRF + RX_ADDR_P0, (u8*)rc_pair.tx_addr,TX_ADR_WIDTH); // װ�ؽ��ն˵�ַ
//	NRF24L01_Write_Buf(WR_TX_PLOAD, data_to_send, cnt); 			 // װ������	
//	NRF24L01_CE_H;
	NRF24L01_TxPacket(data_to_send);
}
