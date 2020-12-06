/*
 * led_cube.h
 *
 *  Created on: 28/11/2020
 *      Author: evandro
 */

#ifndef LEDCUBE_LED_CUBE_H_
#define LEDCUBE_LED_CUBE_H_


#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

/**
 *
 */
#define NUMBER_OF_PLANS_MAX			4	// number of plans
#define NUMBER_OF_LEDS_PLANE_MAX	16	// number of LEDs per plane
#define DEFAULT_TIMER_PLANE			1000000

/**
 *
 */
typedef struct
{
	gpio_port_num_t gpio;
	uint32_t pin;
}LEDCube_pin_t;

/**
 *
 */
typedef struct
{
	LEDCube_pin_t cathode[NUMBER_OF_LEDS_PLANE_MAX];
	LEDCube_pin_t anode[NUMBER_OF_PLANS_MAX];
}LEDCube_t;

/**
 *
 */
class LED_Cube
{
private:
	LEDCube_t Pin;
	uint32_t CounterPlans;
	uint32_t CounterLEDs;
	uint8_t  Value_Cathode[NUMBER_OF_LEDS_PLANE_MAX][NUMBER_OF_LEDS_PLANE_MAX];
	uint8_t  Value_Anode[NUMBER_OF_PLANS_MAX][NUMBER_OF_PLANS_MAX];
	uint32_t Timer_Plane = DEFAULT_TIMER_PLANE;
public:
	//LED_Cube();
	//~LED_Cube();
	void Init(LEDCube_t pin);
	void Loop(void);
	void SetTimerPlane(uint32_t timer);
	uint32_t GetTimerPlane(void);
	void SetValue(uint8_t cathode[NUMBER_OF_LEDS_PLANE_MAX][NUMBER_OF_LEDS_PLANE_MAX],
				uint8_t anode[NUMBER_OF_PLANS_MAX][NUMBER_OF_PLANS_MAX]);
};


#endif /* LEDCUBE_LED_CUBE_H_ */
