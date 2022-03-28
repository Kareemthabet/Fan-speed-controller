/*
 * main.c
 *
 *  Created on: Oct 18, 2021
 *  Author: Karim
 */

#include"adc.h"
#include"lcd.h"
#include"gpio.h"
#include"timer0.h"
#include"lm35.h"
#include"motor.h"
int main()
{
	ADC_ConfigType ADC_Config = {INTERNAL_AREF, F_CPU_8}; /*set ADC configuration */
	ADC_init( &ADC_Config ); /* Intialize ADC Module */
	LCD_init();              /* Intialize LCD Module */
	DcMotor_init();          /* Intialize DC Motor Module */
	LCD_displayString("FAN is "); /* LCD display function */
	LCD_moveCursor(1,0);   /* Move cursor to the second line */
	LCD_displayString("Temp=      C"); /* LCD display function */
	uint8 Temp = 0;
	while(1)
	{
		Temp =  LM35_GetTemperature();  /* save the LM35 sensor value in Temp variable */
		if( Temp < 30 ) /* check if the temperature less than 30 */
				{
					DcMotor_Rotate( STOP, 0 );  /* the motor is stopped */
				}
		else if( Temp >= 30 && Temp < 60 )  /* check if the temperature greater than 30 and less than 60 */
				{
					DcMotor_Rotate( CW, 25 ); /* rotate the motor clockwise direction with duty cycle 25% */
				}
		else if( Temp  >= 60 && Temp < 90) /* check if the temperature greater than 60 and less than 90 */
				{
					DcMotor_Rotate( CW, 50 ); /* rotate the motor clockwise direction with duty cycle 50% */
				}
		else if( Temp  >= 90 && Temp < 120)/* check if the temperature greater than 90 and less than 120 */
				{
					DcMotor_Rotate( CW, 75 ); /* rotate the motor clockwise direction with duty cycle 75% */
				}
		else if( Temp  >= 120 )  /* check if the temperature greater than 120 */
				{
					DcMotor_Rotate( CW, 100 ); /* rotate the motor clockwise direction with duty cycle 100% */
				}
		LCD_moveCursor(0,7);
			if( Temp < 30 ) /* check if the temperature less than 30 */
				{
				LCD_displayString("off"); /* display on the lcd the fan is off */
				}
			else
				{
				LCD_displayString("on");  /* display on the lcd the fan is on */
				/* In case the digital value is three or two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
				}
			LCD_moveCursor(1,7);
			if( Temp >= 100 ) /* check if the temperature greater than 30 */
				{
				LCD_integerToString( Temp ); /* display on the lcd the temperature value */
				}
			else
				{
				LCD_integerToString( Temp ); /* display on the lcd the temperature value */
				/* In case the digital value is three or two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
				}
	}
}


