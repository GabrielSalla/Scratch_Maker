/*
 * som.h
 *
 * Created: 01/02/2015 22:38:58
 *  Author: pacheco
 */ 


#ifndef SOM_H_
#define SOM_H_
	
	#include <avr/io.h>
	#include <util/delay.h>
	
	#include "escala8.h"
	#include "IO.h"
	
	
	#define buzzer                 PB4                            /* OC0A */
	#define buzzer_PORT            PORTB
	#define buzzer_PIN             PINB
	#define buzzer_DDR             DDRB

	
/*   Funcoes   */
void inicia_Timer(void);
void som(void);
void playNote(uint8_t wavelength, uint16_t duration);


#endif /* SOM_H_ */