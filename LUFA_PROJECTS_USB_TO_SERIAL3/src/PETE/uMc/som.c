/*
 * som.c
 *
 * Created: 01/02/2015 22:38:34
 *  Author: pacheco
 */ 

#include "som.h"


void inicia_Timer(void) {
	//Inicia timer 0 para período de 1ms
	TCCR0A = 1 << WGM01;
	TCCR0B = (1 << CS01) | (1 << CS00);
	OCR0A = 249;
	TIMSK0 = 1 << OCIE0A;
	
	//Inicia timer 2 para o som de início
	TCCR2A |= (1 << COM2A0) | (1 << WGM21);
	TCCR2B |= (1 << FOC2A) | (1 << CS21) | (1 << CS22);
	
	//Toca som de início
	som();
	
	//Inicia timer para saídas analógicas
	TCCR2A = 1 << WGM21;
	TCCR2B = (1 << CS01) | (1 << CS00);
	OCR2A = 10;
	TIMSK2 = 1 << OCIE2A;	
}

void som(void){
	float i = 200;
	uint8_t tempo = 80;
	
	L1_on();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);
	i = i * 1.5;

	L2_on();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);
	i = i * 1.5;

	L3_on();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);
	i = i * 1.5;

	L1_off();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);
	i = i * 1.5;

	L2_off();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);
	i = i * 1.5;

	L3_off();
	playNote((uint8_t)i, tempo);
	i = i / 2;
	playNote((uint8_t)i, tempo);

	TCCR0A = 0;
	TCCR2B = 0;
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
