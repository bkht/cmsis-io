#include "main.h"
#include "delay.h"
#include "init_gpio.h"
#include "board_io.h"

// Target Options -> Debug -> ST-Link Debugger Settings -> Flash Download tab
// Right click in projct tree on Target 1
// Options for Target 'Target 1'...
// Tab Debug
// Use: ST-Link Debugger
// Setting
// ST-Link/V2
// Flash Download
// Erase Sectors
// Program
// Verify
// Reset and Run

// Discovery F4 STM32F407VG
// LED Red    LD8 PD5  0=on
// LED Orange LD3 PD13 1=on
// LED Green  LD4 PD12 1=on
// LED Red    LD5 PD14 1=on
// LED Blue   LD6 PD15 1=on
// User Button    PA0  1=pressed

int main()
{
	InitGPIO();	
	
	GPIOD->BSRR = (LED_LD5_R | LED_LD4_G | LED_LD6_B);
	delay(1000000);

	while (1) {
		// Check user button on GPIOA0 is pressed (logic high when pressed)
		if (ButtonIsPressed(USER_BUTTON)) 		{
			// Pressed
			LED_On(LED_LD4_G); // Lit green LED
		} else {
			// Released
			LED_Off(LED_LD4_G); // Dim green LED
		}

		LED_On(LED_LD6_B); // Lit blue LED
		delay(1000000);

		LED_Off(LED_LD6_B); // Dim blue LED
		delay(1000000);
	}
}
