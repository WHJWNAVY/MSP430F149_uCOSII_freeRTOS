#include <msp430x14x.h>
#include <stdint.h>

//8个LED灯，连接在P6口，可通过断开电源停止使用，ADC使用时断开电源
#define LEDDIR                  P6DIR
#define LEDOUT                  P6OUT//P6口接LED灯，8个

#define UINT8_SETB(uv8,b)       ((uv8) |= (uint8_t)(  1 << (uint8_t)(b)))
#define UINT8_CLRB(uv8,b)       ((uv8) &= (uint8_t)(~(1 << (uint8_t)(b))))

//延时函数，IAR自带，经常使用到
#define CPU_F ((double)8000000)   //外部高频晶振8MHZ
//#define CPU_F ((double)32768)   //外部低频晶振32.768KHZ
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 

//***********************************************************************
//               MSP430内部看门狗初始化
//***********************************************************************
void WDT_Init()
{
    WDTCTL = WDTPW + WDTHOLD;       //关闭看门狗
}

//***********************************************************************
//                   系统时钟初始化，外部8M晶振
//***********************************************************************
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

//***********************************************************************
//               MSP430IO口初始化
//***********************************************************************
void Led_Init()
{
    LEDDIR = 0xff;                      //设置IO口方向为输出
    LEDOUT = 0xFF;                      //初始设置为00
}

//***********************************************************************
//      主程序
//***********************************************************************
void main(void)
{
    uint8_t count;
    WDT_Init();
    Clock_Init();   //时钟初始化
    Led_Init();    //端口初始化，用于控制IO口输入或输出
    while(1)
    {
        delay_ms(200);
        
        for(count=0; count<8; count++)
        {
            UINT8_CLRB(LEDOUT, count);
            delay_ms(200);
        }
        for(count=8; count>0; count--)
        {
            UINT8_SETB(LEDOUT, count-1);
            delay_ms(200);
        }
    }
}



