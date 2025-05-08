/*
 * task_dht22.c
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */
#include "task_dht22.h"
#include "dht22-driver.h"
#include "uart-driver.h"
#include "stdio.h"

osThreadId dht22TaskHandle;

void DHT22_Task(void const *argument) {
    uint8_t temperature = 0;
    uint8_t humidity = 0;
    char buffer[64];

    DHT22_Init();  // Initialize GPIO and pull-up

    while (1) {
        if (DHT22_Read(&temperature, &humidity)) {
            sprintf(buffer, "Temp: %dC  Humidity: %d%%\r\n", temperature, humidity);
        } else {
            sprintf(buffer, "DHT22 read failed\r\n");
        }
        UART1_SendString(buffer);
        osDelay(5000);  // Read every 5 seconds
    }
}


