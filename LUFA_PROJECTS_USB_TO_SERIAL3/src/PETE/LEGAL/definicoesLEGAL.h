/*
 * IdefinicoesLEGAL.h
 *
 * Created: 20/03/2015 12:14:34
 *  Author: pacheco
 */ 


#ifndef IDEFINICOESLEGAL_H_
#define IDEFINICOESLEGAL_H_


//-------------------------------------------------------------------------------
// Ientificação

#define Numero_Serie    "00000"
#define Nome_Robo		"SemNome"
#define	Versao_kernel	"1011"
#define	Produto			"MC3.0"
#define	Versao_hw		"v2.3"                                   //Versão do hardware compativel com este programa

//-------------------------------------------------------------------------------
// Limites

#define	Maxregistradores	255									// numero maximo de registradores na Ram
#define Maxmemoria			4044								// Tamanho da memória de programa


#define nrPortasNoMux		14									// quantidade de ADs no mux 

//-------------------------------------------------------------------------------
// Configurações de endereços do Registrador

#define s1Valor			4
#define s1ID			5
#define s2Valor			1
#define s2ID			0
#define s3Valor			6
#define s3ID			7
#define s4Valor			3
#define s4ID			2

#define servo1ID		8
#define meID			9
#define sLuz            10
#define sTemp			11
#define mdID			12
#define servo2ID		13

#define bateriaValor	14

#define ad0Valor		15
#define ad1Valor		16
#define ad2Valor		17
#define ad3Valor		18
#define ad4Valor		19
#define ad5Valor		20

#define btEnterValor	21

#define p00Valor		22
#define p01Valor		23
#define p02Valor		24
#define p03Valor		25
#define p04Valor		26
#define p05Valor		27
#define p06Valor		28
#define p07Valor		29
#define p08Valor		30
#define p09Valor		31
#define p10Valor		32
#define p11Valor		33
#define p12Valor		34
#define p13Valor		35

// Valores dos IDs de sensores e atuadores

#define IDLivre			0
#define	IDCor			2	// Sensor Cor
#define IDLuz			3	// Sensor Luz OK
#define IDSom			4   // Sensor de Ruído        
#define IDTemperatura	5	// Sensor Temperatura
#define IDResistencia	6   // Sensor Resistência
#define IDTensao		7	// Sensor Tensão
#define IDAnalogico		8   // Sensor Analógico Genérico
#define IDDigital		-8	// Sensor Digital Genérico
#define IDFaixa			-7	// Sensor Faixa
#define IDProximidade	-6	// Sensor Proximidade
#define IDContado		-5	// Sensor Contato

#define IDAtDigital		-3	// Atuador digital
#define IDAtLed			-2  // Atuador led
#define IDAtServoA		100	// Servo TSX35 
#define IDAtServoB		100	// Servo PS-4803
#define IDAtServoC		100	// Servo CS-60
#define IDAtServoD		100	// Servo PS-4806
#define IDAtMotor		128	// Motor DC


// Limites para o as leituras dos Sensores
#define LimiteIDLivre			10	// Entrada livre
#define	LimiteIDCor				51	// Sensor Cor
#define LimiteIDLuz				92	// Sensor Luz OK
#define LimiteIDSom				125 // Sensor de Som
#define LimiteIDTemperatura		175	// Sensor Temperatura
#define LimiteIDResistencia		245 // Sensor Resistência
#define LimiteIDTensao			292	// Sensor Tensão
#define LimiteIDAnalogico		332 // Sensor Analógico Genérico

#define LimiteIDDigital			684	// Sensor Digital Genérico
#define LimiteIDProximidade		915 /// Sensor Proximidade  909
#define LimiteIDFaixa			950	// Sensor Faixa 946
#define LimiteIDContado		   1000	// Sensor Contato  994


// Limites para o as leituras dos atuadores
#define LimiteIDAtLed			762	// Sensor Contato


#endif /* IDEFINICOESLEGAL_H_ */