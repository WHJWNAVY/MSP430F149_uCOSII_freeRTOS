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
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : HS
*********************************************************************************************************
*/

#ifndef  __BSP_H__
#define  __BSP_H__

#define CPU_F ((double)8000000u)   //Õ‚≤ø∏ﬂ∆µæß’Ò8MHZ
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 


void    BSP_Init            (void);
void    SystemTick_Init     (void);
void    BSP_IntEnAll        (void);
void    BSP_IntDisAll       (void);
void    LED_Blink           (uint8_t led);

#endif
