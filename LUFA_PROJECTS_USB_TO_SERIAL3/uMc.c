/** \file
 *
 * 
 * the project and is responsible for the initial application hardware configuration.
 */

#include "uMc.h"

/**
* FUNÇÃO PRINCIPAL. 
 */
int main(void){
	iniciaHardware();
	
	milliseconds = 0;
	
	//setupADCSleepmode();
	mc_executa();
	
	while(1);
}

ISR(TIMER0_COMPA_vect){
	milliseconds++;
	
	if(conStatus == 1){
		if(milliseconds % 40 == 0){
			LD3R_off();
			LD3G_toogle();
		}
	}
	else{
		if(milliseconds % 500 == 0){
			LD3G_off();
			LD3R_toogle();
		}
	}
}

ISR(TIMER2_COMPA_vect){
	contAnalogico++;
	
	if(contAnalogico == 255){
		if(cont5 == analogico5 && analogico5 != 0){
			p05_set;
			cont5 = 0;
		}
		else{
			p05_reset;
		}
		
		if(cont6 == analogico6 && analogico6 != 0){
			p06_set;
			cont6 = 0;
		}
		else{
			p06_reset;
		}
		
		
		if(cont9 == analogico9 && analogico9 != 0){
			p09_set;
			cont9 = 0;
		}
		else{
			p09_reset;
		}
			
		contAnalogico = 0;
	}
	if(cont5 == analogico5){
		p05_reset;
	}
	else{
		cont5++;
	}
	if(cont6 == analogico6){
		p06_reset;
	}
	else{
		cont6++;
	}
	if(cont9 == analogico9){
		p09_reset;
	}
	else{
		cont9++;
	}
}

//******************************************************
// Rotina que gerencia o modo conectado

/*void mc_conectado(){
	unsigned long int tempo = milliseconds;
	
	while(uMC_Modo == MODO_CONECTADO){
		CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
		USB_USBTask();
		if(milliseconds - tempo >= 20 && status == 1){
			tempo = milliseconds;
			receberUSB();
		
			testeCom(); // Verifica se há e trata a coomunicaçao com o PC
		}
	}
}*/

// Rotina que gerencia o modo de execução
void mc_executa(){
	uint8_t i;
	unsigned long int tempo;
	
	tempo = milliseconds;
	while(1){
		CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
		USB_USBTask();
		
		if(milliseconds - tempo >= 5){
			tempo = milliseconds;
			
			if(conStatus == 1){
				lerEntradasuMC();
	
				receberUSB();
	
				scratchCom();
				for(i = ad0Valor; i <= ad5Valor; i++){
					envieUSB_Char(0x80 | ((i - ad0Valor)<<3) | (registradores[i] >> 7));
					envieUSB_Char(registradores[i] & 0x7F);
				}
	
				if(registradores[p02Valor]){
					envieUSB_Char(0xB7);
					envieUSB_Char(0x7F);
				}
				else{
					envieUSB_Char(0xB0);
					envieUSB_Char(0);
				}
	
				if(registradores[p03Valor]){
					envieUSB_Char(0xB8);
					envieUSB_Char(0x7F);
				}
				else{
					envieUSB_Char(0xB8);
					envieUSB_Char(0);
				}
			}
		}
	}
}


//--------------------------------------------------------------------------
// Rotina que gerencia a comunicação com a máquina hopedeira e chama as demais rotinas do MC
void testeCom(){
	if(palavraLida(MODO_CONECTADO)==1){
		if(strcmp((const char *)palavraRecebida, "ping")==0){
			envieUSB_string_nl("pong");
		}
		resetBuffer();
	}
}

