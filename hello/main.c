#include <msp430x14x.h>
#include <stdint.h>

//8��LED�ƣ�������P6�ڣ���ͨ���Ͽ���Դֹͣʹ�ã�ADCʹ��ʱ�Ͽ���Դ
#define LEDDIR                  P6DIR
#define LEDOUT                  P6OUT//P6�ڽ�LED�ƣ�8��

#define UINT8_SETB(uv8,b)       ((uv8) |= (uint8_t)(  1 << (uint8_t)(b)))
#define UINT8_CLRB(uv8,b)       ((uv8) &= (uint8_t)(~(1 << (uint8_t)(b))))

//��ʱ������IAR�Դ�������ʹ�õ�
#define CPU_F ((double)8000000)   //�ⲿ��Ƶ����8MHZ
//#define CPU_F ((double)32768)   //�ⲿ��Ƶ����32.768KHZ
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 

//***********************************************************************
//               MSP430�ڲ����Ź���ʼ��
//***********************************************************************
void WDT_Init()
{
    WDTCTL = WDTPW + WDTHOLD;       //�رտ��Ź�
}

//***********************************************************************
//                   ϵͳʱ�ӳ�ʼ�����ⲿ8M����
//***********************************************************************
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

//***********************************************************************
//               MSP430IO�ڳ�ʼ��
//***********************************************************************
void Led_Init()
{
    LEDDIR = 0xff;                      //����IO�ڷ���Ϊ���
    LEDOUT = 0xFF;                      //��ʼ����Ϊ00
}

//***********************************************************************
//      ������
//***********************************************************************
void main(void)
{
    uint8_t count;
    WDT_Init();
    Clock_Init();   //ʱ�ӳ�ʼ��
    Led_Init();    //�˿ڳ�ʼ�������ڿ���IO����������
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



