/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'DE2_115_SOPC'
 * SOPC Builder design path: ../../DE2_115_SOPC.sopcinfo
 *
 * Generated: Wed Apr 19 01:17:21 VLAT 2023
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
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x09000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x09000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_LCD_16207
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SGDMA
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTPLL
#define __ISP1362_IF
#define __SEG7_IF


/*
 * ISP1362_IF_0_dc configuration
 *
 */

#define ALT_MODULE_CLASS_ISP1362_IF_0_dc ISP1362_IF
#define ISP1362_IF_0_DC_BASE 0x9001098
#define ISP1362_IF_0_DC_IRQ 1
#define ISP1362_IF_0_DC_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ISP1362_IF_0_DC_NAME "/dev/ISP1362_IF_0_dc"
#define ISP1362_IF_0_DC_SPAN 8
#define ISP1362_IF_0_DC_TYPE "ISP1362_IF"


/*
 * ISP1362_IF_0_hc configuration
 *
 */

#define ALT_MODULE_CLASS_ISP1362_IF_0_hc ISP1362_IF
#define ISP1362_IF_0_HC_BASE 0x9001090
#define ISP1362_IF_0_HC_IRQ 2
#define ISP1362_IF_0_HC_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ISP1362_IF_0_HC_NAME "/dev/ISP1362_IF_0_hc"
#define ISP1362_IF_0_HC_SPAN 8
#define ISP1362_IF_0_HC_TYPE "ISP1362_IF"


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
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x90010a0
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x90010a0
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x90010a0
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "DE2_115_SOPC"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x90010a0
#define JTAG_UART_IRQ 6
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x8000050
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 1
#define KEY_DATA_WIDTH 4
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "FALLING"
#define KEY_FREQ 10000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 4
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "EDGE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * lcd configuration
 *
 */

#define ALT_MODULE_CLASS_lcd altera_avalon_lcd_16207
#define LCD_BASE 0x8000060
#define LCD_IRQ -1
#define LCD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_NAME "/dev/lcd"
#define LCD_SPAN 16
#define LCD_TYPE "altera_avalon_lcd_16207"


/*
 * lcd_sgdma configuration
 *
 */

#define ALT_MODULE_CLASS_lcd_sgdma altera_avalon_sgdma
#define LCD_SGDMA_ADDRESS_WIDTH 32
#define LCD_SGDMA_ALWAYS_DO_MAX_BURST 1
#define LCD_SGDMA_ATLANTIC_CHANNEL_DATA_WIDTH 4
#define LCD_SGDMA_AVALON_MM_BYTE_REORDER_MODE 0
#define LCD_SGDMA_BASE 0x9001000
#define LCD_SGDMA_BURST_DATA_WIDTH 8
#define LCD_SGDMA_BURST_TRANSFER 0
#define LCD_SGDMA_BYTES_TO_TRANSFER_DATA_WIDTH 16
#define LCD_SGDMA_CHAIN_WRITEBACK_DATA_WIDTH 32
#define LCD_SGDMA_COMMAND_FIFO_DATA_WIDTH 104
#define LCD_SGDMA_CONTROL_DATA_WIDTH 8
#define LCD_SGDMA_CONTROL_SLAVE_ADDRESS_WIDTH 0x4
#define LCD_SGDMA_CONTROL_SLAVE_DATA_WIDTH 32
#define LCD_SGDMA_DESCRIPTOR_READ_BURST 0
#define LCD_SGDMA_DESC_DATA_WIDTH 32
#define LCD_SGDMA_HAS_READ_BLOCK 1
#define LCD_SGDMA_HAS_WRITE_BLOCK 0
#define LCD_SGDMA_IN_ERROR_WIDTH 0
#define LCD_SGDMA_IRQ 0
#define LCD_SGDMA_IRQ_INTERRUPT_CONTROLLER_ID 0
#define LCD_SGDMA_NAME "/dev/lcd_sgdma"
#define LCD_SGDMA_OUT_ERROR_WIDTH 0
#define LCD_SGDMA_READ_BLOCK_DATA_WIDTH 32
#define LCD_SGDMA_READ_BURSTCOUNT_WIDTH 4
#define LCD_SGDMA_SPAN 64
#define LCD_SGDMA_STATUS_TOKEN_DATA_WIDTH 24
#define LCD_SGDMA_STREAM_DATA_WIDTH 32
#define LCD_SGDMA_SYMBOLS_PER_BEAT 4
#define LCD_SGDMA_TYPE "altera_avalon_sgdma"
#define LCD_SGDMA_UNALIGNED_TRANSFER 0
#define LCD_SGDMA_WRITE_BLOCK_DATA_WIDTH 32
#define LCD_SGDMA_WRITE_BURSTCOUNT_WIDTH 4


