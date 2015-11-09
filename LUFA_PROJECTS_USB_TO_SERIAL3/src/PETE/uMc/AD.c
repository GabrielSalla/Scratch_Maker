/*
 * AD.c
 *
 * Created: 01/02/2015 19:08:01
 *  Author: pacheco
 */ 

#include "AD.h"

// -------- Funcoes --------- //


uint16_t readAD(uint8_t channel){
	if(channel<8){
		ADMUX = (0xf0 & ADMUX) | channel;
		ADCSRA |= (1 << ADSC);
		loop_until_bit_is_clear(ADCSRA, ADSC);
		return(ADC);
	}
	else{
		channel -= 8;
		PORTC = (0xf0 & PORTC) | channel;
		ADMUX = (0xf0 & ADMUX) | ad_mux;
		ADCSRA |= (1 << ADSC);						/* inicia conversão ADC */
		loop_until_bit_is_clear(ADCSRA, ADSC);		/* espera terminar */
		return(ADC);
	}
}


uint16_t readADSleep(uint8_t channel){
	if(channel<8){
		ADMUX = (0xf0 & ADMUX) | channel;
		ADCSRA |= (1 << ADSC);
		sleep_mode();
		return(ADC);
	}
	else{
		channel -= 8;
		PORTC = (0xf0 & PORTC) | channel;
		ADMUX = (0xf0 & ADMUX) | ad_mux;
		ADCSRA |= (1 << ADSC);					/* inicia conversão ADC */
		sleep_mode();
		return(ADC);
	}	
}

inline void inicia_Mux(){
	DDRC |= ((1 << PC0) |(1 << PC1) |(1 << PC2) |(1 << PC3) );
}

inline void inicia_AD(void){
	inicia_Mux();
	
	// Todas ADS como entrada
	//DDRF &= 0x00;
	
	ADMUX |= (1 << REFS0);										/* coloca a voltage referencia em AVCC */
	ADCSRA |= ((1 << ADPS2) | (1 << ADPS0));		/* ADC clock prescaler /64 */
	ADCSRA |= (1 << ADEN);										/* habilita ADC */
}

void setupADCSleepmode(){
	set_sleep_mode(SLEEP_MODE_ADC);
	ADCSRA |= (1 << ADIE);
	sei();
	
}

EMPTY_INTERRUPT(ADC_vect);

uint16_t oversample12x(uint8_t channel){
	uint16_t oversample=0;
	uint8_t i;
	ADMUX = (0xf0 & ADMUX) | channel;
	ADCSRA |= (1 << ADSC);
	for(i=0; i<12; i++){
		sleep_mode(); 
		oversample += ADC;
		
	}
	return(oversample >> 1);
}

uint16_t leiuraMedia(uint8_t channel){
	uint16_t oversample=0;

	if(channel>7){
		channel -= 8;
		PORTC = (0xf0 & PORTC) | channel;
		ADMUX = (0xf0 & ADMUX) | ad_mux;
	}
	else ADMUX = (0xf0 & ADMUX) | channel;
	ADCSRA |= (1 << ADSC);
	for(uint8_t i=0; i<numeroDeLeituraMedia; i++){
		loop_until_bit_is_clear(ADCSRA, ADSC);		/* espera terminar */
		oversample += ADC;
	}
	return(oversample >> deslocamentoParaMediaLeituras);
}

uint16_t leiuraMediaSleep(uint8_t channel){
	uint16_t oversample=0;

	if(channel>7){
		channel -= 8;
		PORTC = (0xf0 & PORTC) | channel;
		ADMUX = (0xf0 & ADMUX) | ad_mux;
	}
	else ADMUX = (0xf0 & ADMUX) | channel;
	ADCSRA |= (1 << ADSC);
	for(uint8_t i=0; i<numeroDeLeituraMedia; i++){
		sleep_mode();
		oversample += ADC;
	}
	return(oversample >> deslocamentoParaMediaLeituras);
}

