#include "../Config.h"
#include <string.h>
// #include "main.h"
// #include "Drivers/AnalogPin/AnalogPin.hpp"
// #include "Drivers/Pushbutton/Pushbutton.hpp"


int main(void) {

  // uint8_t buf[12];
  HAL_Init();
  // MX_USART3_UART_Init();

  LED_GPIO_CLK_ENABLE();
  PUSHBUTTON_GPIO_CLK_ENABLE();
  // HAL_SYSTICK_Config(100);

  GPIO_InitTypeDef GPIO_LED;
  GPIO_InitTypeDef GPIO_PUSHBUTTON;
  // GPIO_InitTypeDef GPIO_ADC1;

  GPIO_LED.Pin = LED_PIN;
  GPIO_LED.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_LED.Pull = GPIO_PULLUP;
  GPIO_LED.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_LED);

  GPIO_PUSHBUTTON.Pin = PUSHBUTTON_PIN;
  GPIO_PUSHBUTTON.Mode = GPIO_MODE_INPUT;
  // GPIO_PUSHBUTTON.Pull = GPIO_NOPULL;
  GPIO_PUSHBUTTON.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(PUSHBUTTON_GPIO_PORT, &GPIO_PUSHBUTTON);

  PinState lastState = LOW;

  // GPIO_ADC1.Pin = ADC_PIN;
  // GPIO_ADC1.Mode = GPIO_MODE_ANALOG;
  // GPIO_ADC1.Pull = GPIO_NOPULL;
  // GPIO_ADC1.Speed = GPIO_SPEED_FREQ_HIGH;
  // HAL_ADC_Init(ADC_GPIO_PORT, &GPIO_ADC1);

  // PUSHBUTTON pushbutton;
  // pushbutton.PUSHBUTTON_Setup();


  /*
  #define PUSHBUTTON_PIN                      GPIO_PIN_13
#define PUSHBUTTON_GPIO_PORT                GPIOC
#define PUSHBUTTON_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOC_CLK_ENABLE()*/

  while (1) {
    // strcpy((char*)buf, "Hello!\r\n");
    // HAL_UART_Transmit(&huart3, buf, strlen((char*)buf), 200);
    PinState buttonState = ReadPin(PUSHBUTTON_GPIO_PORT, PUSHBUTTON_PIN);

    if (buttonState == HIGH){
        if (lastState == LOW) {
            TogglePin(LED_GPIO_PORT, LED_PIN);
        }
        lastState = HIGH;
    }
    else {
      lastState = LOW;
    }

    HAL_Delay(100);
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

// UART_HandleTypeDef huart3;
//
// void Error_Handler(void)
// {
//   /* USER CODE BEGIN Error_Handler_Debug */
//   /* User can add his own implementation to report the HAL error return state */
//   __disable_irq();
//   while (1)
//   {
//   }
//   /* USER CODE END Error_Handler_Debug */
// }
//
// static void MX_USART3_UART_Init(void)
// {
//
//   /* USER CODE BEGIN USART3_Init 0 */
//
//   /* USER CODE END USART3_Init 0 */
//
//   /* USER CODE BEGIN USART3_Init 1 */
//
//   /* USER CODE END USART3_Init 1 */
//   huart3.Instance = USART3;
//   huart3.Init.BaudRate = 115200;
//   huart3.Init.WordLength = UART_WORDLENGTH_8B;
//   huart3.Init.StopBits = UART_STOPBITS_1;
//   huart3.Init.Parity = UART_PARITY_NONE;
//   huart3.Init.Mode = UART_MODE_TX_RX;
//   huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//   huart3.Init.OverSampling = UART_OVERSAMPLING_16;
//   huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//   huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
//   huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//   if (HAL_UART_Init(&huart3) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /* USER CODE BEGIN USART3_Init 2 */
//
//   /* USER CODE END USART3_Init 2 */
//
// }