void scratchCom(){
	uint8_t channel;
	uint16_t v16b;
	
	if(palavraLida(MODO_EXECUTAR)==1){
		channel = (palavraRecebida[0] >> 3) & 0x0F;
		v16b = ((palavraRecebida[0] & 0x03) << 7) | palavraRecebida[1];
		switch(channel){
			case 4:
				switch(v16b){
					case 0:
						ME_re;
						break;
					case 0xB4:
						ME_frente;
						break;
					case 0xFF:
						ME_pare;
						break;
				}
				if(v16b != 0xFF)
					OCR1A = v16b * 11 + 500;
				break;
				
			case 5:
				analogico5 = v16b;
				break;
				
			case 6:
				analogico6 = v16b;
				break;
				
			
			case 7:
				switch(v16b){
					case 0:
						MD_re;
						break;
					case 0xB4:
						MD_frente;
						break;
					case 0xFF:
						MD_pare;
						break;
				}
				break;
			
			case 8:
				if(v16b != 0xFF)
					OCR1B = v16b * 11 + 500;
				break;
				
			case 9:
				analogico9 = v16b;
				break;
				
			case 10:
				if(v16b)
					p10_set;
				else
					p10_reset;
				break;
				
			case 11:
				if(v16b)
					p11_set;
				else
					p11_reset;
				break;
				
			case 12:
				if(v16b)
					p12_set;
				else
					p12_reset;
				break;
				
			case 13:
				if(v16b)
					p13_set;
				else
					p13_reset;
				break;
				
			default:
				break;
		}
		resetBuffer();
	}
}

// Posiciona os servos em 90 graus
/*void PosicionarServos(){
	sv1_angulo(90);
	sv2_angulo(90);
}*/

// Apagar os Leds da placa
/*void ApagarLeds(){
	apagaLed(1);
	apagaLed(2);
	apagaLed(3);
}*/

/** Configura o hardware da placa. */
void iniciaHardware(){
	/* Disable watchdog if enabled by bootloader/fuses */
	MCUSR &= ~(1 << WDRF);
	wdt_disable();
	
	CLKPR = 0x80;

	/* Disable clock division */
	clock_prescale_set(clock_div_1);
	
	inicia_uMC();

	USB_Init();
	
	/* Define os Buffers de entrada e saidad de dados da USB */
	RingBuffer_InitBuffer(&USB_DadosRecebidos_pt, USB_DadosRecebidos_Buf, sizeof(USB_DadosRecebidos_Buf));
	RingBuffer_InitBuffer(&USB_DadosParaEnviar_pt, USB_DadosParaEnviar_Buf, sizeof(USB_DadosParaEnviar_Buf));

	//iniciaInterrupt5();

	GlobalInterruptEnable();
}

/*ISR(INT5_vect){
	playNote(somClick, 50);
	resetBuffer();
	reInicia_uMC();
	if(uMC_Modo == MODO_CONECTADO){
		uMC_Modo = MODO_EXECUTAR;
		LD3G_on();
		LD3R_off();
	}
	else{
		uMC_Modo = MODO_CONECTADO;
		LD3G_off();
		LD3R_on();
	}
	bt2_waitRelease();
	_delay_ms(2);
	bt2_waitRelease();
}*/

void iniciaInterrupt5(void) {
	EIMSK |= (1 << INT5); /* enable INT5 */
}

void receberUSB(void){
	int16_t ReceivedByte = 0;
	
	/* apenas tenta ler um byte da CDC interface se o buffer não está cheio. */
	while(ReceivedByte >= 0){
		if(!(RingBuffer_IsFull(&USB_DadosRecebidos_pt))){
			ReceivedByte = CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);

			/* Armazeana o byte recebido no buffer USB_DadosRecebidos_Buf */
			if(ReceivedByte >= 0){
				RingBuffer_Insert(&USB_DadosRecebidos_pt, ReceivedByte);
			}
		}
	}
}

void enviarUSB(){
	uint16_t BufferCount = RingBuffer_GetCount(&USB_DadosParaEnviar_pt);

	if(BufferCount){
		Endpoint_SelectEndpoint(VirtualSerial_CDC_Interface.Config.DataINEndpoint.Address);

		/* Check if a packet is already enqueued to the host - if so, we shouldn't try to send more data
			* until it completes as there is a chance nothing is listening and a lengthy timeout could occur */
		if(Endpoint_IsINReady()){
			/* Never send more than one bank size less one byte to the host at a time, so that we don't block
				* while a Zero Length Packet (ZLP) to terminate the transfer is sent if the host isn't listening */
			uint8_t BytesToSend = MIN(BufferCount, (CDC_TXRX_EPSIZE - 1));

			/* Read bytes from the USART receive buffer into the USB IN endpoint */
			while(BytesToSend--){
				/* Try to send the next byte of data to the host, abort if there is an error without dequeuing */
				if(CDC_Device_SendByte(&VirtualSerial_CDC_Interface,
					RingBuffer_Peek(&USB_DadosParaEnviar_pt)) != ENDPOINT_READYWAIT_NoError){
					break;
				}

				/* Dequeue the already sent byte from the buffer now we have confirmed that no transmission error occurred */
				RingBuffer_Remove(&USB_DadosParaEnviar_pt);
			}
		}
	}
}

