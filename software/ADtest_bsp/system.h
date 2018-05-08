/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'CPU' in SOPC Builder design 'reader_qsys'
 * SOPC Builder design path: ../../reader_qsys.sopcinfo
 *
 * Generated: Sat May 05 10:47:24 CST 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * AOTR configuration
 *
 */

#define ALT_MODULE_CLASS_AOTR altera_avalon_pio
#define AOTR_BASE 0x22170
#define AOTR_BIT_CLEARING_EDGE_REGISTER 0
#define AOTR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define AOTR_CAPTURE 0
#define AOTR_DATA_WIDTH 1
#define AOTR_DO_TEST_BENCH_WIRING 0
#define AOTR_DRIVEN_SIM_VALUE 0
#define AOTR_EDGE_TYPE "NONE"
#define AOTR_FREQ 50000000
#define AOTR_HAS_IN 1
#define AOTR_HAS_OUT 0
#define AOTR_HAS_TRI 0
#define AOTR_IRQ -1
#define AOTR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AOTR_IRQ_TYPE "NONE"
#define AOTR_NAME "/dev/AOTR"
#define AOTR_RESET_VALUE 0
#define AOTR_SPAN 16
#define AOTR_TYPE "altera_avalon_pio"


/*
 * AREADY configuration
 *
 */

#define ALT_MODULE_CLASS_AREADY altera_avalon_pio
#define AREADY_BASE 0x22190
#define AREADY_BIT_CLEARING_EDGE_REGISTER 0
#define AREADY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define AREADY_CAPTURE 0
#define AREADY_DATA_WIDTH 1
#define AREADY_DO_TEST_BENCH_WIRING 0
#define AREADY_DRIVEN_SIM_VALUE 0
#define AREADY_EDGE_TYPE "NONE"
#define AREADY_FREQ 50000000
#define AREADY_HAS_IN 1
#define AREADY_HAS_OUT 0
#define AREADY_HAS_TRI 0
#define AREADY_IRQ -1
#define AREADY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AREADY_IRQ_TYPE "NONE"
#define AREADY_NAME "/dev/AREADY"
#define AREADY_RESET_VALUE 0
#define AREADY_SPAN 16
#define AREADY_TYPE "altera_avalon_pio"


/*
 * BOTR configuration
 *
 */

#define ALT_MODULE_CLASS_BOTR altera_avalon_pio
#define BOTR_BASE 0x22180
#define BOTR_BIT_CLEARING_EDGE_REGISTER 0
#define BOTR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BOTR_CAPTURE 0
#define BOTR_DATA_WIDTH 1
#define BOTR_DO_TEST_BENCH_WIRING 0
#define BOTR_DRIVEN_SIM_VALUE 0
#define BOTR_EDGE_TYPE "NONE"
#define BOTR_FREQ 50000000
#define BOTR_HAS_IN 1
#define BOTR_HAS_OUT 0
#define BOTR_HAS_TRI 0
#define BOTR_IRQ -1
#define BOTR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BOTR_IRQ_TYPE "NONE"
#define BOTR_NAME "/dev/BOTR"
#define BOTR_RESET_VALUE 0
#define BOTR_SPAN 16
#define BOTR_TYPE "altera_avalon_pio"


/*
 * BREADY configuration
 *
 */

#define ALT_MODULE_CLASS_BREADY altera_avalon_pio
#define BREADY_BASE 0x221a0
#define BREADY_BIT_CLEARING_EDGE_REGISTER 0
#define BREADY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BREADY_CAPTURE 0
#define BREADY_DATA_WIDTH 1
#define BREADY_DO_TEST_BENCH_WIRING 0
#define BREADY_DRIVEN_SIM_VALUE 0
#define BREADY_EDGE_TYPE "NONE"
#define BREADY_FREQ 50000000
#define BREADY_HAS_IN 1
#define BREADY_HAS_OUT 0
#define BREADY_HAS_TRI 0
#define BREADY_IRQ -1
#define BREADY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BREADY_IRQ_TYPE "NONE"
#define BREADY_NAME "/dev/BREADY"
#define BREADY_RESET_VALUE 0
#define BREADY_SPAN 16
#define BREADY_TYPE "altera_avalon_pio"


/*
 * Bluethooth configuration
 *
 */

