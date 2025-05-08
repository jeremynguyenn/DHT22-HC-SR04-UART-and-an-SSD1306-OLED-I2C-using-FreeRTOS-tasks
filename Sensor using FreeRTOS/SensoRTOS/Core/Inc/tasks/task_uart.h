/*
 * task-uart.h
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */

#ifndef INC_TASKS_TASK_UART_H_
#define INC_TASKS_TASK_UART_H_
#include "cmsis_os.h"

extern osThreadId uartTaskHandle;
void UART_Task(void const *argument);

#endif /* INC_TASKS_TASK_UART_H_ */
