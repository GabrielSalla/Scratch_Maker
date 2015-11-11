/*
 * IO.h
 *
 * Created: 11/11/2015 15:56:16
 *  Author: Gabriel
 */ 


#ifndef IO_H_
#define IO_H_

#include <avr/io.h>

//LED D3R
#define LED_D3R (1 << PE0)
#define LD3R_output() (DDRE |= LED_D3R)
#define LD3R_on() (PORTE |= LED_D3R)
#define LD3R_off() (PORTE &= ~LED_D3R)
#define LD3R_toogle() (PORTE ^= LED_D3R)

//LED D3G
#define LED_D3G (1 << PE1)
#define LD3G_output() (DDRE |= LED_D3G)
#define LD3G_on() (PORTE |= LED_D3G)
#define LD3G_off() (PORTE &= ~LED_D3G)
#define LD3G_toogle() (PORTE ^= LED_D3G)

//LED 1
#define LED_L1 (1 << PA0)
#define L1_output() (DDRA |= LED_L1)
#define L1_on() (PORTA |= LED_L1)
#define L1_off() (PORTA &= ~LED_L1)
#define L1_toogle() (PORTA ^= LED_L1)

//LED 2
#define LED_L2 (1 << PA1)
#define L2_output() (DDRA |= LED_L2)
#define L2_on() (PORTA |= LED_L2)
#define L2_off() (PORTA &= ~LED_L2)
#define L2_toogle() (PORTA ^= LED_L2)

//LED 3
#define LED_L3 (1 << PA2)
#define L3_output() (DDRA |= LED_L3)
#define L3_on() (PORTA |= LED_L3)
#define L3_off() (PORTA &= ~LED_L3)
#define L3_toogle() (PORTA ^= LED_L3)

//Buzzer
#define BUZZER (1 << PB4)
#define BUZZER_output() (DDRB |= BUZZER)
#define BUZZER_on() (PORTB |= BUZZER)
#define BUZZER_off() (PORTB &= ~BUZZER)

//Entrada digital 2
#define P02 (1 << PE6)
#define P02_input() (DDRE &= ~P02)
#define P02_setup() (PORTE |= P02)
#define P02_read() (PINE & P02)

//Entrada digital 3
#define P03 (1 << PD7)
#define P03_input() (DDRD &= ~P03)
#define P03_setup() (PORTD |= P03)
#define P03_read() (PIND & P03)

//Saída digital 10
#define P10 (1 << PB0)
#define P10_output() (DDRB |= P10)
#define P10_on() (PORTB |= P10)
#define P10_off() (PORTB &= ~P10)

//Saída digital 11
#define P11 (1 << PB2)
#define P11_output() (DDRB |= P11)
#define P11_on() (PORTB |= P11)
#define P11_off() (PORTB &= ~P11)

//Saída digital 12
#define P12 (1 << PB3)
#define P12_output() (DDRB |= P12)
#define P12_on() (PORTB |= P12)
#define P12_off() (PORTB &= ~P12)

//Saída digital 13
#define P13 (1 << PB1)
#define P13_output() (DDRB |= P13)
#define P13_on() (PORTB |= P13)
#define P13_off() (PORTB &= ~P13)

//Saída analógica 5
#define P05 (1 << PC7)
#define P05_output() (DDRC |= P05)
#define P05_on() (PORTC |= P05)
#define P05_off() (PORTC &= ~P05)

//Saída analógica 6
#define P06 (1 << PB7)
#define P06_output() (DDRB |= P06)
#define P06_on() (PORTB |= P06)
#define P06_off() (PORTB &= ~P06)

//Saída analógica 9
#define P09 (1 << PC4)
#define P09_output() (DDRC |= P09)
#define P09_on() (PORTC |= P09)
#define P09_off() (PORTC &= ~P09)

//Motores
//PWM
#define PWM_output() (DDRC |= (1 << PC5) | (1 << PC6))
#define PWM_on() (PORTC |= (1 << PC5) | (1 << PC6))
//MD1
#define MD1 (1 << PD5)
#define MD1_output() (DDRD |= MD1)
#define MD1_on() (PORTD |= MD1)
#define MD1_off() (PORTD &= ~MD1)
//MD2
#define MD2 (1 << PA3)
#define MD2_output() (DDRA |= MD2)
#define MD2_on() (PORTA |= MD2)
#define MD2_off() (PORTA &= ~MD2)
//ME1
#define ME1 (1 << PE4)
#define ME1_output() (DDRE |= ME1)
#define ME1_on() (PORTE |= ME1)
#define ME1_off() (PORTE &= ~ME1)
//ME2
#define ME2 (1 << PE3)
#define ME2_output() (DDRE |= ME2)
#define ME2_on() (PORTE |= ME2)
#define ME2_off() (PORTE &= ~ME2)

#define ME_re ME1_on();MD2_off();
#define MD_re MD1_off();MD2_on();
#define ME_frente ME1_off();ME2_on();
#define MD_frente MD1_on();MD2_off();
#define ME_pare ME1_off();ME2_off();
#define MD_pare MD1_off();MD2_off();

//SV1
#define SV1 (1 << PB5)
#define SV1_output() (DDRB |= SV1)

//SV2
#define SV2 (1 << PB6)
#define SV2_output() (DDRB |= SV2)


#endif /* IO_H_ */