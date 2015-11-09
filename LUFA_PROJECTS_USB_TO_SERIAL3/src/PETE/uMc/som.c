/*
 * som.c
 *
 * Created: 01/02/2015 22:38:34
 *  Author: pacheco
 */ 

#include "som.h"

void inicia_Timer(void) {
	TCCR0A = 1 << WGM01;
	TCCR0B = (1 << CS01) | (1 << CS00);
	OCR0A = 249;
	TIMSK0 = 1 << OCIE0A;
	
	TCCR2A |= (1 << WGM21);                                  /* CTC mode */
	TCCR2A |= (1 << COM2A0);								 /* inverte o pino a cada ciclo */
	TCCR2B |= (1 << CS21) | (1 << CS22);					 /* CPU clock / 256 */
}

void playNote(uint8_t wavelength, uint16_t duration) {
	
	OCR2A = wavelength;									/* seta nota */
	buzzer_DDR |= (1 << buzzer);						/* habilita a saida do Buzzer */
	
	
	while (duration) {                                  /* duracao do som */
		_delay_ms(1);
		duration--;
	}	
	buzzer_DDR &= ~(1 << buzzer);                     /* desliga Buzzer */
}
