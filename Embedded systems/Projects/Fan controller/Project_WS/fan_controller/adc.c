#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt)<<6) ;
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr -> prescaler);
	ADCSRA |= (1<<ADEN);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
