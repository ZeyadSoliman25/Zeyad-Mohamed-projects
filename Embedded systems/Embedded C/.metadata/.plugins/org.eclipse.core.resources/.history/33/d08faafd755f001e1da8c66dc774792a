/*
 ============================================================================
 Name        : BitFields_Ex2.c
 Author      : Mohamed Tarek
 Description : Example to illustrate the idea of bit-fields
 Date        : 31/3/2019
 ============================================================================
 */
#include <stdio.h>

struct Data
{
  unsigned int a : 6;
  unsigned int   : 10;
  unsigned int b : 16;
}Data1;

struct Example
{
  unsigned int a : 6;
  unsigned int   : 0;
  unsigned int b : 16;
}Example1;

int main()
{
	printf("%d\n",sizeof(Data1));

	printf("%d\n",sizeof(Example1));

    return 0;
}
