 /******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.c
 *
 * Description: Source file for the ATmega16 LM35 driver
 *
 * Author: Kareem Ahmed Thabet
 *
 *******************************************************************************/

#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LM_CH_NUM 2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the LM35 driver.
 */
uint8 LM35_GetTemperature( void );

#endif /* LM35_H_ */
