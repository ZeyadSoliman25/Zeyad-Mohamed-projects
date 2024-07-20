#include "uart.h"
#include <avr/io.h>
#include "common_macros.h"



void UART_init(const UART_ConfigType *Config_Ptr)
{
	uint16 ubrr_value = 0;

	UCSRA = (1<<U2X);

	UCSRB = (1<<RXEN) | (1<<TXEN) | ((GET_BIT(Config_Ptr -> bit_data,2)) << UCSZ2);
	
	UCSRC = (1<<URSEL) | ((GET_BIT(Config_Ptr -> bit_data,0)) <<UCSZ0) | ((GET_BIT(Config_Ptr -> bit_data,1)) <<UCSZ1) | ((Config_Ptr -> stop_bit) << USBS);
	UCSRC = (UCSRC & 0XCF) | ((Config_Ptr -> parity) << 4);
	
	ubrr_value = (uint16)(((F_CPU / ((Config_Ptr -> baud_rate) * 8UL))) - 1);

	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;
}


void UART_sendByte(const uint8 data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	UDR = data;
}


uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

    return UDR;		
}


void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}


void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	Str[i] = UART_recieveByte();

	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	Str[i] = '\0';
}
