#include "key.h"
#include "task.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

int key_init(void)
{
    return F_SUCCESS;
}

int key_detectProc(void)
{
    static u8 key_p[2] = {0, 0};
    static u8 key_r[2] = {0, 0};

    if(IORD_ALTERA_AVALON_PIO_DATA(KEY_BASE) & 0x01)
    {
    	key_r[0]++;
		if(key_r[0] == 2)
		{
			key_p[0] = 0;
		}
    }
    else
    {
    	key_p[0]++;
		if(key_p[0] == 2)
		{
			key_r[0] = 0;
			task_setTask(KEY_0_PRESS);
		}
    }

    if(IORD_ALTERA_AVALON_PIO_DATA(KEY_BASE) & 0x02)
    {
        key_r[1]++;
		if(key_r[1] == 2)
		{
			key_p[1] = 0;
		}
    }
    else
    {
    	key_p[1]++;
		if(key_p[1] == 2)
		{
			key_r[1] = 0;
			task_setTask(KEY_1_PRESS);
		}
    }

    if(key_p[0] >= 250)
    {
        key_p[0] = 250;
    }
    if(key_r[0] >= 250)
    {
        key_r[0] = 250;
    }
    if(key_p[1] >= 250)
    {
        key_p[1] = 250;
    }
    if(key_r[1] >= 250)
    {
        key_r[1] = 250;
    }

    return F_SUCCESS;
}
