#ifndef _TYPES_H_
#define _TYPES_H_

#define NULL 0

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum
{
    F_FAILED = -1,
    F_SUCCESS = 0,
} FUNCTION_RETURN;

typedef enum
{
    L_FALSE = 0,
    L_TRUE = 1,
} LOGICAL_ENUM;

typedef enum
{
    UART_RECV,
    KEY_0_PRESS,
    KEY_1_PRESS,
    TASK_NUM
} TASK_ENUM;

typedef enum
{
    TIMER_1,
    TIMER_2,
    TIMER_3,
    TIMER_NUM
} TIMER_ENUM;

typedef int (*TIMER_CB)(void);

typedef struct
{
    u8 isStart;
    u32 count;
    u32 period;
    TIMER_CB pFun;
} TIMER_STRUCT;

typedef int (*TASK_CB)(void);

typedef struct
{
    TASK_ENUM task_id;
    u8 state;
    TASK_CB pFun;
} TASK_MAP;

#endif //! _TYPES_H_
