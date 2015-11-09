/*
 * motoresDC.h
 *
 * Created: 14/02/2015 01:46:32
 * Author: pacheco
 */ 


#ifndef MOTORESDC_H_
#define MOTORESDC_H_

 #include <avr/io.h>
 
 #define pulsoMax 176
 #define pulsoMed 88
 #define pulsoMin 1
 

 /***********************************/
 /* Pinos de controle dos motores. */
 /* */
 
 #define SPEED_STEP_DELAY 2 /* milliseconds */
 
 /** Mascara para o controle do MD1. */
 #define md1 (1 << PD7)
 #define ddrmd1 DDRD
 #define portmd1 PORTD
 #define md1_saida (ddrmd1 |= md1)
 #define md1_set (portmd1 |= md1 )
 #define md1_reset (portmd1 &= ~md1)

 /** Mascara para o controle do MD2. */
 #define md2 (1 << PC4)
 #define ddrmd2 DDRC
 #define portmd2 PORTC
 #define md2_saida (ddrmd2 |= md2)
 #define md2_set (portmd2 |= md2 )
 #define md2_reset (portmd2 &= ~md2)
 
 /** Mascara para o controle do PWM Direito (OC 3B). */
 #define pwmd (1 << PC5)
 #define ddrpwmd DDRC
 #define portpwmd PORTC
 #define pwmd_saida (ddrpwmd |= pwmd)
 #define pwmd_set (portpwmd |= pwmd)
 #define pwmd_reset (portpwmd &= ~pwmd) 

 /** Mascara para o controle do ME1. */
 #define me1 (1 << PD6)
 #define ddrme1 DDRD
 #define portme1 PORTD
 #define me1_saida (ddrme1 |= me1)
 #define me1_set (portme1 |= me1 )
 #define me1_reset (portme1 &= ~me1)

 /** Mascara para o controle do ME2. */
 
 #define me2 (1 << PD4)
 #define ddrme2 DDRD
 #define portmex2 PORTD
 #define me2_saida (ddrme2 |= me2)
 #define me2_set (portmex2 |= me2 )
 #define me2_reset (portmex2 &= ~me2)
 
 /** Mascara para o controle do PWM Esquerdo (OC 3A). */
 #define pwme (1 << PC6)
 #define ddrpwme DDRC
 #define portpwme PORTC
 #define pwme_saida (ddrpwme |= pwme)
 #define pwme_set (portpwme |= pwme)
 
 /** Ligar e desligar o drive do motor. */
 #define mtstby (1 << PC7)
 #define ddrmtstby DDRC
 #define portmtstby PORTC
 #define mtstby_saida (ddrmtstby |= mtstby)
 #define mtstby_set (portmtstby |= mtstby)
 #define mtstby_reset (portmtstby &= ~mtstby)
 
 /* MACROS */
 #define md_re md1_set;md2_reset;
 #define me_re me1_set;me2_reset;
 #define md_frente md1_reset;md2_set;
 #define me_frente me1_reset;me2_set; 
 #define md_parado md1_reset;md2_reset;
 #define me_parado me1_reset;me2_reset;
 
 #define md_pulso(pulso) (OCR3A = pulso)
 #define me_pulso(pulso) (OCR3B = pulso)
 
 #define md_velocidade(vel) (OCR3A = ((vel+10) * 17)/10)
 #define me_velocidade(vel) (OCR3B = ((vel+10) * 17)/10)
 

 /* Funcoes */
 void inicia_motoresDC ();


#endif /* MOTORESDC_H_ */