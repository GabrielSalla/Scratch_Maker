/*
 * motoresDc.c
 *
 * Created: 14/02/2015 01:46:58
 *  Author: pacheco
 */ 

#include "motoresDC.h"

void inicia_motoresDC(){
	pwmd_saida;
	md1_saida;
	md2_saida;
	
	pwme_saida;
	me1_saida;
	me2_saida;
	
	md_parado;
	me_parado;
	
	md_pulso(pulsoMed);
	me_pulso(pulsoMed);

	/*   Motor da direita >> Timer 3B */
	/* Set up Timer1 (16bit) para gerar um pulso a cada 20ms */
	TCCR3A |= (1 << WGM31);
	TCCR3B |= (1 << WGM32) | (1 << WGM33);	/* Usando Fast PWM, counter max em ICR1 */
	TCCR3B |= (1 << CS30); 					/* /1 prescaling  */
	ICR3 = 176;							    /* 90 Khz */
	TCCR3A |= (1 << COM3A1);				/* modo de saida canal A*/
	TCCR3A |= (1 << COM3B1);				/* modo de saida canal B*/
	
	
	mtstby_saida;
	mtstby_set;
}