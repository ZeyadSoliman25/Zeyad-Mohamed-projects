#include <stdio.h>

#define FOURTH_BIT(num) ((num & (1<<4)) >> 4)

int main(void){
	int num = 16;
	int bit = 0;
	bit = FOURTH_BIT(num);
	printf("%d", bit);
}

