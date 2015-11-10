/*
 * servo.c
 *
 * Created: 10/02/2015 13:34:15
 *  Author: pacheco
 */ 

#include "servo.h"


void inicia_servo(void) {
	OCR1A = 1500;
	OCR1B = 1500;
	
	TCCR1A |= (1 << COM1A1 | 1 << COM1B1);
	TCCR1B |= (1 << WGM13 | 1 << CS11);
	ICR1 = 20000;
}



