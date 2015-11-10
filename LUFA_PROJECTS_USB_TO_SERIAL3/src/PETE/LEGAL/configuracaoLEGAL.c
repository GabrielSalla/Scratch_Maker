/*
 * configuracaoLEGAL.c
 *
 * Created: 29/03/2015 14:20:50
 *  Author: pacheco
 */ 

#include "configuracaoLEGAL.h"


/*  Configura os pinos digitais da placa como pinos de entrada e habilita o pull-up.  */
void configura_pinos_uMC(){
	DDRA = 0;
	DDRB = 0;
	DDRC = 0;
	DDRD = 0;
	DDRE = 0;
	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	PORTE = 0;
	
	//LEDs
	DDRA |= (LED_L1 | LED_L2 | LED_L3);
	DDRE |= (LED_D3R | LED_D3G);
	LD3R_on();
	
	//Saídas digitais
	DDRB |= (p10 | p11 | p12 | p13);
	//PORTB |= (p10 | p11 | p12 | p13);
	
	//Saídas servo
	DDRB |= (1 << PB5 | 1 << PB6);
	
	//Entradas digitais
	PORTB |= p02;
	PORTD |= p03;
	
	//Motores
	//PWM
	DDRC |= (1 << PC5) | (1 << PC6);
	PORTC |= (1 << PC5) | (1 << PC6);
	//MD1
	DDRD |= (1 << PD5);
	//PORTD |= (1 << PD5);
	//MD2
	DDRA |= (1 << PA3);
	//PORTA |= (1 << PA3);
	//ME1
	DDRE |= (1 << PE4);
	//PORTE |= (1 << PE4);
	//ME2
	DDRE |= (1 << PE3);
	//PORTE |= (1 << PE3);
	
}

void configura_EntrasdasS()
{
	DDRA &= ~(s1 | s2 | s3 | s4);
	//PORTA |= (s1 | s2 | s3 | s4);
}