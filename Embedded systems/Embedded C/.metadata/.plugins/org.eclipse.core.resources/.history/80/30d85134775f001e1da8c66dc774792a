/*
 ============================================================================
 Name        : BitFields_Ex3.c
 Author      : Mohamed Tarek
 Description : Example to illustrate the idea of bit-fields
 Date        : 31/3/2019
 ============================================================================
 */
#include <stdio.h>

struct Status
{
  unsigned int Set1 : 3;
  unsigned int      : 4;
  unsigned int Set2 : 3;
}Current;

int main()
{
	Current.Set1 = 15; /* Set1 is just 3-bits so it will contain 7(0b111) not 15(0b1111) */

	Current.Set1 = Current.Set1 >> 2;

	printf("%d\n",Current.Set1);

	printf("%d\n",sizeof(Current));

    return 0;
}
