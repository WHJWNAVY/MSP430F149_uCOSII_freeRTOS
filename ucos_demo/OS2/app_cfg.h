/*
 *********************************************************************************************************
 *                                             APPLICATION
 *                                            EXAMPLE CODE
 *
 *                          (c) Copyright 2009-2014; Micrium, Inc.; Weston, FL
 *
 *               All rights reserved. Protected by international copyright laws.
 *
 *               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
 *               your application products. Example code may be used as is, in whole or in
 *               part, or may be used as a reference only.
 *
 *               Please help us continue to provide the Embedded community with the finest
 *               software available. Your honesty is greatly appreciated.
 *
 *               You can contact us at www.micrium.com.
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *
 *                                       APPLICATION CONFIGURATION
 *
 *                                       Texas Instruments MSP430
 *                                                on the
 *                                            MSP-EXP430F5438
 *                                           Evaluation Board
 *
 * File          : app_cfg.h
 * Version       : V1.00
 * Programmer(s) : HS
 *
 *********************************************************************************************************
 */

#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT
/*
*********************************************************************************************************
*                                       ADDITIONAL uC/MODULE ENABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/


#define  OS_TASK_TMR_PRIO            (OS_LOWEST_PRIO - 4)
#define  APP_START_TASK1_PRIO                  5u
#define  APP_START_TASK2_PRIO                  6u
#define  APP_START_TASK3_PRIO                  7u
#define  APP_START_TASK4_PRIO                  8u
#define  APP_START_TASK5_PRIO                  9u
#define  APP_START_TASK6_PRIO                  10u
#define  APP_START_TASK7_PRIO                  11u
#define  APP_START_TASK8_PRIO                  12u

/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_TASK_STK_SIZE                      48u

#endif
