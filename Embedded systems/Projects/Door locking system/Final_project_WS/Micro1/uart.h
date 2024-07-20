#ifndef UART_H_
#define UART_H_

#include "std_types.h"

typedef enum {
	FIVE_BIT, SIX_BIT, SEVEN_BIT, EIGHT_BIT, RESERVED_0,RESERVED_1,RESERVED_2, NINE_BITS
}UART_BitData;

typedef enum {
	DISABLED, RESERVED_3, EVEN_PARITY, ODD_PARITY
}UART_Parity;

typedef enum {
	ONE_BIT, TWO_BIT
}UART_StopBit;

typedef struct {
	uint32 baud_rate;
	UART_BitData bit_data;
	UART_Parity parity;
	UART_StopBit stop_bit;
}UART_ConfigType;


void UART_init(const UART_ConfigType *Config_Ptr);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str);

#endif
