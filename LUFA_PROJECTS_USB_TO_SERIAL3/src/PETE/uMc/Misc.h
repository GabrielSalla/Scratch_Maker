/*
 * Misc.h
 *
 * Created: 19/01/2015 16:33:18
 *  Author: pacheco
 */ 


#ifndef MISC_H_
#define MISC_H_

	#include <avr/io.h>
	//#include "digitalIO.h"
	
	#include "IO.h"
	#include "configuracaoLEGAL.h"
	
	#include "AD.h"
	#include "som.h"
	#include "definicoes.h"
	#include "USART.h"
	//#include "motoresDC.h"
	#include "servo.h"
	


	/* Prototipos */
	void inicia_uMC(void);
	void reInicia_uMC(void);

#endif /* MISC_H_ */