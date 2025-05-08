/*
 * task_display.c
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */
#include "task_display.h"
#include "ssd1306-i2c-driver.h"
#include "hc_sr04-driver.h"
#include "stdio.h"

osThreadId displayTaskHandle;

void Display_Task(void const *argument) {
    char line[32];
    uint32_t distance = 0;

    SSD1306_Init();  // Initialize the OLED display

    while (1) {
        distance = HC_SR04_Read();  // Get distance (in cm)

        SSD1306_Clear();

        if (distance == 0) {
            SSD1306_DisplayString(0, 0, "Distance:");
            SSD1306_DisplayString(1, 0, "Timeout/No object");
        } else {
            SSD1306_DisplayString(0, 0, "Distance:");
            sprintf(line, "%lu cm", distance);
            SSD1306_DisplayString(1, 0, line);
        }

        osDelay(2000);  // Update every 2 seconds
    }
}


