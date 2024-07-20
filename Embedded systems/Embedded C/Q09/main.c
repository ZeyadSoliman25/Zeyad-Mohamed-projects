#include <stdio.h>

typedef unsigned long uint32;

/* Function to change from one endian to another */
uint32 ChangeEndianness(uint32 u32Value)
{
	uint32 u32Result = 0;
    u32Result |= (u32Value & 0x000000FF) << 24;
    u32Result |= (u32Value & 0x0000FF00) << 8;
    u32Result |= (u32Value & 0x00FF0000) >> 8;
    u32Result |= (u32Value & 0xFF000000) >> 24;
    return u32Result;
}

int main()
{
	uint32 u32CheckData  = 0x11223344;
	uint32 u32ResultData =0;
    u32ResultData = ChangeEndianness(u32CheckData); /* swap the data */
    printf("0x%x\n",u32ResultData);
    return 0;
}
