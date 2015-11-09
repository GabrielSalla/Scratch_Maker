/*
 * servo.h
 *
 * Created: 10/02/2015 13:35:03
 *  Author: pacheco
 */ 


#ifndef SERVO_H_
#define SERVO_H_

	#include <avr/io.h>

	#define PULSE_MIN 1100		/* valores obtidos experimentalmete. */
	#define PULSE_MAX 5100		
	#define PULSE_MID 3200
	
	/** Servo 1. OC 1A */
	#define sv1		(1 << PB5)
	#define ddrsv1		DDRB
	#define portsv1		PORTB
	#define sv1_habilita	(ddrsv1 |= sv1)
	#define sv1_desabilita	(ddrsv1 &= ~sv1)
	
	/** Servo 2. OC 1B  */
	#define sv2		(1 << PB6)
	#define ddrsv2		DDRB
	#define portsv2		PORTB
	#define sv2_habilita	(ddrsv2 |= sv2)
	#define sv2_desabilita	(ddrsv2 &= ~sv2)

	
	/*   Macros    */

	#define sv1_pulso(pos) (OCR1A = pos)
	#define sv2_pulos(pos) (OCR1B = pos)
	
	#define sv1_angulo(grau) (OCR1A = (grau*22)+1100)
	#define sv2_angulo(grau) (OCR1B = (grau*22)+1100)
	
	/*   Funçoes   */
	void inicia_servo(void);

	

#endif /* SERVO_H_ */