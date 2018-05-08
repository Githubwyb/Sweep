#include "timer.h"
#include "altera_avalon_timer_regs.h"
#include "sys/alt_irq.h"
#include "led.h"

static TIMER_STRUCT timer_handler[TIMER_NUM];

int timer_init(void)
{
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);//清除标志位为0

	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0xA120);//预置数，设置周期为10ms
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, 0x7);

	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x7);//配置定时器，使能中断

	alt_ic_isr_register( TIMER_IRQ_INTERRUPT_CONTROLLER_ID,	TIMER_IRQ, TIMER_IRQ_HANDLE, NULL, 0x0 );//注册中断

    return F_SUCCESS;
}

void TIMER_IRQ_HANDLE(void *context)
{
	static int count = 0;
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x7);
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);//清除中断标志
	timer_update_IT();
}

int timer_update_IT(void)
{
    u8 i = 0;
    TIMER_CB pFun;

    //led_change();

    for(i = 0; i < TIMER_NUM; i++)
    {
        if(L_TRUE == timer_handler[i].isStart)
        {
            timer_handler[i].count++;

            if(timer_handler[i].count > timer_handler[i].period)
            {
                timer_handler[i].isStart = L_FALSE;
                if(timer_handler[i].pFun)
                {
                    pFun = timer_handler[i].pFun;
                    timer_handler[i].pFun = NULL;
                    pFun();
                }
            }
        }
    }

    key_detectProc();

    return F_SUCCESS;
}

int timer_start(TIMER_ENUM id, u32 period, TIMER_CB pFun)
{
    timer_handler[id].period = period / 10;
    timer_handler[id].count = 0;
    timer_handler[id].pFun = pFun;
    timer_handler[id].isStart = L_TRUE;
    return F_SUCCESS;
}

int timer_stop(TIMER_ENUM id)
{
    timer_handler[id].isStart = L_FALSE;
    return F_SUCCESS;
}

int timer_isTimerStart(TIMER_ENUM id)
{
    return timer_handler[id].isStart;
}
