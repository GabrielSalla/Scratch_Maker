/*
 * USART.c
 *
 * Created: 28/01/2015 18:55:20
 *  Author: pacheco
 */ 
#include "USART.h"

void inicia_USART() {                           /* requires BAUD */
	UBRR1H = UBRRH_VALUE;                        /* definido em  setbaud.h */
	UBRR1L = UBRRL_VALUE;
	#if USE_2X
		UCSR1A |= (1 << U2X1);
	#else
	   UCSR1A &= ~(1 << U2X1);
	#endif
	                                   /* Enable USART transmitter/receiver */
	UCSR1B = (1 << TXEN1) | (1 << RXEN1);
	UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);   /* 8 data bits, 1 stop bit */
}


void transmitByte(uint8_t data) {
                                      /* espera para o buffer de envio ficar fazio */
	loop_until_bit_is_set(UCSR1A, UDRE1);
	UDR1 = data;                                            /* envia o  dado */
}


uint8_t receiveByte(void) {
	loop_until_bit_is_set(UCSR1A, RXC1);       /* Wait for incoming data */
	return UDR1;                                /* return register value */
}
 

void readString(char myString[], uint8_t maxLength) {
	char response;
	uint8_t i;
	i = 0;
	while (i < (maxLength - 1)) {                   /* prevent over-runs */
		response = receiveByte();
		transmitByte(response);                                    /* echo */
		if (response == '\r') {                     /* enter marks the end */
			break;
		}
		else {
			myString[i] = response;                       /* add in a letter */
			i++;
		}
	}
	myString[i] = 0;                          /* terminal NULL character */
}


uint8_t getNumber8(void) {
	// Gets a numerical 0-255 from the serial port.
	// Converts from string to number.
	char hundreds = '0';
	char tens = '0';
	char ones = '0';
	char thisChar = '0';
	do {                                                   /* shift over */
			hundreds = tens;
			tens = ones;
			ones = thisChar;
			thisChar = receiveByte();                   /* get a new character */
			transmitByte(thisChar);                                    /* echo */
		} while (thisChar != '\r');                     /* until type return */	 	
		transmitByte('\n'); 	
	return (100 * (hundreds - '0') + 10 * (tens - '0') + ones - '0');
	
}

uint16_t getNumber16(void) {
	// Gets a numerical 0-255 from the serial port.
	// Converts from string to number.
	char thousand = '0';
	char hundreds = '0';
	char tens = '0';
	char ones = '0';
	char thisChar = '0';
	do { 
		thousand = hundreds;                         /* shift over */
		hundreds = tens;
		tens = ones;
		ones = thisChar;
		thisChar = receiveByte();                   /* get a new character */
		transmitByte(thisChar);                                    /* echo */
		} while (thisChar != '\r');                     /* until type return */	
		transmitByte('\n'); 
		return (1000 * (thousand - '0') + 100 * (hundreds - '0') + 10 * (tens - '0') + ones - '0');		
	}

void printByte(uint8_t byte) {
	/* Converts a byte to a string of decimal text, sends it */
	transmitByte('0' + (byte / 100));                        /* Hundreds */
	transmitByte('0' + ((byte / 10) % 10));                      /* Tens */
	transmitByte('0' + (byte % 10));                             /* Ones */
}

void printWord(uint16_t word) {
	transmitByte('0' + (word / 10000));                 /* Ten-thousands */
	transmitByte('0' + ((word / 1000) % 10));               /* Thousands */
	transmitByte('0' + ((word / 100) % 10));                 /* Hundreds */
	transmitByte('0' + ((word / 10) % 10));                      /* Tens */
	transmitByte('0' + (word % 10));                             /* Ones */
}

void printBinaryByte(uint8_t byte) {
	/* Prints out a byte as a series of 1's and 0's */
	uint8_t bit;
	for (bit = 7; bit < 255; bit--) {
		if (bit_is_set(byte, bit))
			transmitByte('1');
		else
			transmitByte('0');
	}
}


void printString(const char myString[]) {
	uint8_t i = 0;
	while (myString[i]) {
		transmitByte(myString[i]);
		i++;
	}
}

void printString_nl(const char myString[]) {
	uint8_t i = 0;
	while (myString[i]) {
		transmitByte(myString[i]);
		i++;
	}
	transmitByte('\r');
	transmitByte('\n');
}

char nibbleToHexCharacter(uint8_t nibble) {
	/* Converts 4 bits into hexadecimal */
	if (nibble < 10) {
		return ('0' + nibble);
	}
	else {
		return ('A' + nibble - 10);
 }
}


void printHexByte(uint8_t byte) {
	/* Prints a byte as its hexadecimal equivalent */
	uint8_t nibble;
	nibble = (byte & 0b11110000) >> 4;
	transmitByte(nibbleToHexCharacter(nibble));
	nibble = byte & 0b00001111;
	transmitByte(nibbleToHexCharacter(nibble));
}
