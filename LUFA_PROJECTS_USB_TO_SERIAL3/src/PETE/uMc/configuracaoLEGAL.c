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
	
	//Buzzer
	BUZZER_output();
	
	//LEDs
	L1_output();
	L2_output();
	L3_output();
	LD3R_output();
	LD3G_output();
	LD3R_on();
	
	//Saídas analógicas
	P05_output();
	P06_output();
	P09_output();
	
	//Saídas digitais
	P10_output();
	P11_output();
	P12_output();
	P13_output();
	
	//Saídas servo
	SV1_output();
	SV2_output();
	
	//Entradas digitais
	P02_input();
	P02_setup();
	P03_input();
	P03_setup();
	
	//Motores e servos
	PWM_output();
	PWM_on();
	MD1_output();
	MD2_output();
	ME1_output();
	ME2_output();
}

/*void configura_EntrasdasS()
{
	DDRA &= ~(s1 | s2 | s3 | s4);
	//PORTA |= (s1 | s2 | s3 | s4);
}*/