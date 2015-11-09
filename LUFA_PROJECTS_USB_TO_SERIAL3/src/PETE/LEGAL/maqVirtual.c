/*
 * maqVirtual.c
 *
 * Created: 20/03/2015 11:53:37
 *  Author: pacheco
 */ 

#include "maqVirtual.h"

void leiturasAD_ALPHA(){
	uint16_t soma=0;
	
	registradores[bateriaValor] = leiuraMediaSleep(ad_bat);
	
	// Leituras com o Multiplexador
	
	//Configura MUX
	ADMUX = (0xf0 & ADMUX) | ad_mux;

	for(int8_t porta=0; porta<nrPortasNoMux; porta++){
		PORTC = (0xf0 & PORTC) | porta;
		ADCSRA |= (1 << ADSC);
		for(uint8_t i=0; i<numeroDeLeituraMedia; i++){
			sleep_mode();
			soma += ADC;
		}
		registradores[porta] =  soma >> deslocamentoParaMediaLeituras;
		soma=0;
	}
}


// Converte o valor dos IDs lidos diretamnete dos AD's pelos valores correspondente a cada sensor/atuador
void trataID(){
	registradores[s1ID] = converteIdSEntradasS(registradores[s1ID]);
	registradores[s2ID] = converteIdSEntradasS(registradores[s2ID]);
	registradores[s3ID] = converteIdSEntradasS(registradores[s3ID]);
	registradores[s4ID] = converteIdSEntradasS(registradores[s4ID]);

	registradores[servo1ID] = converteIdServos(registradores[servo1ID]);
	registradores[servo2ID] = converteIdServos(registradores[servo2ID]);

	registradores[meID] = converteIdMotores(registradores[meID]);
	registradores[mdID] = converteIdMotores(registradores[mdID]);
}

// Converte os valores das leituras AD para os sensores digitais.
void trataSensoresDigitais(){
	if(registradores[s1ID]< 0){
		if(registradores[s1Valor]< LimiteDigital)
			registradores[s1Valor] = 0;
		else
			registradores[s1Valor] = 1;
	}
	  
	if(registradores[s2ID]< 0){
		if(registradores[s2Valor]< LimiteDigital)
			registradores[s2Valor] = 0;
		else
			registradores[s2Valor] = 1;
	}
	
	if(registradores[s3ID]< 0){
		if(registradores[s3Valor]< LimiteDigital)
			registradores[s3Valor] = 0;
		else
			registradores[s3Valor] = 1;
	}
	  
	if(registradores[s4ID]< 0){
		if(registradores[s4Valor]< LimiteDigital)
			registradores[s4Valor] = 0;
		else
			registradores[s4Valor] = 1;
	}
}


void leituraAD_Ardunio(){
	for(int8_t i=ad0Valor; i<btEnterValor; i++)
		registradores[i]= leiuraMediaSleep(i-ad0Valor);
}

void leituraDigital_Arduino(){
	//registradores[p00Valor] = is_p00_set();
	//registradores[p01Valor] = is_p01_set();
	registradores[p02Valor] = is_p02_set();
	registradores[p03Valor] = is_p03_set();
	/*registradores[p04Valor] = is_p04_set();
	registradores[p05Valor] = is_p05_set();
	registradores[p06Valor] = is_p06_set();
	registradores[p07Valor] = is_p07_set();
	registradores[p08Valor] = is_p08_set();
	registradores[p09Valor] = is_p09_set();
	registradores[p10Valor] = is_p10_set();
	registradores[p11Valor] = is_p11_set();
	registradores[p12Valor] = is_p12_set();
	registradores[p13Valor] = is_p13_set();*/
}

void lerEntradasuMC(){
	//leiturasAD_ALPHA();
	//le_botaoENTER();
	leituraAD_Ardunio();
	leituraDigital_Arduino();
}