
#ifndef _uMC_H_
#define _uMC_H_

	/* Includes: */
	#include <string.h>	
	#include <avr/io.h>
	#include <avr/wdt.h>
	#include <avr/interrupt.h>
	#include <avr/power.h>

	#include "Descriptors.h"	

	#include <LUFA/Drivers/Peripheral/Serial.h>
	#include <LUFA/Drivers/Misc/RingBuffer.h>
	#include <LUFA/Drivers/USB/USB.h>
	#include <LUFA/Platform/Platform.h>
		
	#include "src/PETE/uMc/USART.h"
	#include "src/PETE/uMc/Misc.h"
	#include "src/PETE/uMc/definicoes.h"
	#include "src/PETE/uMc/AD.h"
	#include "src/PETE/uMc/som.h"
	#include "src/PETE/uMc/servo.h"
	//#include "src/PETE/uMc/motoresDC.h"
	
	//#include "src/PETE/LEGAL/comandosAtuadores.h"
	
	
	//#include "src/PETE/LEGAL/divercos.h"	
	#include "src/PETE/LEGAL/maqVirtual.h"

	/* Macros: */

	
	/* Variaveis */
	//volatile char uMC_Modo = MODO_CONECTADO;		
	volatile uint8_t palavraRecebida[20];
	volatile uint8_t palavraRecebida_pt =0;
	volatile uint8_t palavraPronta=0;
	volatile unsigned long milliseconds = 0;
	uint8_t conStatus = 0;
	uint8_t analogico5 = 0, analogico6 = 0, analogico9 = 0, cont5 = 0, cont6 = 0, cont9 = 0, contAnalogico = 0;
	
	/** Circular buffer to hold data from the host before it is sent to the device via the serial port. */
	static RingBuffer_t USB_DadosRecebidos_pt;

	/** Underlying data buffer for \ref USB_DadosRecebidos_pt, where the stored bytes are located. */
	static uint8_t USB_DadosRecebidos_Buf[128];

	/** Circular buffer to hold data from the serial port before it is sent to the host. */
	static RingBuffer_t USB_DadosParaEnviar_pt;

	/** Underlying data buffer for \ref USB_DadosParaEnviar_pt, where the stored bytes are located. */
	static uint8_t USB_DadosParaEnviar_Buf[128];
	
	uint8_t readingStage = 0;

	/** LUFA CDC Class driver interface configuration and state information. This structure is
 * passed to all CDC Class driver functions, so that multiple instances of the same class
 * within a device can be differentiated from one another.
 */
	USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface ={
		.Config = {
			.ControlInterfaceNumber = INTERFACE_ID_CDC_CCI,
			.DataINEndpoint = {
				.Address = CDC_TX_EPADDR,
				.Size = CDC_TXRX_EPSIZE,
				.Banks = 1,
			},
			.DataOUTEndpoint = {
				.Address = CDC_RX_EPADDR,
				.Size = CDC_TXRX_EPSIZE,
				.Banks = 1,
			},
			.NotificationEndpoint = {
				.Address = CDC_NOTIFICATION_EPADDR,
				.Size = CDC_NOTIFICATION_EPSIZE,
				.Banks = 1,
			},
		},
	};
	


	/* Function Prototypes: */
	void mc_conectado();
	void mc_executa();
	void testeCom();
	void scratchCom();
	void ModoControlar();
	void PosicionarServos();
	void ApagarLeds();
	void enviarDados();
	void mostraMemoria();
	void iniciaHardware();
	void iniciaInterrupt5(void);
	
	
	void receberUSB(void);
	void enviarUSB(void);
	void envieUSB_string_nl(char dado[]);
	void envieUSB_string(char dado[]);
	void envieUSB_sensors(char dado[], uint8_t n);
	void envieUSB_Byte(int8_t byte);
	void envieUSB_Word(int16_t word);
	void envieUSB_dado(int16_t word);
	void envieUSB_nl();
	void envieUSB_Char(uint8_t byte);
	int8_t palavraLida(uint8_t modo);
	void resetBuffer();
	
	void EVENT_USB_Device_Connect(void);
	void EVENT_USB_Device_Disconnect(void);
	void EVENT_USB_Device_ConfigurationChanged(void);
	void EVENT_USB_Device_ControlRequest(void);
	

	void EVENT_CDC_Device_LineEncodingChanged(USB_ClassInfo_CDC_Device_t* const CDCInterfaceInfo);

#endif

