#ifndef CONFIG_H
#define CONFIG_H

#if G4
#include "stm32g4xx_hal.h"
#define LED_PIN                                GPIO_PIN_5 // for g4 board
#define LED_GPIO_PORT                          GPIOA
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()
// #define ReadPin                                HAL_GPIO_ReadPin

// Blue pushbutton - PC13


#elif H7
#include "stm32h7xx_hal.h"
#define LED_PIN                                GPIO_PIN_0 // for h7 board
#define LED_GPIO_PORT                          GPIOB
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()

#else
#error "Unsupported STM32 Family"
#endif

#endif
