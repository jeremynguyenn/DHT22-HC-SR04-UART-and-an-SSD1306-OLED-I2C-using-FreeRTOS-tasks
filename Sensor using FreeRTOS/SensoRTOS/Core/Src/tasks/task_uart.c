/*
 * task_uart.c
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */
#include "cmsis_os.h"
#include "uart-driver.h"
#include "string.h"
#include "dht22-driver.h"
#include "hc_sr04-driver.h"
#include "ssd1306-i2c-driver.h"
#include "stdint.h"
#include "gpio-driver.h"
#include "delay.h"
#include <stdio.h>

//osThreadId uartTaskHandle;

char rx_buffer[32];
uint8_t rx_index = 0;
uint8_t temperature, humidity;

void UART_Task(void const *argument) {
    UART1_Init();
    UART1_SendString("UART Task Started\r\n");

    while (1) {
        char c = UART1_ReceiveChar();
        UART1_SendChar(c);  // Echo back

        if (c == '\r') {
            rx_buffer[rx_index] = '\0';

            if (strcmp(rx_buffer, "TSTART") == 0) {
                UART1_SendString("Temperature Monitoring Started\r\n");
                while (1) {
                    if (DHT22_Read(&temperature, &humidity)) {
                        char buf[64];
                        sprintf(buf, "Temp: %dC  Hum: %d%%\r\n", temperature, humidity);
                        UART1_SendString(buf);

                        if (temperature > 30) {
                            BUZZER_ON();
                        } else {
                            BUZZER_OFF();
                        }

                        SSD1306_Clear();
                        SSD1306_DisplayString(0, 0, buf);
                    } else {
                        UART1_SendString("DHT22 Error\r\n");
                    }

                    osDelay(1000);

                    if (UART1_CharAvailable()) {
                        UART1_SendString("Monitoring Stopped\r\n");
                        BUZZER_OFF();
                        break;
                    }
                }
            }

            else if (strcmp(rx_buffer, "LED ON") == 0) {
                LED_ON();
                UART1_SendString("LED ON\r\n");
            }

            else if (strcmp(rx_buffer, "LED OFF") == 0) {
                LED_OFF();
                UART1_SendString("LED OFF\r\n");
            }

            else if (strcmp(rx_buffer, "DIST") == 0) {
                UART1_SendString("Distance Monitoring Started\r\n");
                while (1) {
                    uint32_t dist = HC_SR04_Read();
                    char dist_buf[32];
                    sprintf(dist_buf, "Distance: %lu cm\r\n", dist);
                    UART1_SendString(dist_buf);
                    SSD1306_Clear();
                    SSD1306_DisplayString(0, 0, dist_buf);

                    osDelay(500);

                    if (UART1_CharAvailable()) {
                        UART1_SendString("Distance Monitoring Stopped\r\n");
                        break;
                    }
                }
            }

            else {
                UART1_SendString("Unknown Command\r\n");
            }

            rx_index = 0;
        } else if (rx_index < sizeof(rx_buffer) - 1) {
            rx_buffer[rx_index++] = c;
        }

        osDelay(10);
    }
}
