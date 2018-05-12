/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/*-----------------------------------------------------------
 * Characters on the LCD are used to simulate LED's.  In this case the 'ParTest'
 * is really operating on the LCD display.
 *-----------------------------------------------------------*/

/*
 * This demo is configured to execute on the ES449 prototyping board from
 * SoftBaugh. The ES449 has a built in LCD display and a single built in user
 * LED.  Therefore, in place of flashing an LED, the 'flash' and 'check' tasks
 * toggle '*' characters on the LCD.  The left most '*' represents LED 0, the
 * next LED 1, etc.
 *
 * There is a single genuine on board LED referenced as LED 10.
 */


/* Scheduler includes. */
#include <msp430.h>
#include <msp430x14x.h>


/* Demo application includes. */
#include "bsp.h"

/* Constants required for hardware setup. */
#define mainALL_BITS_OUTPUT     ( ( unsigned char ) 0xff )
#define mainMAX_FREQUENCY       ( ( unsigned char ) 121 )

//8��LED�ƣ�������P6�ڣ���ͨ���Ͽ���Դֹͣʹ�ã�ADCʹ��ʱ�Ͽ���Դ
#define LEDDIR                  P6DIR
#define LEDOUT                  P6OUT//P6�ڽ�LED�ƣ�8��

#define UINT8_SETB(uv8,b)       ((uv8) |= (uint8_t)(  1 << (uint8_t)(b)))
#define UINT8_CLRB(uv8,b)       ((uv8) &= (uint8_t)(~(1 << (uint8_t)(b))))
#define UINT8_REVB(uv8,b)       ((uv8) ^= (uint8_t)( (1 << (uint8_t)(b))))

static void prvClockSetup()
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

static void prvOnBoardLEDSetup()
{
    LEDDIR = 0xff;                      //����IO�ڷ���Ϊ���
    LEDOUT = 0xFF;                      //��ʼ����Ϊ00
}

void prvOnBoardLEDToggle(uint8_t led)
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
/*-----------------------------------------------------------*/

void prvSetupHardware(void)
{
    /* Stop the watchdog. */
    WDTCTL = WDTPW + WDTHOLD;

    prvClockSetup();
#if 0
    /* Setup DCO+ for ( xtal * D * (N + 1) ) operation. */
    FLL_CTL0 |= DCOPLUS + XCAP18PF;

    /* X2 DCO frequency, 8MHz nominal DCO */
    SCFI0 |= FN_4;

    /* (121+1) x 32768 x 2 = 7.99 Mhz */
    SCFQCTL = mainMAX_FREQUENCY;
#endif
    prvOnBoardLEDSetup();
}
/*-----------------------------------------------------------*/


