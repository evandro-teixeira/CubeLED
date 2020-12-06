/*
 * led_cube.cpp
 *
 *  Created on: 28/11/2020
 *      Author: evandro
 */

#include "led_cube.h"
#include <stddef.h>

/**
 *
 */
void LED_Cube::Init(LEDCube_t pin)
{
	gpio_pin_config_t PinLED = {kGPIO_DigitalOutput, 1,};
	uint8_t i = 0;
	Pin = pin;

	for(i=0;i<NUMBER_OF_PLANS_MAX;i++)
	{
		/* Initializes pins that drives the LED anode pins */
		GPIO_PinInit(Pin.anode[i].gpio, Pin.anode[i].pin,&PinLED);
	}

	PinLED.outputLogic = 0;
	for(i=0;i<NUMBER_OF_LEDS_PLANE_MAX;i++)
	{
		/* Initializes pins that drives the LED cathode pins */
		GPIO_PinInit(Pin.cathode[i].gpio, Pin.cathode[i].pin, &PinLED);
	}
}

/**
 *
 */
void LED_Cube::Loop(void)
{
	//static uint8_t value_anode = 1;
	static uint8_t index_anode = 0;
	static uint8_t index_cathode = 0;
	uint8_t i = 0;

	if(CounterPlans > 0)
	{
		CounterPlans--;
		if(CounterLEDs > 0)
		{
			CounterLEDs--;
		}
		else
		{
			PRINTF("\n\rLEDs Index: %d",index_cathode);
			CounterLEDs = (uint32_t)(Timer_Plane/NUMBER_OF_LEDS_PLANE_MAX);
			for(i=0;i<NUMBER_OF_LEDS_PLANE_MAX;i++)
			{
				GPIO_PinWrite(Pin.cathode[i].gpio,Pin.cathode[i].pin, Value_Cathode[index_cathode][i]);
			}
			index_cathode++;
			if(index_cathode >= NUMBER_OF_LEDS_PLANE_MAX)
			{
				index_cathode = 0;
			}
		}
	}
	else
	{
		PRINTF("\n\rPlans Index: %d",index_anode);
		CounterPlans = Timer_Plane;
		CounterLEDs = 0;
		for(i=0;i<NUMBER_OF_PLANS_MAX;i++)
		{
			GPIO_PinWrite(Pin.anode[i].gpio,Pin.anode[i].pin, Value_Anode[index_anode][i] );
		}
		index_anode++;
		if(index_anode >= NUMBER_OF_PLANS_MAX)
		{
			index_anode = 0;
		}
	}
}
/**
 *
 */
void LED_Cube::SetTimerPlane(uint32_t timer)
{
	Timer_Plane = timer;
}
/**
 *
 */
uint32_t LED_Cube::GetTimerPlane(void)
{
	return Timer_Plane;
}
/**
 *
 */
void LED_Cube::SetValue(uint8_t cathode[NUMBER_OF_LEDS_PLANE_MAX][NUMBER_OF_LEDS_PLANE_MAX],
					uint8_t anode[NUMBER_OF_PLANS_MAX][NUMBER_OF_PLANS_MAX])
{
	uint8_t i = 0, x = 0;

	for(i=0;i<NUMBER_OF_LEDS_PLANE_MAX;i++)
	{
		for(x=0;x<NUMBER_OF_LEDS_PLANE_MAX;x++)
		{
			//if(cathode[i][x] == NULL)
			//{
			//	break;
			//}
			//else
			//{
				Value_Cathode[i][x] = cathode[i][x];
			//}
		}
	}

	for(i=0;i<NUMBER_OF_PLANS_MAX;i++)
	{
		for(x=0;x<NUMBER_OF_PLANS_MAX;x++)
		{
			//if(anode[i][x] == NULL)
			//{
			//	break;
			//}
			//else
			//{
				Value_Anode[i][x] = anode[i][x];
			//}
		}
	}
}
