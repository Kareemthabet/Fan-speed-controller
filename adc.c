 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kareem Ahmed Thabet
 *
 *******************************************************************************/

#include"adc.h"
#include"common_macros.h" /* To use the macros like SET_BIT */
#include<avr/io.h> /* To use the ADC Registers */
#include<avr/interrupt.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
volatile uint16 ADC_value;


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void ADC_init( const ADC_ConfigType *Config_ptr )
{
	ADMUX = ( ( Config_ptr->ref_volt ) << 6 ); /* Configure the reference voltage */
	ADCSRA = ( ADCSRA & 0xf8 ) | ( Config_ptr->prescaler);       /* Configure the ADC frequency */
	ADCSRA |= (1<<ADEN);  /*Enable ADC */
}

#ifdef polling
uint16 ADC_readChannel( uint8 ch_num )
{
	ADMUX =( 0XE0 & ADMUX ) | ( 0x07 & ch_num ); /* Configure the channel number */
	ADCSRA |= (1<<ADSC);  /* Start conversion write '1' to ADSC */
	while( BIT_IS_CLEAR(ADCSRA,ADIF) ); /* Wait for conversion to complete, ADIF becomes '1' */
	ADCSRA |= (1<<ADIF); /* Clear ADIF by write '1' to it */
	return ADC; /* Read the digital value from the data register */
}
#endif
#ifdef interrupt
void uint16 ADC_readChannel( uint8 ch_num )
{
	ADMUX =( 0XE0 & ADMUX ) | ( 0x07 & ch_num );  /* Configure the channel number */
	ADCSRA |= (1<<ADSC);      /* Start conversion write '1' to ADSC */
	ADCSRA |= (1<<ADIE);      /* Enable the ADC interrupt */

}
ISR(ADC_vect)
{
	ADC_value = ADC;   /* Save the ADC value */
}
#endif


