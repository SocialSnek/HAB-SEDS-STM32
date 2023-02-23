#ifndef CONFIG_H
#define CONFIG_H

#if G4
#include "stm32g4xx_hal.h"

#define LOW                                 GPIO_PIN_RESET
#define HIGH                                GPIO_PIN_SET

// LED
#define LED_PIN                             GPIO_PIN_5 // for g4 board
#define LED_GPIO_PORT                       GPIOA
#define LED_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOA_CLK_ENABLE()
#define ReadPin                             HAL_GPIO_ReadPin
#define TogglePin                           HAL_GPIO_TogglePin
#define PinState                            GPIO_PinState

#define PUSHBUTTON_PIN                      GPIO_PIN_13
#define PUSHBUTTON_GPIO_PORT                GPIOC
#define PUSHBUTTON_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOC_CLK_ENABLE()

// Blue pushbutton - PC13


#elif H7
#include "stm32h7xx_hal.h"

// LED
#define LED_PIN                             GPIO_PIN_0 // for h7 board
#define LED_GPIO_PORT                       GPIOB
#define LED_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOB_CLK_ENABLE()


// Analog Pin

// #define ADC_PIN                             GPIO_PIN_0
// #define ADC_GPIO_PORT                       GPIOC
// #define ADC_CLK_ENABLE()                    __HAL_RCC_ADC_CLK_ENABLE()
// #define ADC_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()

#else
#error "Unsupported STM32 Family"
#endif

#endif
