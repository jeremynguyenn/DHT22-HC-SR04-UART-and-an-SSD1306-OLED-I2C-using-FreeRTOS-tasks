/*
 * gpio-driver.c
 *
 *  Created on: May 3, 2025
 *      Author: sandeep
 */
#include "stm32f103xb.h"
#include "gpio-driver.h"

void GPIO_Init(void) {
    // Enable clock for GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA5 as push-pull output (50 MHz)
    GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
    GPIOA->CRL |=  (GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0); // Output mode, 50 MHz
    GPIOA->CRL |=  0x0;                                   // General purpose output push-pull
    // Configure PA6 as push-pull output (for Buzzer)
    GPIOA->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6);
    GPIOA->CRL |=  (GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0); // Output mode, 50 MHz
    GPIOA->CRL |=  0x0;                                   // General purpose output push-pull
 }

void LED_ON(void) {
    GPIOA->BSRR = GPIO_BSRR_BS5;
}

void LED_OFF(void) {
    GPIOA->BSRR = GPIO_BSRR_BR5;
}

void BUZZER_ON(void) {
    GPIOA->BSRR = GPIO_BSRR_BS6;  // Set PA6 high
}

void BUZZER_OFF(void) {
    GPIOA->BSRR = GPIO_BSRR_BR6;  // Set PA6 low
}

