 /*
 * divercosLEGAL.h
 *
 * Created: 02/03/2015 16:04:02
 *  Author: pacheco
 */ 


#ifndef DIVERCOSLEGAL_H_
#define DIVERCOSLEGAL_H_
	
	#include <util/delay.h>
		
	#include "PETE/uMc/digitalIO.h"
	#include "PETE/LEGAL/definicoesLEGAL.h"
	
	// Definicoes
	#define tensaoMinima 30
	
	//  Status do modo controlar/executar
	#define MODO_CONECTADO 0
	#define MODO_EXECUTAR 1
	
	// Som e efeitos sonoros do uMC
	#define somClick  239
	
	/* Macros */
	#define aviso \
			L2_off(); \
			_delay_ms(300);
			
    #define testaBateria()  \
	 if(registradores[bateriaValor]<tensaoMinima) { aviso }
		 
	// Variáveis
	
	
			
	//Funcoes 
	int16_t converteIdSEntradasS (int16_t valorLido);
	int16_t converteIdServos (int16_t valorLido);
	int16_t converteIdMotores (int16_t valorLido);


#endif /* DIVERCOSLEGAL_H_ */