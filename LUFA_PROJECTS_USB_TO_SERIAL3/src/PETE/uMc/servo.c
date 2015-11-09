/*
 * servo.c
 *
 * Created: 10/02/2015 13:34:15
 *  Author: pacheco
 */ 

#include "servo.h"


void inicia_servo(void) {
	OCR1A = PULSE_MID;						/* coloca  os servos na posicao central.*/
	OCR1B = PULSE_MID;
	/* Set up Timer1 (16bit) para gerar um pulso a cada 20ms */	
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);	/* Usando Fast PWM, counter max em ICR1 */
	TCCR1B |= (1 << CS11); 					/* /8 prescaling -- counting in microseconds */
	ICR1 = 40000;							/* TOP  = 20ms */
	TCCR1A |= (1 << COM1A1);				/* modo de saida canal A*/
	TCCR1A |= (1 << COM1B1);				/* modo de saida canal B*/
}