void envieUSB_string_nl(char dado[]){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		for(int i = 0; dado[i] != 0 ; ++i)
			RingBuffer_Insert(&USB_DadosParaEnviar_pt, dado[i]);
		RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\r');
		RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\n');
		enviarUSB();
	}
}

void envieUSB_string(char dado[]){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		for(int i = 0; dado[i] != 0 ; ++i)
			RingBuffer_Insert(&USB_DadosParaEnviar_pt, dado[i]);
		enviarUSB();
	}
}

void envieUSB_sensors(char dado[], uint8_t n){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		for(int i = 0; i < n ; i++)
			RingBuffer_Insert(&USB_DadosParaEnviar_pt, dado[i]);
		enviarUSB();
	}
}

void envieUSB_Byte(int8_t byte){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (byte / 100)); /* centena */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,('0' + ((byte / 10) % 10))); /* dezena */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (byte % 10)); /* unidade*/
		enviarUSB();
	}
}

void envieUSB_Char(uint8_t byte){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,byte); 
		enviarUSB();
	}
}

void envieUSB_Char_nl(int8_t byte){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,byte);
		RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\r');
		RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\n');
		enviarUSB();
	}
}

void envieUSB_Word(int16_t word){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		if(word < 0){
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'-');					 /* sinal de - */
			word *= -1;
		}
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word / 10000));					/* Milhar */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 1000) % 10)); /* centena */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 100) % 10)); /* desena */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 10) % 10)); /* Tens */
		RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word % 10)); /* unidade */
		enviarUSB();
	}
}

void envieUSB_dado(int16_t word){
	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt))){
		if(word < 0){
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'-');										/* sinal de - */
			word *= -1;
		}
		if(word > 10000) {
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word / 10000));					/* Milhar */
			word %= 10000;
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 1000) % 10)); /* centena */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 100) % 10)); /* dezena */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 10) % 10)); /* dezena */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word % 10)); /* unidade */
		}
		else
		if(word > 1000){
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word / 1000));					/* milhar */
			word %= 1000;
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 100) % 10)); /* desena */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 10) % 10)); /* Tens */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word % 10)); /* unidade */
		}
		else
		if(word > 100){
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word / 100));					/* centena */
			word %= 100;
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + ((word / 10) % 10)); /* dezena */
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word % 10)); /* unidade */
		}
		else
		if(word > 10){
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word / 10));					/* dezena */
			word %= 10;
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + (word % 10));					/* unidade */
		}
		else
			RingBuffer_Insert(&USB_DadosParaEnviar_pt,'0' + word);								/* unidade */
		enviarUSB();
	}
}

void envieUSB_nl(){
	RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\r');
	RingBuffer_Insert(&USB_DadosParaEnviar_pt, '\n');
	enviarUSB();
}

//Retorna 1 se há uma palavra completa lida em palavraRecebida
int8_t palavraLida(uint8_t modo){
	uint16_t BufferCount = RingBuffer_GetCount(&USB_DadosRecebidos_pt);
	uint8_t dado;
	
	if(modo == MODO_CONECTADO){
		// Se existem dados no buffer da USB ele será processsado aqui
		while(BufferCount--){
			dado = RingBuffer_Remove(&USB_DadosRecebidos_pt);
			if(dado == '\r'){
				return 1;
			}
			else{
				palavraRecebida[palavraRecebida_pt++] = dado;
				palavraRecebida[palavraRecebida_pt] = 0;
				if(palavraRecebida_pt > 10){
					resetBuffer();
				}
			}
		}
	return 0;
	}
	else{
		while(BufferCount--){
			dado = RingBuffer_Remove(&USB_DadosRecebidos_pt);
			if(readingStage == 0){
				if(dado & 0x80){
					palavraRecebida[0] = dado;
					readingStage = 1;
				}
			}
			else{
				if(readingStage == 1){
					if(!(dado & 0x80)){
						palavraRecebida[1] = dado;
						readingStage = 0;
						return 1;
					}
					else{
						readingStage = 0;
					}
				}
			}
		}
	return 0;
	}
}

