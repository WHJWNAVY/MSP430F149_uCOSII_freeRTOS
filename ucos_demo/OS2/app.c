/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2014; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                      Texas Instruments MSP430X
*                                               on the
*                                           MSP-EXP430F5438
*                                          Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : HS
*********************************************************************************************************
*/
#include "includes.h"

OS_STK  TaskStartStk1[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk2[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk3[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk4[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk5[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk6[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk7[APP_TASK_STK_SIZE];
OS_STK  TaskStartStk8[APP_TASK_STK_SIZE];

void    TaskStart1  (void *data);
void    TaskStart2  (void *data);
void    TaskStart3  (void *data);
void    TaskStart4  (void *data);
void    TaskStart5  (void *data);
void    TaskStart6  (void *data);
void    TaskStart7  (void *data);
void    TaskStart8  (void *data);

void  main (void)
{
    BSP_Init();                                            /* Initialize BSP functions */

    OSInit();                                              /* ��ʼ��uCOS-II */
    OSTaskCreate(TaskStart1, (void *)0, &TaskStartStk1[APP_TASK_STK_SIZE - 1], APP_START_TASK1_PRIO);
    OSTaskCreate(TaskStart2, (void *)0, &TaskStartStk2[APP_TASK_STK_SIZE - 1], APP_START_TASK2_PRIO);
    OSTaskCreate(TaskStart3, (void *)0, &TaskStartStk3[APP_TASK_STK_SIZE - 1], APP_START_TASK3_PRIO);
    OSTaskCreate(TaskStart4, (void *)0, &TaskStartStk4[APP_TASK_STK_SIZE - 1], APP_START_TASK4_PRIO);
    OSTaskCreate(TaskStart5, (void *)0, &TaskStartStk5[APP_TASK_STK_SIZE - 1], APP_START_TASK5_PRIO);
    OSTaskCreate(TaskStart6, (void *)0, &TaskStartStk6[APP_TASK_STK_SIZE - 1], APP_START_TASK6_PRIO);
    OSTaskCreate(TaskStart7, (void *)0, &TaskStartStk7[APP_TASK_STK_SIZE - 1], APP_START_TASK7_PRIO);
    OSTaskCreate(TaskStart8, (void *)0, &TaskStartStk8[APP_TASK_STK_SIZE - 1], APP_START_TASK8_PRIO);

    SystemTick_Init();                                    /* �������Ź���ʱ���ж� */

    OSStart();                                             /* ��ʼ�������  */
}

void  TaskStart1 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(0);
        OSTimeDlyHMSM(0u, 0u, 0u, 500u);                    /* ��ʱ0.5�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart2 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(1);
        OSTimeDlyHMSM(0u, 0u, 1u, 0u);                    /* ��ʱ1�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart3 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(2);
        OSTimeDlyHMSM(0u, 0u, 1u, 500u);                    /* ��ʱ1.5�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart4 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(3);
        OSTimeDlyHMSM(0u, 0u, 2u, 0u);                    /* ��ʱ2�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart5 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(4);
        OSTimeDlyHMSM(0u, 0u, 2u, 500u);                    /* ��ʱ2.5�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart6 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(5);
        OSTimeDlyHMSM(0u, 0u, 3u, 0u);                    /* ��ʱ3�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart7 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(6);
        OSTimeDlyHMSM(0u, 0u, 3u, 500u);                    /* ��ʱ3.5�룬��������ȴ���ʱ���� */
    }
}

void  TaskStart8 (void *pdata)
{
    pdata  = pdata;                                        /* ���κ����壬��ֹ���������� */

    while (1) {
        LED_Blink(7);
        OSTimeDlyHMSM(0u, 0u, 4u, 0u);                    /* ��ʱ4�룬��������ȴ���ʱ���� */
    }
}