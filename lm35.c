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
#include"adc.h"
#include"lm35.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 LM35_GetTemperature( void )
{
#ifdef polling
	uint16 value = ADC_readChannel( LM_CH_NUM ); /* Read digital value from ADC Data register using polling */
#endif

#ifdef interrupt
	/* Read digital value from ADC Data register using interrupt */
	ADC_readChannel( LM_CH_NUM );
	uint16 value = ADC_value;
#endif
	/* Calculate the Temperature sensor value */
	uint8 Temp = (uint8) ( ( (uint32) value * 150 * 2.56 ) / (1.5 * 1023 ) ) ;
	return Temp; /* Return the temperature sensor reading */
}

