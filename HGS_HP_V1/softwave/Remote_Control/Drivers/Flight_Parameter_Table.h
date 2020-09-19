/*----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ��������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------/
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��540707961
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrun����С��
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               �޸�����:2018/8/30
*               �汾���۷��ߡ���V1.0.1
*               ��Ȩ���У�����ؾ���
*               Copyright(C) �人�Ƽ���ѧ�����ƴ��Ŷ� 2017-2025
*               All rights reserved
----------------------------------------------------------------------------------------------------------------------*/
#ifndef _FLIGHT_PARAMETER_TABLE_H_
#define _FLIGHT_PARAMETER_TABLE_H_


#define FLASH_EEPROM_ENABLE 1
#define PARAMETER_TABLE_STARTADDR 0x0801F000//0x0803C000 //0x08060000 
#define PARAMETER_TABLE_STARTADDR_EEPROM 100


#define FLIGHT_PARAMETER_TABLE_NUM  100
typedef struct
{
   float Parameter_Table[FLIGHT_PARAMETER_TABLE_NUM];
}FLIGHT_PARAMETER;


typedef enum
{
  RC_CAL_ROLL_MIN=0,
	RC_CAL_ROLL_MAX,
	RC_CAL_ROLL_OFFSET,
	RC_CAL_PITCH_MIN,
	RC_CAL_PITCH_MAX,
	RC_CAL_PITCH_OFFSET,
	RC_CAL_THR_MIN,
	RC_CAL_THR_MAX,
	RC_CAL_THR_OFFSET,
 	RC_CAL_YAW_MIN,
	RC_CAL_YAW_MAX,
	RC_CAL_YAW_OFFSET,
	RC_CAL_CH5_MIN,
	RC_CAL_CH5_MAX,
	RC_CAL_CH5_OFFSET,
	RC_CAL_CH6_MIN,
	RC_CAL_CH6_MAX,
	RC_CAL_CH6_OFFSET,	
	RC_CAL_CH7_MIN,
	RC_CAL_CH7_MAX,
	RC_CAL_CH7_OFFSET,	
	RC_CAL_CH8_MIN,
	RC_CAL_CH8_MAX,
	RC_CAL_CH8_OFFSET,
	RC_CAL_CH9_MIN,
	RC_CAL_CH9_MAX,
	RC_CAL_CH9_OFFSET,
	RC_CAL_CH10_MIN,
	RC_CAL_CH10_MAX,
	RC_CAL_CH10_OFFSET,
	RC_MAP_CH1,
	RC_MAP_CH2,
	RC_MAP_CH3,
	RC_MAP_CH4,
	RC_MAP_CH5,
  RC_MAP_CH6,
	RC_MAP_CH7,
	RC_MAP_CH8,
	RC_MAP_CH9,
	RC_MAP_CH10,
	LOSE_CTRL_PROTECT_ENABLE,
	LOSE_CTRL_PROTECT_CHL,
	LOSE_CTRL_PROTECT_VALUE,
	RC_SAFE_VOLTAGE,
	FLIGHT_SAFE_VOLTAGE,
	FLIGHT_SAFE_VOLTAGE_ENABLE,
	RC_PAIR_CHL,
	RC_TX_ADDR0,
	RC_TX_ADDR1,
	RC_TX_ADDR2,
	RC_TX_ADDR3,
	RC_TX_ADDR4,
	FLIGHT_PARAMETER_NUM,
}FLIGHT_PARAMETER_TABLE;




void ReadFlashParameterALL(volatile FLIGHT_PARAMETER *WriteData);
uint8_t ReadFlashParameterOne(uint16_t Label,float *ReadData);
uint8_t ReadFlashParameterTwo(uint16_t Label,float *ReadData1,float *ReadData2);
uint8_t ReadFlashParameterThree(uint16_t Label,float *ReadData1,float *ReadData2,float *ReadData3);
   
   
void WriteFlashParameter(uint16_t Label,float WriteData,volatile FLIGHT_PARAMETER *Table);
void WriteFlashParameter_Two(uint16_t Label,
                         float WriteData1,
                         float WriteData2,
                         volatile FLIGHT_PARAMETER *Table);
void WriteFlashParameter_Three(uint16_t Label,
                         float WriteData1,
                         float WriteData2,
                         float WriteData3,
                         volatile FLIGHT_PARAMETER *Table);
uint8_t ReadFlashParameterTwo(uint16_t Label,float *ReadData1,float *ReadData2);
extern volatile FLIGHT_PARAMETER Table_Parameter;
extern float Table_Parameter_Read[FLIGHT_PARAMETER_TABLE_NUM];
#endif

