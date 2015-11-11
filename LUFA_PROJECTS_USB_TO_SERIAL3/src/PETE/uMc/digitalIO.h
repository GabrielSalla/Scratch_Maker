/*
 * definicoes.h
 *
 * Created: 19/01/2015 11:37:29
 *  Author: pacheco
 */ 


#ifndef DIGITAOIO_H_
#define DIGITAOIO_H_

	#include <avr/io.h>
	/* Macros e Mascaras */
	
	/***********************************/
	/*  LEDS						   */
	/*								   */
	
	
			
	/***********************************/
	/*  Botões   					   */
	/*								   */
	/** Mascara para o Botao 1. */
	#define bt1 (1 << PE2) 
	#define bt1_isPress() (!(PINE & bt1))
	#define bt1_waitPress() while(!bt1_isPress())
	#define bt1_waitRelease() while(bt1_isPress()) 
		
	/** Mascara para o Botao 1. */
	#define bt2	(1 << PE5) 
	#define bt2_isPress() (!(PINE & bt2))
	#define bt2_waitPress() while(!bt2_isPress()) 
	#define bt2_waitRelease() while(bt2_isPress()) 

	/***********************************/
	/*  Pinos Arduino				   */
	/*								   */
	/** Mascara para o Pin00.		   */
	#define p00			(1 << PD2)
	#define ddr00		DDRD
	#define port00		PORTD
	#define pin00		PIND
	#define p00_pullup  (port00 |= p00)
	#define p00_saida	(ddr00 |= p00)
	#define p00_entrada	(ddr00 &= ~p00)
	#define p00_set     (port00 |= p00)
	#define p00_reset   (port00 &= ~p00)
	
	#define is_p00_set()	(pin00 & p00)
	
	/** Mascara para o Pin01.		   */
	#define p01			(1 << PD3)
	#define ddr01		DDRD
	#define port01		PORTD
	#define pin01		PIND
	#define p01_pullup  (port01 |= p01)
	#define p01_saida	(ddr01 |= p01)
	#define p01_entrada	(ddr01 &= ~p01)
	#define p01_set     (port01 |= p01)
	#define p01_reset   (port01 &= ~p01)
	
	#define is_p01_set()	(pin01 & p01)
	
	/** Mascara para o Pin02.		   */
	#define p02			(1 << PE6)
	#define ddr02		DDRE
	#define port02		PORTE
	#define pin02		PINE
	#define p02_pullup  (port02 |= p02)
	#define p02_saida	(ddr02 |= p02)
	#define p02_entrada	(ddr02 &= ~p02)
	#define p02_set     (port02 |= p02 )
	#define p02_reset   (port02 &= ~p02)
	
	#define is_p02_set()	(pin02 & p02)
	
	/** Mascara para o Pin03.		   */
	#define p03			(1 << PD7)
	#define ddr03		DDRD
	#define port03		PORTD
	#define pin03		PIND
	#define p03_pullup  (port03 |= p03)
	#define p03_saida	(ddr03 |= p03)
	#define p03_entrada	(ddr03 &= ~p03)
	#define p03_set     (port03 |= p03)
	#define p03_reset   (port03 &= ~p03)
	
	#define is_p03_set()	(pin03 & p03)
	
	/** Mascara para o Pin04.		   */
	#define p04			(1 << PD6)
	#define ddr04		DDRD
	#define port04		PORTD
	#define pin04		PIND
	#define p04_pullup  (port04 |= p04)
	#define p04_saida	(ddr04 |= p04)
	#define p04_entrada	(ddr04 &= ~p04)
	#define p04_set     (port04 |= p04)
	#define p04_reset   (port04 &= ~p04)
	
	#define is_p04_set()	(pin04 & p04)
	
	/** Mascara para o Pin05.		   */
	#define p05			(1 << PC7)
	#define ddr05		DDRC
	#define port05		PORTC
	#define pin05		PINC
	#define p05_pullup  (port05 |= p05)
	#define p05_saida	(ddr05 |= p05)
	#define p05_entrada	(ddr05 &= ~p05)
	#define p05_set     (port05 |= p05)
	#define p05_reset   (port05 &= ~p05)
	
	#define is_p05_set()	(pin05 & p05)
	
	/** Mascara para o Pin06.		   */
	#define p06			(1 << PB7)
	#define ddr06		DDRB
	#define port06		PORTB
	#define pin06		PINB
	#define p06_pullup  (port06 |= p06)
	#define p06_saida	(ddr06 |= p06)
	#define p06_entrada	(ddr06 &= ~p06)
	#define p06_set     (port06 |= p06)
	#define p06_reset   (port06 &= ~p06)
	
	#define is_p06_set()	(pin06 & p06)
	
	/** Mascara para o Pin07.		   */
	#define p07			(1 << PE7)
	#define ddr07		DDRE
	#define port07		PORTE
	#define pin07		PINE
	#define p07_pullup  (port07 |= p07)
	#define p07_saida	(ddr07 |= p07)
	#define p07_entrada	(ddr07 &= ~p07)
	#define p07_set     (port07 |= p07)
	#define p07_reset   (port07 &= ~p07)
	
	#define is_p07_set()	(pin07 & p07)	
		
	/** Mascara para o Pin08.		   */
	#define p08			(1 << PD4)
	#define ddr08		DDRD
	#define port08		PORTD
	#define pin08		PIND
	#define p08_pullup  (port08 |= p08)
	#define p08_saida	(ddr08 |= p08)
	#define p08_entrada	(ddr08 &= ~p08)
	#define p08_set     (port08 |= p08)
	#define p08_reset   (port08 &= ~p08)
	
	#define is_p08_set()	(pin08 & p08)
		
	/** Mascara para o Pin09.		   */
	#define p09			(1 << PC4)
	#define ddr09		DDRC
	#define port09		PORTC
	#define pin09		PINC
	#define p09_pullup  (port09 |= p09)
	#define p09_saida	(ddr09 |= p09)
	#define p09_entrada	(ddr09 &= ~p09)
	#define p09_set     (port09 |= p09)
	#define p09_reset   (port09 &= ~p09)
	
	#define is_p09_set()	(pin09 & p09)
	
	/** Mascara para o Pin10.		   */
	#define p10			(1 << PB0)
	#define ddr10		DDRB
	#define port10		PORTB
	#define pin10		PINB
	#define p10_pullup  (port10 |= p10)
	#define p10_saida	(ddr10 |= p10)
	#define p10_entrada	(ddr10 &= ~p10)
	#define p10_set     (port10 |= p10)
	#define p10_reset   (port10 &= ~p10)
	
	#define is_p10_set()	(pin10 & p10)	
	
	/** Mascara para o Pin11.		   */
	#define p11			(1 << PB2)
	#define ddr11		DDRB
	#define port11		PORTB
	#define pin11		PINB
	#define p11_pullup  (port11 |= p11)
	#define p11_saida	(ddr11 |= p11)
	#define p11_entrada	(ddr11 &= ~p11)
	#define p11_set     (port11 |= p11)
	#define p11_reset   (port11 &= ~p11)
	
	#define is_p11_set()	(pin11 & p11)	
	
	/** Mascara para o Pin12.		   */
	#define p12			(1 << PB3)
	#define ddr12		DDRB
	#define port12		PORTB
	#define pin12		PINB
	#define p12_pullup  (port12 |= p12)
	#define p12_saida	(ddr12 |= p12)
	#define p12_entrada	(ddr12 &= ~p12)
	#define p12_set     (port12 |= p12)
	#define p12_reset   (port12 &= ~p12)
	
	#define is_p12_set()	(pin12 & p12)	

	/** Mascara para o Pin13.		   */
	#define p13			(1 << PB1)
	#define ddr13		DDRB
	#define port13		PORTB
	#define pin13		PINB
	#define p13_pullup  (port13 |= p13)
	#define p13_saida	(ddr13 |= p13)
	#define p13_entrada	(ddr13 &= ~p13)
	#define p13_set     (port13 |= p13)
	#define p13_reset   (port13 &= ~p13)
	
	#define is_p13_set()	(pin13 & p13)	
	
	/** Mascara para o A0.		   */
	#define a0			(1 << PF0)
	#define ddra0		DDRF
	#define porta0		PORTF
	#define pina0		PINF
	#define a0_pullup  (porta0 |= a0)
	#define a0_saida	(ddra0 |= a0)
	#define a0_entrada	(ddra0 &= ~a0)
	#define a0_set     (porta0 |= a0)
	#define a0_reset   (porta0 &= ~a0)
	
	#define is_a0_set	(pina0 & a0)	
		
	/** Mascara para o A1.		   */
	#define a1			(1 << PF1)
	#define ddra1		DDRF
	#define porta1		PORTF
	#define pina1		PINF
	#define a1_pullup  (porta1 |= a1)
	#define a1_saida	(ddra1 |= a1)
	#define a1_entrada	(ddra1 &= ~a1)
	#define a1_set     (porta1 |= a1)
	#define a1_reset   (porta1 &= ~a1)
	
	#define is_a1_set	(pina1 & a1)	
	
	/** Mascara para o A2.		   */
	#define a2			(1 << PF2)
	#define ddra2		DDRF
	#define porta2		PORTF
	#define pina2		PINF
	#define a2_pullup  (porta2 |= a2)
	#define a2_saida	(ddra2 |= a2)
	#define a2_entrada	(ddra2 &= ~a2)
	#define a2_set     (porta2 |= a2)
	#define a2_reset   (porta2 &= ~a2)
	
	#define is_a2_set	(pina2 & a2)	
	
	/** Mascara para o A3.		   */
	#define a3			(1 << PF3)
	#define ddra3		DDRF
	#define porta3		PORTF
	#define pina3		PINF
	#define a3_pullup  (porta3 |= a3)
	#define a3_saida	(ddra3 |= a3)
	#define a3_entrada	(ddra3 &= ~a3)
	#define a3_set     (porta3 |= a3)
	#define a3_reset   (porta3 &= ~a3)
	
	#define is_a3_set	(pina3 & a3)
	
	/** Mascara para o A4.		   */
	#define a4			(1 << PF4)
	#define ddra4		DDRF
	#define porta4		PORTF
	#define pina4		PINF
	#define a4_pullup  (porta4 |= a4)
	#define a4_saida	(ddra4 |= a4)
	#define a4_entrada	(ddra4 &= ~a4)
	#define a4_set     (porta4 |= a4)
	#define a4_reset   (porta4 &= ~a4)
	
	#define is_a4_set	(pina4 & a4)	
	
	/** Mascara para o A5.		   */
	#define a5			(1 << PF5)
	#define ddra5		DDRF
	#define porta5		PORTF
	#define pina5		PINF
	#define a5_pullup  (porta5 |= a5)
	#define a5_saida	(ddra5 |= a5)
	#define a5_entrada	(ddra5 &= ~a5)
	#define a5_set     (porta5 |= a5)
	#define a5_reset   (porta5 &= ~a5)
	
	#define is_a5_set	(pina5 & a5)	
	
	/***********************************/
	/*  Saídas S do uMc				   */
	/*								   */
	/** Mascara para as saidas do uMC  */
		
	/** Mascara para porta S1.		   */
	/*  Contato 2 da uSB (Dados)	   */	
	#define s1				(1 << PA3)
	#define ddrs1			DDRA
	#define ports1			PORTA
	#define pins1			PINA
	#define s1_pullup()		(ports1 |= s1)
	#define s1_saida()		(ddrs1 |= s1)
	#define s1_entrada()	(ddrs1 &= ~s1)
	#define s1_set()		(ports1 |= s1 )
	#define s1_reset()		(ports1 &= ~s1)
	
	#define is_s1_set()		(pins1 & s1)
	
	/** Mascara para porta S2.		   */
	/*  Contato 2 da uSB (Dados)	   */	
	#define s2				(1 << PA1)
	#define ddrs2			DDRA
	#define ports2			PORTA
	#define pins2			PINA
	#define s2_pullup()		(ports2 |= s2)
	#define s2_saida()		(ddrs2 |= s2)
	#define s2_entrada()	(ddrs2 &= ~s2)
	#define s2_set()		(ports2 |= s2 )
	#define s2_reset()		(ports2 &= ~s2)
	
	#define is_s2_set()		(pins2 & s2)
	
	/** Mascara para porta S3.		   */
	/*  Contato 2 da uSB (Dados)	   */	
	#define s3				(1 << PA4)
	#define ddrs3			DDRA
	#define ports3			PORTA
	#define pins3			PINA
	#define s3_pullup()		(ports3 |= s3)
	#define s3_saida()		(ddrs3 |= s3)
	#define s3_entrada()	(ddrs3 &= ~s3)
	#define s3_set()		(ports3 |= s3 )
	#define s3_reset()		(ports3 &= ~s3)
	
	#define is_s3_set()		(pins3 & s3)	
	
	/** Mascara para porta S4.		   */
	/*  Contato 2 da uSB (Dados)	   */	
	#define s4				(1 << PA6)
	#define ddrs4			DDRA
	#define ports4			PORTA
	#define pins4			PINA
	#define s4_pullup()		(ports4 |= s4)
	#define s4_saida()		(ddrs4 |= s4)
	#define s4_entrada()	(ddrs4 &= ~s4)
	#define s4_set()		(ports4 |= s4 )
	#define s4_reset()		(ports4 &= ~s4)
	
	#define is_s4_set()		(pins4 & s4)
	
/*    Funcoes  */
	void inicia_LEDS();
	void inicia_Botoes();

#endif /* DEFINICOES_H_ */