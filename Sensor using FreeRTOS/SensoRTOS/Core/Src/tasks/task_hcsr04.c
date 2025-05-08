/*
 * task_hcsr04.c
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */
#include "task_hcsr04.h"
#include "hc_sr04-driver.h"
#include "uart-driver.h"
#include "stdio.h"

osThreadId hcsr04TaskHandle;

void HCSR04_Task(void const *argument) {
    uint32_t distance_cm = 0;
    char buffer[64];

    HC_SR04_Init();  // Set up GPIO for trigger and echo

    while (1) {
        distance_cm = HC_SR04_Read();
        if (distance_cm == 0) {
            UART1_SendString("HC-SR04 read timeout\r\n");
        } else {
            sprintf(buffer, "Distance: %lu cm\r\n", distance_cm);
            UART1_SendString(buffer);
        }
        osDelay(2000);  // Sample every 2 seconds
    }
}


