/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "../LEDCube/led_cube.h"

#define TIMER_PLANS		500000

/*!
 * @brief
 */
uint8_t ValueCathode[NUMBER_OF_LEDS_PLANE_MAX][NUMBER_OF_LEDS_PLANE_MAX] =
{
	{0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},  // 0
	{1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1},  // 1
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},  // 2
	{1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0},  // 3
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1},  // 4
	{1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1},  // 5
	{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},  // 6
	{1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1},  // 7
	{1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},  // 8
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0},  // 9
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},  // 10
	{1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1},  // 11
	{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},  // 12
	{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},  // 13
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},  // 14
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},  // 15
};

/*!
 * @brief
 */
uint8_t ValueAnode[NUMBER_OF_PLANS_MAX][NUMBER_OF_PLANS_MAX] =
{
	{1,1,1,1},  // 0
	{1,1,1,1},  // 1
	{1,1,1,1},  // 2
	{1,1,1,1}   // 3
};

/*!
 * @brief
 */
uint32_t timer = TIMER_PLANS;
uint32_t counter = 1000;
/*!
 * @brief Application entry point.
 */
int main(void)
{
	LED_Cube Cube;
	uint8_t i = 0;

	/* Init board hardware. */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	/* Add your code here */
	LEDCube_t config;

	i = 0;
	config.anode[i].gpio = kGPIO_PORTA;
	config.anode[i++].pin = 6U;

	config.anode[i].gpio = kGPIO_PORTA;
	config.anode[i++].pin = 7U;

	config.anode[i].gpio = kGPIO_PORTF;
	config.anode[i++].pin = 6U;

	config.anode[i].gpio = kGPIO_PORTB;
	config.anode[i++].pin = 3U;


	i = 0;
	config.cathode[i].gpio = kGPIO_PORTC;
	config.cathode[i++].pin = 5U;

	config.cathode[i].gpio = kGPIO_PORTD;
	config.cathode[i++].pin = 7U;

	config.cathode[i].gpio = kGPIO_PORTB;
	config.cathode[i++].pin = 2U;

	config.cathode[i].gpio = kGPIO_PORTB;
	config.cathode[i++].pin = 4U;

	config.cathode[i].gpio = kGPIO_PORTD;
	config.cathode[i++].pin = 1U;

	config.cathode[i].gpio = kGPIO_PORTA;
	config.cathode[i++].pin = 1U;

	config.cathode[i].gpio = kGPIO_PORTD;
	config.cathode[i++].pin = 0U;

	config.cathode[i].gpio = kGPIO_PORTA;
	config.cathode[i++].pin = 7U;

	config.cathode[i].gpio = kGPIO_PORTF;
	config.cathode[i++].pin = 7U;

	config.cathode[i].gpio = kGPIO_PORTD;
	config.cathode[i++].pin = 6U;

	config.cathode[i].gpio = kGPIO_PORTE;
	config.cathode[i++].pin = 4U;

	config.cathode[i].gpio = kGPIO_PORTD;
	config.cathode[i++].pin = 5U;

	config.cathode[i].gpio = kGPIO_PORTB;
	config.cathode[i++].pin = 5U;

	config.cathode[i].gpio = kGPIO_PORTH;
	config.cathode[i++].pin = 0U;

	config.cathode[i].gpio = kGPIO_PORTA;
	config.cathode[i++].pin = 0U;

	config.cathode[i].gpio = kGPIO_PORTB;
	config.cathode[i++].pin = 3U;

	Cube.Init(config);
	Cube.SetTimerPlane(timer);
	Cube.SetValue(ValueCathode,ValueAnode);

	for(;;)
	{ 	/* Infinite loop to avoid leaving the main function */
		//__asm("NOP"); /* something to use as a breakpoint stop while looping */

		Cube.Loop();
		if(counter > 0)
		{
			counter--;
		}
		else
		{
			counter = 100000;
			timer /= 10;
			if(timer < 100000)
			{
				timer = TIMER_PLANS;
			}
			//Cube.SetTimerPlane(timer);
		}
	}
}
