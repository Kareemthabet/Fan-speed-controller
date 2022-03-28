 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Kareem Ahmed Thabet
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

extern volatile uint8 ADC_read;
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define CH_NUM 2
#define polling

/*******************************************************************************
 *                             Enums and Structures Definitions                 *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL_AREF

}ADC_ReferenceVoltage;

typedef enum{
	F_CPU_0, CPU_2, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init( const ADC_ConfigType *Config_ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver using polling.
 */
#ifdef polling
uint16 ADC_readChannel( uint8 ch_num );
#endif

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver using interrupts.
 */
#ifdef interrupt
void ADC_readChannel( uint8 ch_num );
#endif


#endif /* ADC_H_ */
