 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer0.c
 *
 * Description: Source file for the ATmega16 Timer0 driver
 *
 * Author: Kareem Ahmed Thabet
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID PORTB_ID
#define PWM_PIN_ID PIN3

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the Timer0 driver.
 */
void PWM_Timer0_init( uint8 speed );


#endif /* TIMER0_H_ */
