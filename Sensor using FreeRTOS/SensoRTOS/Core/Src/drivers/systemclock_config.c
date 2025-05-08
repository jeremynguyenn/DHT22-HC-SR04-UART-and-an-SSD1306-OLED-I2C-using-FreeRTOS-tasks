/*
 * systemclock_config.c
 *
 *  Created on: May 4, 2025
 *      Author: sande
 */
#include "stm32f103xb.h"

void SystemClock_Config(void) {
    // Enable HSE (High-Speed External) oscillator
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));  // Wait until HSE is ready

    // Configure Flash latency (2 wait states for 72 MHz)
    FLASH->ACR |= FLASH_ACR_PRFTBE;       // Enable Prefetch Buffer
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR |= FLASH_ACR_LATENCY_2;    // 2 wait states

    // Configure PLL
    RCC->CFGR &= ~RCC_CFGR_PLLSRC;        // Clear PLL source
    RCC->CFGR |= RCC_CFGR_PLLSRC;         // HSE oscillator clock selected as PLL input
    RCC->CFGR &= ~RCC_CFGR_PLLMULL;
    RCC->CFGR |= RCC_CFGR_PLLMULL9;       // PLL = 8 MHz * 9 = 72 MHz

    RCC->CR |= RCC_CR_PLLON;              // Enable PLL
    while (!(RCC->CR & RCC_CR_PLLRDY));   // Wait until PLL is ready

    // Select PLL as system clock source
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);  // Wait until PLL is system clock

    // Set HCLK = SYSCLK
    RCC->CFGR &= ~RCC_CFGR_HPRE;

    // Set PCLK1 = HCLK/2
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Set PCLK2 = HCLK
    RCC->CFGR &= ~RCC_CFGR_PPRE2;

    // Optional: Enable GPIO clocks if not already done
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |
                    RCC_APB2ENR_IOPBEN |
                    RCC_APB2ENR_IOPCEN |
                    RCC_APB2ENR_AFIOEN;
}


