/*
 * divercos.c
 *
 * Created: 02/03/2015 19:18:16
 *  Author: pacheco
 */ 

#include "divercosLEGAL.h"


//--------------------------------------------------------------------------
// Funcao que classifica os IDs lidos em valores válido para o LEGAL

// Converte os Ids dos sensores/atuadores das entradas S
int16_t converteIdSEntradasS (int16_t valorLido)
{
	if (valorLido<LimiteIDLivre)		return IDLivre;
	if (valorLido<LimiteIDCor)			return IDCor;
	if (valorLido<LimiteIDLuz)			return IDLuz;
	if (valorLido<LimiteIDSom)			return IDSom;
	if (valorLido<LimiteIDTemperatura)	return IDTemperatura;
	if (valorLido<LimiteIDResistencia)	return IDResistencia;
	if (valorLido<LimiteIDTensao)		return IDTensao;
	if (valorLido<LimiteIDAnalogico)	return IDAnalogico;
	if (valorLido<LimiteIDDigital)		return IDAtDigital;
	if (valorLido<LimiteIDAtLed)		return IDAtLed;
	if (valorLido<LimiteIDDigital)		return IDDigital;
	if (valorLido<LimiteIDProximidade)	return IDProximidade;
	if (valorLido<LimiteIDFaixa)		return IDFaixa;
	if (valorLido<LimiteIDContado)		return IDContado;
	return 0;
}


// Converte os Ids dos servos
int16_t converteIdServos (int16_t valorLido)
{
	if (valorLido<5)   return IDLivre;
	if (valorLido<34)  return IDAtServoA;
	if (valorLido<69)  return IDAtServoB;
	if (valorLido<105) return IDAtServoC;
	return IDAtServoD;
}

// Converte os Ids dos servos
int16_t converteIdMotores (int16_t valorLido)
{
	if (valorLido<900)  return IDLivre;
	return IDAtMotor;

}




/*

Case Else : Id_porta(u) = 0
End Select

Elseif U > 8 And U <= 12 Then

Select Case Registrador(u + Reg_s8_2)              'Inicia a leitura apartir do servo1
Case 60 To 400 : Id_porta(u) = 100              'Serco A                *

Case Else : Id_porta(u) = 0
End Select

Else

Select Case Registrador(u + Reg_s8_2)              'Inicia a leitura apartir do motor

Case 960 To 1023 : Id_porta(u) = 128            'Motor                   *
Case Else : Id_porta(u) = 0

*/