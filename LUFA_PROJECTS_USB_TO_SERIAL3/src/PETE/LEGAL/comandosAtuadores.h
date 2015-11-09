/*
 * comandosAtuadores.h
 *
 * Created: 29/03/2015 15:16:43
 *  Author: pacheco
 */ 


#ifndef COMANDOSATUADORES_H_
#define COMANDOSATUADORES_H_

#include <util/delay.h>

#include "PETE/LEGAL/configuracaoLEGAL.h"
#include "PETE/uMc/motoresDC.h"

void ligarSaida(int8_t saida);
void desligarSaida(int8_t saida);
void acendeLed(int8_t l);
void apagaLed(int8_t l);
void frente(int8_t tempo);


#endif /* COMANDOSATUADORES_H_ */