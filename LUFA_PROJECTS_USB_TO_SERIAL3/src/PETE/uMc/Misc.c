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

/*  Esta rotina deve ser chamada ao termino de execução de um programa em LEGAL,
 *  Ela é responsável por retornar a configuração das I/Os para os valores padrão. */
void reInicia_uMC(){
	inicia_USART();
	inicia_AD();
	inicia_Timer();
	//configura_pinos_uMC();
	//configura_EntrasdasS();
}

