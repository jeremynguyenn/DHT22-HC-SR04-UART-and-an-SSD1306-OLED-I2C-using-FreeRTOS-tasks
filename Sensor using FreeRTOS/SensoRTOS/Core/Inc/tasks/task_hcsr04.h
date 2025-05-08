/*
 * task-hcsr04.h
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */

#ifndef INC_TASKS_TASK_HCSR04_H_
#define INC_TASKS_TASK_HCSR04_H_
#include "cmsis_os.h"

extern osThreadId hcsr04TaskHandle;
void HCSR04_Task(void const *argument);

#endif /* INC_TASKS_TASK_HCSR04_H_ */
