/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* USER CODE BEGIN 0 */
#define RCC_BASE            0x40021000UL


#define RCC_APB2ENR         (*(volatile unsigned int *)(RCC_BASE + 0x18))

#define GPIOC_BASE          0x40011000UL

#define GPIOC_CRH           (*(volatile unsigned int *)(GPIOC_BASE + 0x04))

#define GPIOC_ODR           (*(volatile unsigned int *)(GPIOC_BASE + 0x0C))

int main(void)
{

    RCC_APB2ENR |= (1 << 4);

    GPIOC_CRH &= ~(0xF << 20);

    GPIOC_CRH |= (0x2 << 20);

    // The main loop
    while(1)
    {
        GPIOC_ODR ^= (1 << 13);
        for(volatile int i = 0; i < 100000; i++);
    }

    return 0;
}

