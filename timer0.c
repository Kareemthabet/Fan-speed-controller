 /******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kareem Ahmed Thabet
 *
 *******************************************************************************/

#include"gpio.h"
#include"timer0.h"
#include<avr/io.h>

void PWM_Timer0_init( uint8 speed )
{
	TCNT0 = 0; //Set Timer Initial value
	OCR0  = ( (speed*255) / 100 ); // Set Compare Value
	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,LOGIC_HIGH);
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