#define ALT_MODULE_CLASS_Bluethooth altera_avalon_uart
#define BLUETHOOTH_BASE 0x22020
#define BLUETHOOTH_BAUD 115200
#define BLUETHOOTH_DATA_BITS 8
#define BLUETHOOTH_FIXED_BAUD 0
#define BLUETHOOTH_FREQ 50000000
#define BLUETHOOTH_IRQ 5
#define BLUETHOOTH_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BLUETHOOTH_NAME "/dev/Bluethooth"
#define BLUETHOOTH_PARITY 'N'
#define BLUETHOOTH_SIM_CHAR_STREAM ""
#define BLUETHOOTH_SIM_TRUE_BAUD 0
#define BLUETHOOTH_SPAN 32
#define BLUETHOOTH_STOP_BITS 1
#define BLUETHOOTH_SYNC_REG_DEPTH 2
#define BLUETHOOTH_TYPE "altera_avalon_uart"
#define BLUETHOOTH_USE_CTS_RTS 0
#define BLUETHOOTH_USE_EOP_REGISTER 0


/*
 * Buzzer configuration
 *
 */

#define ALT_MODULE_CLASS_Buzzer altera_avalon_pio
#define BUZZER_BASE 0x22110
#define BUZZER_BIT_CLEARING_EDGE_REGISTER 0
#define BUZZER_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUZZER_CAPTURE 0
#define BUZZER_DATA_WIDTH 1
#define BUZZER_DO_TEST_BENCH_WIRING 0
#define BUZZER_DRIVEN_SIM_VALUE 0
#define BUZZER_EDGE_TYPE "NONE"
#define BUZZER_FREQ 50000000
#define BUZZER_HAS_IN 0
#define BUZZER_HAS_OUT 1
#define BUZZER_HAS_TRI 0
#define BUZZER_IRQ -1
#define BUZZER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUZZER_IRQ_TYPE "NONE"
#define BUZZER_NAME "/dev/Buzzer"
#define BUZZER_RESET_VALUE 0
#define BUZZER_SPAN 16
#define BUZZER_TYPE "altera_avalon_pio"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00021020
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "CPU"
#define ALT_CPU_RESET_ADDR 0x00021800


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00021020
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_RESET_ADDR 0x00021800


/*
 * DDS configuration
 *
 */

#define ALT_MODULE_CLASS_DDS altera_avalon_pio
#define DDS_BASE 0x22120
#define DDS_BIT_CLEARING_EDGE_REGISTER 0
#define DDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DDS_CAPTURE 0
#define DDS_DATA_WIDTH 3
#define DDS_DO_TEST_BENCH_WIRING 0
#define DDS_DRIVEN_SIM_VALUE 0
#define DDS_EDGE_TYPE "NONE"
#define DDS_FREQ 50000000
#define DDS_HAS_IN 0
#define DDS_HAS_OUT 1
#define DDS_HAS_TRI 0
#define DDS_IRQ -1
#define DDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DDS_IRQ_TYPE "NONE"
#define DDS_NAME "/dev/DDS"
#define DDS_RESET_VALUE 0
#define DDS_SPAN 16
#define DDS_TYPE "altera_avalon_pio"


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS


/*
 * EPCS configuration
 *
 */

#define ALT_MODULE_CLASS_EPCS altera_avalon_epcs_flash_controller
#define EPCS_BASE 0x21800
#define EPCS_IRQ -1
#define EPCS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define EPCS_NAME "/dev/EPCS"
#define EPCS_REGISTER_OFFSET 1024
#define EPCS_SPAN 2048
#define EPCS_TYPE "altera_avalon_epcs_flash_controller"


/*
 * FALSH_OUT configuration
 *
 */

#define ALT_MODULE_CLASS_FALSH_OUT altera_avalon_pio
#define FALSH_OUT_BASE 0x220e0
#define FALSH_OUT_BIT_CLEARING_EDGE_REGISTER 0
#define FALSH_OUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FALSH_OUT_CAPTURE 0
#define FALSH_OUT_DATA_WIDTH 2
#define FALSH_OUT_DO_TEST_BENCH_WIRING 0
#define FALSH_OUT_DRIVEN_SIM_VALUE 0
#define FALSH_OUT_EDGE_TYPE "NONE"
#define FALSH_OUT_FREQ 50000000
#define FALSH_OUT_HAS_IN 0
#define FALSH_OUT_HAS_OUT 1
#define FALSH_OUT_HAS_TRI 0
#define FALSH_OUT_IRQ -1
#define FALSH_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FALSH_OUT_IRQ_TYPE "NONE"
#define FALSH_OUT_NAME "/dev/FALSH_OUT"
#define FALSH_OUT_RESET_VALUE 0
#define FALSH_OUT_SPAN 16
#define FALSH_OUT_TYPE "altera_avalon_pio"


