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

    OSInit();                                              /* 初始化uCOS-II */
    OSTaskCreate(TaskStart1, (void *)0, &TaskStartStk1[APP_TASK_STK_SIZE - 1], APP_START_TASK1_PRIO);
    OSTaskCreate(TaskStart2, (void *)0, &TaskStartStk2[APP_TASK_STK_SIZE - 1], APP_START_TASK2_PRIO);
    OSTaskCreate(TaskStart3, (void *)0, &TaskStartStk3[APP_TASK_STK_SIZE - 1], APP_START_TASK3_PRIO);
    OSTaskCreate(TaskStart4, (void *)0, &TaskStartStk4[APP_TASK_STK_SIZE - 1], APP_START_TASK4_PRIO);
    OSTaskCreate(TaskStart5, (void *)0, &TaskStartStk5[APP_TASK_STK_SIZE - 1], APP_START_TASK5_PRIO);
    OSTaskCreate(TaskStart6, (void *)0, &TaskStartStk6[APP_TASK_STK_SIZE - 1], APP_START_TASK6_PRIO);
    OSTaskCreate(TaskStart7, (void *)0, &TaskStartStk7[APP_TASK_STK_SIZE - 1], APP_START_TASK7_PRIO);
    OSTaskCreate(TaskStart8, (void *)0, &TaskStartStk8[APP_TASK_STK_SIZE - 1], APP_START_TASK8_PRIO);

    SystemTick_Init();                                    /* 开启看门狗定时器中断 */

    OSStart();                                             /* 开始任务调度  */
}

void  TaskStart1 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(0);
        OSTimeDlyHMSM(0u, 0u, 0u, 500u);                    /* 延时0.5秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart2 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(1);
        OSTimeDlyHMSM(0u, 0u, 1u, 0u);                    /* 延时1秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart3 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(2);
        OSTimeDlyHMSM(0u, 0u, 1u, 500u);                    /* 延时1.5秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart4 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(3);
        OSTimeDlyHMSM(0u, 0u, 2u, 0u);                    /* 延时2秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart5 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(4);
        OSTimeDlyHMSM(0u, 0u, 2u, 500u);                    /* 延时2.5秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart6 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(5);
        OSTimeDlyHMSM(0u, 0u, 3u, 0u);                    /* 延时3秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart7 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(6);
        OSTimeDlyHMSM(0u, 0u, 3u, 500u);                    /* 延时3.5秒，挂起本任务等待延时结束 */
    }
}

void  TaskStart8 (void *pdata)
{
    pdata  = pdata;                                        /* 无任何意义，防止编译器报警 */

    while (1) {
        LED_Blink(7);
        OSTimeDlyHMSM(0u, 0u, 4u, 0u);                    /* 延时4秒，挂起本任务等待延时结束 */
    }
}