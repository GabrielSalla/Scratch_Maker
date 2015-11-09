/*
 * maqVirtual.h
 *
 * Created: 20/03/2015 11:53:59
 *  Author: pacheco
 */ 


#ifndef MAQVIRTUAL_H_
#define MAQVIRTUAL_H_

#include "PETE/uMc/AD.h"
#include "PETE/LEGAL/definicoesLEGAL.h"
#include "PETE/LEGAL/divercosLEGAL.h"
#include "PETE/uMc/digitalIO.h"


//----------------------------------------

uint16_t registradores[Maxregistradores];

//----------------------------------------
	
#define LimiteDigital	512	   // valor minino para uma leitura ser considera 1 digital
	
//---------------------------------------
//  MACROS
#define le_botaoENTER() registradores[btEnterValor]	= bt1_isPress()


//----------------------------------------
//   FUNÇÕES
void lerEntradasuMC(void);
void trataID(void);
void trataSensoresDigitais(void);

#endif /* MAQVIRTUAL_H_ */