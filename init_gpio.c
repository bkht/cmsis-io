#include "init_gpio.h"

void InitGPIO(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            // enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;            // enable clock for GPIOD

	GPIOD->MODER = 0x55000000;
	GPIOD->OSPEEDR = 0;
	GPIOD->OTYPER = 0;
	GPIOD->PUPDR = 0;
//	GPIOD->BSRR = (LED_LD5_R | LED_LD4_G | LED_LD6_B);
//	GPIOD->ODR |= (LED_LD5_R | LED_LD4_G | LED_LD6_B); // set PD12 thru PD15

    // Now, lock GPIOD configuration
	GPIOD->LCKR = (LED_LD5_R | LED_LD4_G | LED_LD6_B | LED_LD3_O | LED_LD8_R | LCKK);
	GPIOD->LCKR = (LED_LD5_R | LED_LD4_G | LED_LD6_B | LED_LD3_O | LED_LD8_R);
	GPIOD->LCKR = (LED_LD5_R | LED_LD4_G | LED_LD6_B | LED_LD3_O | LED_LD8_R | LCKK);
	uint32_t locked = GPIOD->LCKR;
	locked = GPIOD->LCKR;	// 2nd read needed, as the LCKK bit is updated after the first read
	if (locked & LCKK) {
		GPIOD->BSRR = LED_LD3_O;	// Orange LED indicates successful lock
	}
}
