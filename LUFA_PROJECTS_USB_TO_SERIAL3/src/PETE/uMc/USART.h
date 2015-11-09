/*
 * USART.h
 *
 * Created: 28/01/2015 19:07:50
 *  Author: pacheco
 */ 

#include <avr/io.h>
#include <util/setbaud.h>
#ifndef USART_H_
	#define USART_H_

#ifndef BAUD                          /* if not defined in Makefile... */
		#define BAUD  38400                     /* set a safe default baud rate */
#endif


    /* These are defined for convenience */
	#define   USART_HAS_DATA   bit_is_set(UCSR0A, RXC0)
	#define   USART_READY      bit_is_set(UCSR0A, UDRE0)


/* Takes the defined BAUD and F_CPU,
    calculates the bit-clock multiplier,
    and configures the hardware USART                   */
void inicia_USART();


/* Blocking transmit and receive functions.
    When you call receiveByte() your program will hang until
    data comes through.  We'll improve on this later. */
void transmitByte(uint8_t data);
uint8_t receiveByte(void);

void printString(const char myString[]);
void printString_nl(const char myString[]);

/* Utility function to transmit an entire string from RAM */
void readString(char myString[], uint8_t maxLength);
 /* Define a string variable, pass it to this function
    The string will contain whatever you typed over serial */


void printByte(uint8_t byte);
                  /* Prints a byte out as its 3-digit ascii equivalent */
void printWord(uint16_t word);
        /* Prints a word (16-bits) out as its 5-digit ascii equivalent */

void printBinaryByte(uint8_t byte);
                                    /* Prints a byte out in 1s and 0s */
char nibbleToHex(uint8_t nibble);
void printHexByte(uint8_t byte);
                                   /* Prints a byte out in hexadecimal */
uint8_t getNumber8(void);  /* takes in up to three ascii digits,
						   converts them to a byte when press enter */
uint16_t getNumber16(void);




#endif /* USART_H_ */