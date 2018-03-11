#include "board_io.h"

void LED_On(uint16_t led)
{
	GPIOD->BSRR = led; // Lit green LED
}

void LED_Off(uint16_t led)
{
	GPIOD->BSRR = (led<<16); // Dim green LED
}

void LED_Set(uint16_t led, uint8_t status)
{
	if (status) {
		GPIOD->BSRR = led; // Lit green LED
	} else {
		GPIOD->BSRR = (led<<16); // Dim green LED
	}
}

uint8_t ButtonIsPressed(uint16_t button)
{
	return (GPIOA->IDR & button) == 0 ? 0 : 1;
}
