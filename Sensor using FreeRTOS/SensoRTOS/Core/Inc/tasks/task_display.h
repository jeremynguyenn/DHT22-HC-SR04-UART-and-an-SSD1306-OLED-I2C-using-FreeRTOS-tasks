/*
 * task_display.h
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */

#ifndef INC_TASKS_TASK_DISPLAY_H_
#define INC_TASKS_TASK_DISPLAY_H_
#include "cmsis_os.h"

extern osThreadId displayTaskHandle;
void Display_Task(void const *argument);

#endif /* INC_TASKS_TASK_DISPLAY_H_ */
