#include <stdio.h>

unsigned char RightCircularShift(unsigned int InputNumber, int NumberOfShifts, unsigned int * pOutput)
{
	if(NumberOfShifts > (8*sizeof(InputNumber)) )
	{
		*pOutput = InputNumber;
		return 0xFF;
	}
	else
	{
		*pOutput = ( InputNumber >> NumberOfShifts ) | ( InputNumber << ( (8*sizeof(InputNumber)) - NumberOfShifts) );
		return 0;
	}
}

int main(void)
{
	unsigned int num = 255; /* binary = 00000000 00000000 00000000 11111111 */
	unsigned int output = 0;
	unsigned char error_status = 0;

	error_status = RightCircularShift(num,2,&output);

	if(error_status == 0)
	{
		printf("count = %u\n",output); /* it should be equals to 11000000000000000000000000111111 */
	}
	else if(error_status == 0xFF)
	{
		printf("The number of shifts must be less than or equal 32 for unsigned int\n");
	}

	error_status = RightCircularShift(num,40,&output);

	if(error_status == 0)
	{
		printf("count = %u\n",output);
	}
	else if(error_status == 0xFF)
	{
		printf("The number of shifts must be less than or equal 32 for unsigned int\n");
	}

	return 0;
}