/*
 * ledg configuration
 *
 */

#define ALT_MODULE_CLASS_ledg altera_avalon_pio
#define LEDG_BASE 0x8000030
#define LEDG_BIT_CLEARING_EDGE_REGISTER 0
#define LEDG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDG_CAPTURE 0
#define LEDG_DATA_WIDTH 9
#define LEDG_DO_TEST_BENCH_WIRING 0
#define LEDG_DRIVEN_SIM_VALUE 0
#define LEDG_EDGE_TYPE "NONE"
#define LEDG_FREQ 10000000
#define LEDG_HAS_IN 0
#define LEDG_HAS_OUT 1
#define LEDG_HAS_TRI 0
#define LEDG_IRQ -1
#define LEDG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDG_IRQ_TYPE "NONE"
#define LEDG_NAME "/dev/ledg"
#define LEDG_RESET_VALUE 0
#define LEDG_SPAN 16
#define LEDG_TYPE "altera_avalon_pio"


/*
 * ledr configuration
 *
 */

#define ALT_MODULE_CLASS_ledr altera_avalon_pio
#define LEDR_BASE 0x8000020
#define LEDR_BIT_CLEARING_EDGE_REGISTER 0
#define LEDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDR_CAPTURE 0
#define LEDR_DATA_WIDTH 18
#define LEDR_DO_TEST_BENCH_WIRING 0
#define LEDR_DRIVEN_SIM_VALUE 0
#define LEDR_EDGE_TYPE "NONE"
#define LEDR_FREQ 10000000
#define LEDR_HAS_IN 0
#define LEDR_HAS_OUT 1
#define LEDR_HAS_TRI 0
#define LEDR_IRQ -1
#define LEDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDR_IRQ_TYPE "NONE"
#define LEDR_NAME "/dev/ledr"
#define LEDR_RESET_VALUE 0
#define LEDR_SPAN 16
#define LEDR_TYPE "altera_avalon_pio"


/*
 * pll configuration
 *
 */

#define ALT_MODULE_CLASS_pll altpll
#define PLL_BASE 0x9001080
#define PLL_IRQ -1
#define PLL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PLL_NAME "/dev/pll"
#define PLL_SPAN 16
#define PLL_TYPE "altpll"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 32
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SPAN 134217728
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sdram configuration as viewed by lcd_sgdma_m_read
 *
 */

