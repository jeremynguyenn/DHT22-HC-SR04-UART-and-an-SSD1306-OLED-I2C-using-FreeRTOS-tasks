/*
 * hc_sr04-driver.c
 *
 *  Created on: May 3, 2025
 *      Author: sande
 */
#include "stm32f103xb.h"
#include "delay.h"
#include "uart-driver.h"
#include "hc_sr04-driver.h"

#define TRIG_PIN 1
#define ECHO_PIN 2

#define TRIG_PORT GPIOA
#define ECHO_PORT GPIOA

void HC_SR04_Init(void) {
    // Enable GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // --- TRIG: PA1 as Output Push-Pull ---
    TRIG_PORT->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);         // Clear bits
    TRIG_PORT->CRL |= (0b10 << GPIO_CRL_MODE1_Pos);              // Output mode, 2 MHz
    TRIG_PORT->CRL |= (0b00 << GPIO_CRL_CNF1_Pos);               // Push-pull

    // --- ECHO: PA2 as Floating Input ---
    ECHO_PORT->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);         // Clear bits
    ECHO_PORT->CRL |= (0b01 << GPIO_CRL_CNF2_Pos);               // Floating input
}


uint32_t HC_SR04_Read(void) {
    uint32_t time_us = 0;
    uint32_t timeout = 0;

    // Ensure trigger is low
    TRIG_PORT->ODR &= ~(1 << TRIG_PIN);
    delay_us(2);

    // Trigger high for 10us
    TRIG_PORT->ODR |= (1 << TRIG_PIN);
    delay_us(10);
    TRIG_PORT->ODR &= ~(1 << TRIG_PIN);

    // Wait for ECHO to go HIGH (with timeout)
    timeout = 0;
    while (!(ECHO_PORT->IDR & (1 << ECHO_PIN))) {
        delay_us(1);
        if (++timeout > 3000) return 0;  // Timeout after 30 ms
    }

    // Measure HIGH pulse duration
    time_us = 0;
    while (ECHO_PORT->IDR & (1 << ECHO_PIN)) {
        delay_us(1);
        time_us++;
        if (time_us > 3000) break;  // Timeout after 30 ms
    }

    return time_us / 58;  // Distance in cm
}