/*
 * FLASH_IN configuration
 *
 */

#define ALT_MODULE_CLASS_FLASH_IN altera_avalon_pio
#define FLASH_IN_BASE 0x220c0
#define FLASH_IN_BIT_CLEARING_EDGE_REGISTER 0
#define FLASH_IN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FLASH_IN_CAPTURE 0
#define FLASH_IN_DATA_WIDTH 1
#define FLASH_IN_DO_TEST_BENCH_WIRING 0
#define FLASH_IN_DRIVEN_SIM_VALUE 0
#define FLASH_IN_EDGE_TYPE "NONE"
#define FLASH_IN_FREQ 50000000
#define FLASH_IN_HAS_IN 1
#define FLASH_IN_HAS_OUT 0
#define FLASH_IN_HAS_TRI 0
#define FLASH_IN_IRQ -1
#define FLASH_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FLASH_IN_IRQ_TYPE "NONE"
#define FLASH_IN_NAME "/dev/FLASH_IN"
#define FLASH_IN_RESET_VALUE 0
#define FLASH_IN_SPAN 16
#define FLASH_IN_TYPE "altera_avalon_pio"


/*
 * JTAG_UART configuration
 *
 */

#define ALT_MODULE_CLASS_JTAG_UART altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x221b8
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/JTAG_UART"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * KEY configuration
 *
 */

#define ALT_MODULE_CLASS_KEY altera_avalon_pio
#define KEY_BASE 0x22100
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 0
#define KEY_DATA_WIDTH 2
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "NONE"
#define KEY_FREQ 50000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 6
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "LEVEL"
#define KEY_NAME "/dev/KEY"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * LED configuration
 *
 */

#define ALT_MODULE_CLASS_LED altera_avalon_pio
#define LED_BASE 0x220f0
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 2
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/LED"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * MCPCS configuration
 *
 */

#define ALT_MODULE_CLASS_MCPCS altera_avalon_pio
#define MCPCS_BASE 0x220d0
#define MCPCS_BIT_CLEARING_EDGE_REGISTER 0
#define MCPCS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MCPCS_CAPTURE 0
#define MCPCS_DATA_WIDTH 1
#define MCPCS_DO_TEST_BENCH_WIRING 0
#define MCPCS_DRIVEN_SIM_VALUE 0
#define MCPCS_EDGE_TYPE "NONE"
#define MCPCS_FREQ 50000000
#define MCPCS_HAS_IN 0
#define MCPCS_HAS_OUT 1
#define MCPCS_HAS_TRI 0
#define MCPCS_IRQ -1
#define MCPCS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MCPCS_IRQ_TYPE "NONE"
#define MCPCS_NAME "/dev/MCPCS"
#define MCPCS_RESET_VALUE 0
#define MCPCS_SPAN 16
#define MCPCS_TYPE "altera_avalon_pio"


/*
 * RAM configuration
 *
 */

#define ALT_MODULE_CLASS_RAM altera_avalon_onchip_memory2
#define RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_BASE 0x10000
#define RAM_CONTENTS_INFO ""
#define RAM_DUAL_PORT 0
#define RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_INIT_CONTENTS_FILE "reader_qsys_RAM"
#define RAM_INIT_MEM_CONTENT 1
#define RAM_INSTANCE_ID "NONE"
#define RAM_IRQ -1
#define RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_NAME "/dev/RAM"
#define RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define RAM_RAM_BLOCK_TYPE "AUTO"
#define RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_SINGLE_CLOCK_OP 0
#define RAM_SIZE_MULTIPLE 1
#define RAM_SIZE_VALUE 53000
#define RAM_SPAN 53000
#define RAM_TYPE "altera_avalon_onchip_memory2"
#define RAM_WRITABLE 1


/*
 * RS232 configuration
 *
 */

