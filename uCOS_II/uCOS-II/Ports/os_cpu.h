/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                              (c) Copyright 2008, Micrium, Inc., Weston, FL
*                                           All Rights Reserved
*
*                                               TI MSP430X
*                                               MSP430x5xx
*
*
* File         : OS_CPU.H
* By           : Jian Chen (yenger@hotmail.com)
*                Jean J. Labrosse
*********************************************************************************************************
*/

#ifndef  OS_CPU_H
#define  OS_CPU_H

#ifdef  OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT  extern
#endif

/*
*********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
*********************************************************************************************************
*/

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char  INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned int   INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   int   INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long  INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long  INT32S;                   /* Signed   32 bit quantity                           */
typedef float          FP32;                     /* Single precision floating point                    */
typedef double         FP64;                     /* Double precision floating point                    */

typedef unsigned int   OS_STK;                   /* Each stack entry is 16-bit wide                    */
typedef unsigned int   OS_CPU_SR;                /* Define size of CPU status register (SR = 16 bits)  */

/* 
*********************************************************************************************************
*                                             TI MSP430
*
* Method #1:  Disable/Enable interrupts using simple instructions.  After critical section, interrupts
*             will be enabled even if they were disabled before entering the critical section.
*
* Method #2:  Disable/Enable interrupts by preserving the state of interrupts.  In other words, if 
*             interrupts were disabled before entering the critical section, they will be disabled when
*             leaving the critical section.
*             NOT IMPLEMENTED!
*
* Method #3:  Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking you
*             would store the state of the interrupt disable flag in the local variable 'cpu_sr' and then
*             disable interrupts.  'cpu_sr' is allocated in all of uC/OS-II's functions that need to 
*             disable interrupts.  You would restore the interrupt disable state by copying back 'cpu_sr'
*             into the CPU's status register.
*********************************************************************************************************
*/
#define  OS_CRITICAL_METHOD    3


#if      OS_CRITICAL_METHOD == 1
#define  OS_ENTER_CRITICAL()        _DINT()               /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()         _EINT()               /* Enable  interrupts                        */
#endif

#if      OS_CRITICAL_METHOD == 2
#define  OS_ENTER_CRITICAL()                              /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()                               /* Enable  interrupts                        */
#endif

#if      OS_CRITICAL_METHOD == 3
#define  OS_ENTER_CRITICAL()  (cpu_sr = OS_CPU_SR_Save())    /* Disable interrupts                        */
#define  OS_EXIT_CRITICAL()   (OS_CPU_SR_Restore(cpu_sr))    /* Enable  interrupts                        */
#endif

/*
*********************************************************************************************************
*                                             MSP430
*********************************************************************************************************
*/

#define  OS_STK_GROWTH        1                       /* Stack grows from HIGH to LOW memory on MSP430 */

#define  OS_TASK_SW()         OSCtxSw()               /* Task level context switch routine             */

/*
*********************************************************************************************************
*                                         GLOBAL VARIABLES
*********************************************************************************************************
*/

OS_CPU_EXT  OS_STK  *OSISRStkPtr;                    /* Pointer to top-of ISR stack                    */

/*
*********************************************************************************************************
*                                           PROTOTYPES
*********************************************************************************************************
*/

#if OS_CRITICAL_METHOD == 3u                               /* See OS_CPU_A.S85                                          */
OS_CPU_SR  OS_CPU_SR_Save        (void);
void       OS_CPU_SR_Restore     (OS_CPU_SR   cpu_sr);
#endif

void       OSCtxSw               (void);
void       OSIntCtxSw            (void);
void       OSStartHighRdy        (void);

#endif