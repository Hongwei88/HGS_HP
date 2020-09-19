#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef true
#define true  1
#endif

#ifndef false
#define false 0
#endif

#ifndef NULL
#define NULL 0
#endif
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;
typedef unsigned char  uint8;                   /* defined for unsigned 8-bits integer variable 	�޷���8λ���ͱ���  */
typedef signed   char  int8;                    /* defined for signed 8-bits integer variable		�з���8λ���ͱ���  */
typedef unsigned short uint16;                  /* defined for unsigned 16-bits integer variable 	�޷���16λ���ͱ��� */
typedef signed   short int16;                   /* defined for signed 16-bits integer variable 		�з���16λ���ͱ��� */
typedef unsigned int   uint32;                  /* defined for unsigned 32-bits integer variable 	�޷���32λ���ͱ��� */
typedef signed   int   int32;                   /* defined for signed 32-bits integer variable 		�з���32λ���ͱ��� */
typedef float          fp32;                    /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef double         fp64;                    /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */

#include		"LCMDRV.H"
#include		"FONT_MACRO.H"
#include    "GUI_CONFIG.H"
#include    "GUI_BASIC.H"
#include    "GUI_STOCKC.H"
#include    "FONT5_7.H"
#include    "FONT8_8.H"
#include    "FONT24_32.H"
#include    "LOADBIT.H"
#include    "WINDOWS.H"
#include    "MENU.H"
#include    "spline.H"
#include    "ConvertColor.H"



typedef enum
{
  FONT5x7=0,
  FONT8x8,
}FONT;

void GUI_PutNumber(unsigned char x,unsigned char y, float number,FONT type);


extern  uint8  GUI_PutChar24_32(uint32 x, uint32 y, uint8 ch);
extern void  GUI_PutString24_32(uint32 x, uint32 y, char *str);
extern void  GUI_PutNOString24_32(uint32 x, uint32 y, char *str, uint8 no);
#endif
