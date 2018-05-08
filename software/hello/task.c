#include "task.h"
#include "uart.h"
#include "log.h"

extern FreInfo FInfo;
extern TestMessage ReceiveMessage;
extern u8 isStart;

static int task_msgProc(unsigned char *data, int length)
{
//    if(NULL != strstr(data, "S f"))
//    {
//        ReceiveMessage.getMessege = 1;
//        FInfo.CurFre = 15.625;
//        FInfo.divideFre = 100000;
//        FInfo.endTest = 0;
//        isStart = 1;
//
////      LOG_DEBUG("start");
//    }
//    else if(NULL != strstr(data, "stop"))
//    {
//        ReceiveMessage.getMessege = 0;
//        isStart = 0;
////      LOG_DEBUG("end");
//    }
    return F_SUCCESS;
}

int task_key0Press(void)
{
	if(isStart == 0)
	{
		isStart = 1;
		led_start();
		FInfo.CurFre = 15.625;
		FInfo.divideFre = 200000;
		FInfo.endTest = 0;
	}
	LOG_DEBUG("Key 0 press");
    return F_SUCCESS;
}

int task_key1Press(void)
{
	if(isStart)
	{
		isStart = 0;
		led_end();
	}
	LOG_DEBUG("Key 1 press");
    return F_SUCCESS;
}

static int task_uartRecvProc(void)
{
    LOG_DEBUG("wifi recieve %d data:", uart.receive_count);
    log_hex(uart.receive_buffer, uart.receive_count);
    task_msgProc(uart.receive_buffer, uart.receive_count);
    uart.receive_count = 0;
    return F_SUCCESS;
}

static TASK_MAP task_map[] =
{
    {UART_RECV,             L_FALSE,        task_uartRecvProc},
    {KEY_0_PRESS,           L_FALSE,        task_key0Press},
    {KEY_1_PRESS,           L_FALSE,        task_key1Press},
};

int task_proc(void)
{
    int i = 0;

    for (i = 0; i < sizeof(task_map) / sizeof(task_map[0]); ++i)
    {
        if (L_TRUE == task_map[i].state)
        {
            task_map[i].state = L_FALSE;

            if (task_map[i].pFun)
            {
                task_map[i].pFun();
            }
            else
            {
                LOG_DEBUG("task %d has no handler", task_map[i].task_id);
            }
        }
    }

    return F_SUCCESS;
}

int task_setTask(TASK_ENUM id)
{
    int i = 0;

    for (i = 0; i < sizeof(task_map) / sizeof(task_map[0]); ++i)
    {
        if (id == task_map[i].task_id)
        {
            task_map[i].state = L_TRUE;
            return F_SUCCESS;
        }
    }

    LOG_ERROR("no such task %d", id);
    return F_FAILED;
}
