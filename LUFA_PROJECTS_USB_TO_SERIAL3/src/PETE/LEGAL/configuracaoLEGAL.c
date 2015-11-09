/*
 * configuracaoLEGAL.c
 *
 * Created: 29/03/2015 14:20:50
 *  Author: pacheco
 */ 

#include "configuracaoLEGAL.h"


/*  Configura os pinos digitais da placa como pinos de entrada e habilita o pull-up.  */
void configura_pinos_uMC()
{
	DDRB &= ~(p03 | p05 | p06 | p10 | p11 | p12 | p13);
	PORTB |= (p03 | p05 | p06 | p10 | p11 | p12 | p13);
	DDRC &= ~(p09);
	PORTC |= (p09);
	DDRD &= ~(p00 | p01 | p04 | p08);
	PORTD |= (p00 | p01 | p04 | p08);
	DDRE &= ~(p02 | p07);
	PORTE |= (p02 | p07);
}

void configura_EntrasdasS()
{
	DDRA &= ~(s1 | s2 | s3 | s4);
	//PORTA |= (s1 | s2 | s3 | s4);
}