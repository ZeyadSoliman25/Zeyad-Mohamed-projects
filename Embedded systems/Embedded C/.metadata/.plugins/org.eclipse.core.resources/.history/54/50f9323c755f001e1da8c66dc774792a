/*
 ============================================================================
 Name        : BitFields_Ex1.c
 Author      : Mohamed Tarek
 Description : Example to illustrate the idea of bit-fields
 Date        : 31/3/2019
 ============================================================================
 */
#include <stdio.h>

/* define simple structure */
typedef struct
{
  unsigned int widthValidated;
  unsigned int heightValidated;
}status1;

/* define a structure with bit fields */
typedef struct
{
  unsigned  int widthValidated  : 1;
  unsigned  int heightValidated : 5;
}status2;

/* define a structure with bit fields */
typedef struct
{
  unsigned  int widthValidated  : 1;
  unsigned  int heightValidated : 5;
  unsigned  int longValidated   : 10;
}status3;

/* define a structure with bit fields */
typedef struct
{
  unsigned  int widthValidated  : 32;
  unsigned  int heightValidated : 5;
  unsigned  int longValidated   : 3;
} status4;

/* define a structure with bit fields */
typedef struct
{
  unsigned  int widthValidated  : 9;
  unsigned  int heightValidated : 20;
  unsigned  int longValidated;
} status5;

int main()
{
	 printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
	 printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
	 printf( "Memory size occupied by status3 : %d\n", sizeof(status3));
	 printf( "Memory size occupied by status4 : %d\n", sizeof(status4));
	 printf( "Memory size occupied by status4 : %d\n", sizeof(status5));
    return 0;
}
