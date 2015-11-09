/*
 * digitalIO.c
 *
 * Created: 01/02/2015 20:16:43
 *  Author: pacheco
 */ 

#include "digitalIO.h"

/*  Inicia os Leds da placa */
void inicia_LEDS(){
	DDRA |= (LED_L1 | LED_L2 | LED_L3);
	DDRE |= (LED_D3R | LED_D3G);
	
	L1_off();
	L1_off();
	L2_off();
	L2_off();
}

/*  Inicia os Botoes da placa */
void inicia_Botoes()
{
	DDRE &= ~(bt1 | bt2);
	PORTE |= (bt1 | bt2);
}