#define LCD_SGDMA_M_READ_SDRAM_BASE 0x0
#define LCD_SGDMA_M_READ_SDRAM_CAS_LATENCY 3
#define LCD_SGDMA_M_READ_SDRAM_CONTENTS_INFO
#define LCD_SGDMA_M_READ_SDRAM_INIT_NOP_DELAY 0.0
#define LCD_SGDMA_M_READ_SDRAM_INIT_REFRESH_COMMANDS 2
#define LCD_SGDMA_M_READ_SDRAM_IRQ -1
#define LCD_SGDMA_M_READ_SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_SGDMA_M_READ_SDRAM_IS_INITIALIZED 1
#define LCD_SGDMA_M_READ_SDRAM_NAME "/dev/sdram"
#define LCD_SGDMA_M_READ_SDRAM_POWERUP_DELAY 100.0
#define LCD_SGDMA_M_READ_SDRAM_REFRESH_PERIOD 15.625
#define LCD_SGDMA_M_READ_SDRAM_REGISTER_DATA_IN 1
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_ADDR_WIDTH 0x19
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_BANK_WIDTH 2
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_COL_WIDTH 10
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_DATA_WIDTH 32
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_NUM_BANKS 4
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define LCD_SGDMA_M_READ_SDRAM_SDRAM_ROW_WIDTH 13
#define LCD_SGDMA_M_READ_SDRAM_SHARED_DATA 0
#define LCD_SGDMA_M_READ_SDRAM_SIM_MODEL_BASE 1
#define LCD_SGDMA_M_READ_SDRAM_SPAN 134217728
#define LCD_SGDMA_M_READ_SDRAM_STARVATION_INDICATOR 0
#define LCD_SGDMA_M_READ_SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define LCD_SGDMA_M_READ_SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define LCD_SGDMA_M_READ_SDRAM_T_AC 5.5
#define LCD_SGDMA_M_READ_SDRAM_T_MRD 3
#define LCD_SGDMA_M_READ_SDRAM_T_RCD 20.0
#define LCD_SGDMA_M_READ_SDRAM_T_RFC 70.0
#define LCD_SGDMA_M_READ_SDRAM_T_RP 20.0
#define LCD_SGDMA_M_READ_SDRAM_T_WR 14.0


/*
 * seg7 configuration
 *
 */

#define ALT_MODULE_CLASS_seg7 SEG7_IF
#define SEG7_BASE 0x8000000
#define SEG7_IRQ -1
#define SEG7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG7_NAME "/dev/seg7"
#define SEG7_SPAN 32
#define SEG7_TYPE "SEG7_IF"


/*
 * sw configuration
 *
 */

#define ALT_MODULE_CLASS_sw altera_avalon_pio
#define SW_BASE 0x8000040
#define SW_BIT_CLEARING_EDGE_REGISTER 0
#define SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_CAPTURE 1
#define SW_DATA_WIDTH 18
#define SW_DO_TEST_BENCH_WIRING 0
#define SW_DRIVEN_SIM_VALUE 0
#define SW_EDGE_TYPE "FALLING"
#define SW_FREQ 10000000
#define SW_HAS_IN 1
#define SW_HAS_OUT 0
#define SW_HAS_TRI 0
#define SW_IRQ 5
#define SW_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SW_IRQ_TYPE "EDGE"
#define SW_NAME "/dev/sw"
#define SW_RESET_VALUE 0
#define SW_SPAN 16
#define SW_TYPE "altera_avalon_pio"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x8000070
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1681825803
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x9001040
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 10000000
#define TIMER_IRQ 3
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 9999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * timer_stamp configuration
 *
 */

#define ALT_MODULE_CLASS_timer_stamp altera_avalon_timer
#define TIMER_STAMP_ALWAYS_RUN 0
#define TIMER_STAMP_BASE 0x9001060
#define TIMER_STAMP_COUNTER_SIZE 32
#define TIMER_STAMP_FIXED_PERIOD 0
#define TIMER_STAMP_FREQ 100000000
#define TIMER_STAMP_IRQ 7
#define TIMER_STAMP_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_STAMP_LOAD_VALUE 99999
#define TIMER_STAMP_MULT 0.001
#define TIMER_STAMP_NAME "/dev/timer_stamp"
#define TIMER_STAMP_PERIOD 1
#define TIMER_STAMP_PERIOD_UNITS "ms"
#define TIMER_STAMP_RESET_OUTPUT 0
#define TIMER_STAMP_SNAPSHOT 1
#define TIMER_STAMP_SPAN 32
#define TIMER_STAMP_TICKS_PER_SEC 1000
#define TIMER_STAMP_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_STAMP_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
