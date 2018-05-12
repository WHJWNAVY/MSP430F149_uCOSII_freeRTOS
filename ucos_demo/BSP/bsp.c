/*
*********************************************************************************************************
*                                         BOARD SUPPORT PACKAGE
*
*                            (c) Copyright 2014; Micrium, Inc.; Weston, FL
*
*               All rights reserved. Protected by international copyright laws.
*
*               BSP is provided in source form to registered licensees ONLY.  It is
*               illegal to distribute this source code to any third party unless you receive
*               written permission by an authorized Micrium representative.  Knowledge of
*               the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                  Texas Instruments MSP-EXP430F5438
*                                         Experimenter Board
*
* Filename      : bsp.c
* Version       : V1.00
* Programmer(s) : HS
*********************************************************************************************************
*/

#include  <includes.h>

//8��LED�ƣ�������P6�ڣ���ͨ���Ͽ���Դֹͣʹ�ã�ADCʹ��ʱ�Ͽ���Դ
#define LEDDIR                  P6DIR
#define LEDOUT                  P6OUT//P6�ڽ�LED�ƣ�8��

#define UINT8_SETB(uv8,b)       ((uv8) |= (uint8_t)(  1 << (uint8_t)(b)))
#define UINT8_CLRB(uv8,b)       ((uv8) &= (uint8_t)(~(1 << (uint8_t)(b))))
#define UINT8_REVB(uv8,b)       ((uv8) ^= (uint8_t)( (1 << (uint8_t)(b))))

void Clock_Init()
{
    uint8_t i;
    BCSCTL1 &= ~XT2OFF;               //��XT2����
    BCSCTL2 |= SELM1 + SELS;          //MCLKΪ8MHZ��SMCLKΪ8MHZ
    do
    {
        IFG1 &= ~OFIFG;                 //������������־
        for(i = 0; i < 100; i++)
            _NOP();
    }
    while((IFG1 & OFIFG) != 0);       //�����־λ1�������ѭ���ȴ�
    IFG1 &= ~OFIFG;
}

void LED_Init()
{
    LEDDIR = 0xff;                      //����IO�ڷ���Ϊ���
    LEDOUT = 0xFF;                      //��ʼ����Ϊ00
}

void LED_Blink(uint8_t led)
{
#if 0
    static uint8_t flag = 0;
    led = ((led > 7) ? 7 : led);
    if(flag == 0)
    {
        UINT8_CLRB(LEDOUT, led);
        flag = 1;
    }
    else
    {
        UINT8_SETB(LEDOUT, led);
        flag = 1;
    }
#else
    led = ((led > 7) ? 7 : led);
    UINT8_REVB(LEDOUT, led);
#endif
}

void  BSP_IntDisAll (void)
{
    _DINT();                                                    /* Disable all interrupts                               */
}

void  BSP_IntEnAll (void)
{
    _EINT();                                                    /* Enable all interrupts                                */
}

void  BSP_Init (void)
{
    WDTCTL = WDTPW + WDTHOLD;					/* ��ֹ���Ź� */
    Clock_Init();
    LED_Init();
    BSP_IntDisAll();
}

void SystemTick_Init (void)
{
    WDTCTL  = WDT_MDLY_32;                                      /* This configuration produces interrupts every 32  ... */
                                                                /* ����ʱ�ӽ��ļ��Ϊ32ms(1Mhz),���ⲿʱ��Ƶ����8Mhz,�� */
                                                                /* ʵ�ʵĿ��Ź���ʱ��ʱ�ӽ���Ϊ(32/8 = 4)ms             */

    IE1 |= BIT0;                                                /* Enable WDT interrupts.                               */
                                                                /* �����Ź���ʱ���ж�                                   */
}