#define ALT_MODULE_CLASS_RS232 altera_avalon_uart
#define RS232_BASE 0x22040
#define RS232_BAUD 115200
#define RS232_DATA_BITS 8
#define RS232_FIXED_BAUD 0
#define RS232_FREQ 50000000
#define RS232_IRQ 4
#define RS232_IRQ_INTERRUPT_CONTROLLER_ID 0
#define RS232_NAME "/dev/RS232"
#define RS232_PARITY 'N'
#define RS232_SIM_CHAR_STREAM ""
#define RS232_SIM_TRUE_BAUD 0
#define RS232_SPAN 32
#define RS232_STOP_BITS 1
#define RS232_SYNC_REG_DEPTH 2
#define RS232_TYPE "altera_avalon_uart"
#define RS232_USE_CTS_RTS 0
#define RS232_USE_EOP_REGISTER 0


/*
 * SYSID configuration
 *
 */

#define ALT_MODULE_CLASS_SYSID altera_avalon_sysid_qsys
#define SYSID_BASE 0x221b0
#define SYSID_ID 8
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/SYSID"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1525488233
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/JTAG_UART"
#define ALT_STDERR_BASE 0x221b8
#define ALT_STDERR_DEV JTAG_UART
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/JTAG_UART"
#define ALT_STDIN_BASE 0x221b8
#define ALT_STDIN_DEV JTAG_UART
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/JTAG_UART"
#define ALT_STDOUT_BASE 0x221b8
#define ALT_STDOUT_DEV JTAG_UART
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "reader_qsys"


/*
 * Timer configuration
 *
 */

#define ALT_MODULE_CLASS_Timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x22000
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 50000000
#define TIMER_IRQ 7
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 49999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/Timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * UART configuration
 *
 */

#define ALT_MODULE_CLASS_UART altera_avalon_uart
#define UART_BASE 0x22060
#define UART_BAUD 115200
#define UART_DATA_BITS 8
#define UART_FIXED_BAUD 0
#define UART_FREQ 50000000
#define UART_IRQ 1
#define UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_NAME "/dev/UART"
#define UART_PARITY 'N'
#define UART_SIM_CHAR_STREAM ""
#define UART_SIM_TRUE_BAUD 0
#define UART_SPAN 32
#define UART_STOP_BITS 1
#define UART_SYNC_REG_DEPTH 2
#define UART_TYPE "altera_avalon_uart"
#define UART_USE_CTS_RTS 0
#define UART_USE_EOP_REGISTER 0


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * pio_input configuration
 *
 */

#define ALT_MODULE_CLASS_pio_input altera_avalon_pio
#define PIO_INPUT_BASE 0x22130
#define PIO_INPUT_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_INPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_INPUT_CAPTURE 0
#define PIO_INPUT_DATA_WIDTH 20
#define PIO_INPUT_DO_TEST_BENCH_WIRING 0
#define PIO_INPUT_DRIVEN_SIM_VALUE 0
#define PIO_INPUT_EDGE_TYPE "NONE"
#define PIO_INPUT_FREQ 50000000
#define PIO_INPUT_HAS_IN 0
#define PIO_INPUT_HAS_OUT 1
#define PIO_INPUT_HAS_TRI 0
#define PIO_INPUT_IRQ -1
#define PIO_INPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_INPUT_IRQ_TYPE "NONE"
#define PIO_INPUT_NAME "/dev/pio_input"
#define PIO_INPUT_RESET_VALUE 0
#define PIO_INPUT_SPAN 16
#define PIO_INPUT_TYPE "altera_avalon_pio"


/*
 * pio_output configuration
 *
 */

#define ALT_MODULE_CLASS_pio_output altera_avalon_pio
#define PIO_OUTPUT_BASE 0x22140
#define PIO_OUTPUT_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_OUTPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_OUTPUT_CAPTURE 0
#define PIO_OUTPUT_DATA_WIDTH 20
#define PIO_OUTPUT_DO_TEST_BENCH_WIRING 0
#define PIO_OUTPUT_DRIVEN_SIM_VALUE 0
#define PIO_OUTPUT_EDGE_TYPE "NONE"
#define PIO_OUTPUT_FREQ 50000000
#define PIO_OUTPUT_HAS_IN 0
#define PIO_OUTPUT_HAS_OUT 1
#define PIO_OUTPUT_HAS_TRI 0
#define PIO_OUTPUT_IRQ -1
#define PIO_OUTPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_OUTPUT_IRQ_TYPE "NONE"
#define PIO_OUTPUT_NAME "/dev/pio_output"
#define PIO_OUTPUT_RESET_VALUE 0
#define PIO_OUTPUT_SPAN 16
#define PIO_OUTPUT_TYPE "altera_avalon_pio"


