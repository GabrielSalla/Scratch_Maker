/*
 * AD.h
 *
 * Created: 01/02/2015 19:08:24
 *  Author: pacheco
 */ 


#ifndef AD_H_
#define AD_H_

	#include <avr/io.h>
	#include <util/delay.h>
	#include <avr/sleep.h>
	#include <avr/interrupt.h>

	#define ad_a0		0x00
	#define ad_a1		0x01
	#define ad_a2		0x02
	#define ad_a3		0x03
	#define ad_a4		0x04
	#define ad_a5		0x05
	#define ad_bat		0x06
	#define ad_mux		0x07
	
	#define ad_ids2		0x08
	#define ad_s2		0x09
	#define ad_ids4		0x0A
	#define ad_s4		0x0B	
	#define ad_s1		0x0C
	#define ad_ids1		0x0D
	#define ad_s3		0x0E
	#define ad_ids3		0x0F
	#define ad_idsv1	0x10
	#define ad_idme		0x11
	#define ad_sluz		0x12 
	#define ad_stemp	0x13
	#define ad_idmd		0x14
	#define ad_idsv2	0x15
	
	#define numeroDeLeituraMedia			4	// numero de leituras para calcular o velor medio
	#define deslocamentoParaMediaLeituras	2   // valor so shift (divisao) para o calculo da media
	
	
	/* Funcoes */

	void inicia_AD(void);
	void setupADCSleepmode(void);

	uint16_t readAD(uint8_t channel);
	uint16_t oversample12x(uint8_t channel);
	uint16_t readADSleep(uint8_t channel);
	uint16_t leiuraMedia(uint8_t channel);
	uint16_t leiuraMediaSleep(uint8_t channel);

#endif /* AD_H_ */