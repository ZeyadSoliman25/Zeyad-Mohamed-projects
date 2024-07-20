#include <stdio.h>

typedef unsigned long uint32;

/* Macro to change from one endian to another */
#define CHANGE_ENDIANNESS(A)   ((((uint32)(A) & 0xff000000) >> 24)  \
                               | (((uint32)(A) & 0x00ff0000) >> 8)  \
                               | (((uint32)(A) & 0x0000ff00) << 8)  \
                               | (((uint32)(A) & 0x000000ff) << 24))
int main(void)
{
	uint32 u32CheckData  = 0x11223344;
	uint32 u32ResultData =0;
    u32ResultData = CHANGE_ENDIANNESS(u32CheckData);
    printf("0x%x\n",u32ResultData);
    return 0;
}



