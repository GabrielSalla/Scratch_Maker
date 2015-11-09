/*
 * comandosAtuadores.c
 *
 * Created: 29/03/2015 15:17:02
 *  Author: pacheco
 */ 

/*
 *  Conjunto de instruçÕes para controlar os atadores do kit Alpha:
 *		Motores;
 *		som;
 *		cabos de luz;
 *		leds
 */

#include "comandosAtuadores.h"


/*   Liga as saídas S's da placa. */
void ligarSaida(int8_t saida){
	switch (saida){
		case 1:
			s1_saida();
			s1_set();
			break;

		case 2:
			s2_saida();
			s2_set();
			break;

		case 3:
			s3_saida();
			s3_set();
			break;

		case 4:
			s4_saida();
			s4_set();
			break;
	}

}


/*   Desliga as saídas S's da placa. */
void desligarSaida(int8_t saida){
	switch (saida){
		case 1:
		s1_saida();
		s1_reset();
		break;

		case 2:
		s2_saida();
		s2_reset();
		break;

		case 3:
		s3_saida();
		s3_reset();
		break;

		case 4:
		s4_saida();
		s4_reset();
		break;
	}
}

//   Acende os Leds do uMC.
void acendeLed(int8_t l){
	switch (l){
		case 1:
			L1_on();
			break;
			
		case 2:
			L2_on();
			break;
			
		case 3:
			L3_on();
			break;
	}
}

//  Apaga os leds do uMC
void apagaLed(int8_t l){
	switch (l){
		case 1:
		L1_off();
		break;
		
		case 2:
		L2_off();
		break;
		
		case 3:
		L3_off();
		break;
	}
}


void frente(int8_t tempo){
	md_frente;
	me_frente;
	for (int8_t i = 0; i < tempo; i++)
		_delay_ms(10);
	md_parado;
	me_parado;
}