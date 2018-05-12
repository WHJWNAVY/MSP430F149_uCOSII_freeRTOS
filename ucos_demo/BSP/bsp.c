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

//8个LED灯，连接在P6口，可通过断开电源停止使用，ADC使用时断开电源
#define LEDDIR                  P6DIR
#define LEDOUT                  P6OUT//P6口接LED灯，8个

#define UINT8_SETB(uv8,b)       ((uv8) |= (uint8_t)(  1 << (uint8_t)(b)))
#define UINT8_CLRB(uv8,b)       ((uv8) &= (uint8_t)(~(1 << (uint8_t)(b))))
#define UINT8_REVB(uv8,b)       ((uv8) ^= (uint8_t)( (1 << (uint8_t)(b))))

void Clock_Init()
{
    uint8_t i;
    BCSCTL1 &= ~XT2OFF;               //打开XT2振荡器
    BCSCTL2 |= SELM1 + SELS;          //MCLK为8MHZ，SMCLK为8MHZ
    do
    {
        IFG1 &= ~OFIFG;                 //清楚振荡器错误标志
        for(i = 0; i < 100; i++)
            _NOP();
    }
    while((IFG1 & OFIFG) != 0);       //如果标志位1，则继续循环等待
    IFG1 &= ~OFIFG;
}

void LED_Init()
{
    LEDDIR = 0xff;                      //设置IO口方向为输出
    LEDOUT = 0xFF;                      //初始设置为00
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
    WDTCTL = WDTPW + WDTHOLD;					/* 禁止看门狗 */
    Clock_Init();
    LED_Init();
    BSP_IntDisAll();
}

void SystemTick_Init (void)
{
    WDTCTL  = WDT_MDLY_32;                                      /* This configuration produces interrupts every 32  ... */
                                                                /* 设置时钟节拍间隔为32ms(1Mhz),但外部时钟频率是8Mhz,所 */
                                                                /* 实际的看门狗定时器时钟节拍为(32/8 = 4)ms             */

    IE1 |= BIT0;                                                /* Enable WDT interrupts.                               */
                                                                /* 开看门狗定时器中断                                   */
}
