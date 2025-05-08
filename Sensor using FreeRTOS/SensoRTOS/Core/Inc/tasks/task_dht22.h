/*
 * task-dht22.h
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */

#ifndef INC_TASKS_TASK_DHT22_H_
#define INC_TASKS_TASK_DHT22_H_
#include "cmsis_os.h"

extern osThreadId dht22TaskHandle;

void DHT22_Task(void const *argument);


#endif /* INC_TASKS_TASK_DHT22_H_ */
