/*
 * motoresDC.h
 *
 * Created: 14/02/2015 01:46:32
 * Author: pacheco
 */ 


#ifndef MOTORESDC_H_
#define MOTORESDC_H_

#include <avr/io.h>

#define me1 (1 << PE4)
#define me1_set (PORTE |= me1)
#define me1_reset (PORTE &= ~me1)
 
#define me2 (1 << PE3)
#define me2_set (PORTE |= me2)
#define me2_reset (PORTE &= ~me2)
 
#define md1 (1 << PD5)
#define md1_set (PORTD |= md1)
#define md1_reset (PORTD &= ~md1)
 
#define md2 (1 << PA3)
#define md2_set (PORTA |= md2)
#define md2_reset (PORTA &= ~md2)
 
 
#define me_re me1_set;me2_reset;
#define md_re md1_reset;md2_set;
#define me_frente me1_reset;me2_set;
#define md_frente md1_set;md2_reset;
#define md_parado md1_reset;md2_reset;
#define me_parado me1_reset;me2_reset;



void inicia_motoresDC ();


#endif /* MOTORESDC_H_ */