/*
 * pio_rst configuration
 *
 */

#define ALT_MODULE_CLASS_pio_rst altera_avalon_pio
#define PIO_RST_BASE 0x22160
#define PIO_RST_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RST_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RST_CAPTURE 0
#define PIO_RST_DATA_WIDTH 1
#define PIO_RST_DO_TEST_BENCH_WIRING 0
#define PIO_RST_DRIVEN_SIM_VALUE 0
#define PIO_RST_EDGE_TYPE "NONE"
#define PIO_RST_FREQ 50000000
#define PIO_RST_HAS_IN 0
#define PIO_RST_HAS_OUT 1
#define PIO_RST_HAS_TRI 0
#define PIO_RST_IRQ -1
#define PIO_RST_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RST_IRQ_TYPE "NONE"
#define PIO_RST_NAME "/dev/pio_rst"
#define PIO_RST_RESET_VALUE 0
#define PIO_RST_SPAN 16
#define PIO_RST_TYPE "altera_avalon_pio"


/*
 * pio_start configuration
 *
 */

#define ALT_MODULE_CLASS_pio_start altera_avalon_pio
#define PIO_START_BASE 0x22150
#define PIO_START_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_START_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_START_CAPTURE 0
#define PIO_START_DATA_WIDTH 1
#define PIO_START_DO_TEST_BENCH_WIRING 0
#define PIO_START_DRIVEN_SIM_VALUE 0
#define PIO_START_EDGE_TYPE "NONE"
#define PIO_START_FREQ 50000000
#define PIO_START_HAS_IN 0
#define PIO_START_HAS_OUT 1
#define PIO_START_HAS_TRI 0
#define PIO_START_IRQ -1
#define PIO_START_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_START_IRQ_TYPE "NONE"
#define PIO_START_NAME "/dev/pio_start"
#define PIO_START_RESET_VALUE 0
#define PIO_START_SPAN 16
#define PIO_START_TYPE "altera_avalon_pio"


/*
 * uart_input configuration
 *
 */

#define ALT_MODULE_CLASS_uart_input altera_avalon_uart
#define UART_INPUT_BASE 0x22080
#define UART_INPUT_BAUD 115200
#define UART_INPUT_DATA_BITS 8
#define UART_INPUT_FIXED_BAUD 0
#define UART_INPUT_FREQ 50000000
#define UART_INPUT_IRQ 2
#define UART_INPUT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_INPUT_NAME "/dev/uart_input"
#define UART_INPUT_PARITY 'N'
#define UART_INPUT_SIM_CHAR_STREAM ""
#define UART_INPUT_SIM_TRUE_BAUD 0
#define UART_INPUT_SPAN 32
#define UART_INPUT_STOP_BITS 1
#define UART_INPUT_SYNC_REG_DEPTH 2
#define UART_INPUT_TYPE "altera_avalon_uart"
#define UART_INPUT_USE_CTS_RTS 0
#define UART_INPUT_USE_EOP_REGISTER 0


/*
 * uart_output configuration
 *
 */

#define ALT_MODULE_CLASS_uart_output altera_avalon_uart
#define UART_OUTPUT_BASE 0x220a0
#define UART_OUTPUT_BAUD 115200
#define UART_OUTPUT_DATA_BITS 8
#define UART_OUTPUT_FIXED_BAUD 0
#define UART_OUTPUT_FREQ 50000000
#define UART_OUTPUT_IRQ 3
#define UART_OUTPUT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_OUTPUT_NAME "/dev/uart_output"
#define UART_OUTPUT_PARITY 'N'
#define UART_OUTPUT_SIM_CHAR_STREAM ""
#define UART_OUTPUT_SIM_TRUE_BAUD 0
#define UART_OUTPUT_SPAN 32
#define UART_OUTPUT_STOP_BITS 1
#define UART_OUTPUT_SYNC_REG_DEPTH 2
#define UART_OUTPUT_TYPE "altera_avalon_uart"
#define UART_OUTPUT_USE_CTS_RTS 0
#define UART_OUTPUT_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