void resetBuffer(){
	for(palavraRecebida_pt = 0; palavraRecebida_pt < 20; palavraRecebida_pt++){
		palavraRecebida[palavraRecebida_pt] = 0;
	}
	palavraRecebida_pt = 0;
}

//***************************************************************************************

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void){
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void){
	conStatus = 0;
}

void EVENT_CDC_Device_ControLineStateChanged(USB_ClassInfo_CDC_Device_t *const 	CDCInterfaceInfo) {
	static bool PreviousDTRState = false;
	uint8_t CurrentDTRState  = (CDCInterfaceInfo->State.ControlLineStates.HostToDevice & CDC_CONTROL_LINE_OUT_DTR);

	/* Check if the DTR line has been asserted - if so, start the target AVR's reset pulse */
	if(!(PreviousDTRState) && CurrentDTRState){
		conStatus = 1;
	}
	else{
		 if(PreviousDTRState && !(CurrentDTRState)){
			 conStatus = 0;
		 }
	}

	PreviousDTRState = CurrentDTRState;
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void){
	bool ConfigSuccess = true;

	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);	
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void){
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

/** Event handler for the CDC Class driver Line Encoding Changed event.
 *
 * \param[in] CDCInterfaceInfo Pointer to the CDC class interface configuration structure being referenced
 */
void EVENT_CDC_Device_LineEncodingChanged(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo){
	uint8_t ConfigMask = 0;

	switch (CDCInterfaceInfo->State.LineEncoding.ParityType){
		case CDC_PARITY_Odd:
			ConfigMask = ((1 << UPM11) | (1 << UPM10));
			break;
		case CDC_PARITY_Even:
			ConfigMask = (1 << UPM11);
			break;
	}

	if(CDCInterfaceInfo->State.LineEncoding.CharFormat == CDC_LINEENCODING_TwoStopBits)
		ConfigMask |= (1 << USBS1);

	switch (CDCInterfaceInfo->State.LineEncoding.DataBits){
		case 6:
			ConfigMask |= (1 << UCSZ10);
			break;
		case 7:
			ConfigMask |= (1 << UCSZ11);
			break;
		case 8:
			ConfigMask |= ((1 << UCSZ11) | (1 << UCSZ10));
			break;
	}

	/* Keep the TX line held high (idle) while the USART is reconfigured */
	PORTD |= (1 << 3);

	/* Must turn off USART before reconfiguring it, otherwise incorrect operation may occur */
	UCSR1B = 0;
	UCSR1A = 0;
	UCSR1C = 0;

	/* Set the new baud rate before configuring the USART */
	UBRR1 = SERIAL_2X_UBBRVAL(CDCInterfaceInfo->State.LineEncoding.BaudRateBPS);

	/* Reconfigure the USART in double speed mode for a wider baud rate range at the expense of accuracy */
	UCSR1C = ConfigMask;
	UCSR1A = (1 << U2X1);
	UCSR1B = ((1 << RXCIE1) | (1 << TXEN1) | (1 << RXEN1));

	/* Release the TX line after the USART has been reconfigured */
	PORTD &= ~(1 << 3);
}



//***************************************************************************************

/** ISR to manage the reception of data from the serial port, placing received bytes into a circular buffer
 * for later transmission to the host.
 */
ISR(USART1_RX_vect, ISR_BLOCK){
	uint8_t ReceivedByte = UDR1;

	if((USB_DeviceState == DEVICE_STATE_Configured) && !(RingBuffer_IsFull(&USB_DadosParaEnviar_pt)))
		RingBuffer_Insert(&USB_DadosParaEnviar_pt, ReceivedByte);
}

