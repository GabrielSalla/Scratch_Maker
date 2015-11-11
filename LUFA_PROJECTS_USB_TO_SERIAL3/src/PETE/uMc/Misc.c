/*
 * Misc.c
 *
 * Created: 19/01/2015 16:32:49
 *  Author: pacheco
 */ 

#include "Misc.h"

void inicia_uMC(){
	configura_pinos_uMC();
	//inicia_LEDS();
	//inicia_Botoes();
	inicia_USART();
	inicia_AD();
	inicia_Timer();
	inicia_motoresDC();
	inicia_servo();
	//configura_EntrasdasS();
}

/*  Esta rotina deve ser chamada ao termino de execu��o de um programa em LEGAL,
 *  Ela � respons�vel por retornar a configura��o das I/Os para os valores padr�o. */
void reInicia_uMC(){
	inicia_USART();
	inicia_AD();
	inicia_Timer();
	//configura_pinos_uMC();
	//configura_EntrasdasS();
}

