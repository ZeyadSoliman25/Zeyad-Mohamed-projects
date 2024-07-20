#include <stdio.h>

#define CLEAR_BIT(num,bitnum) (num & ~(1<<bitnum))


int main(void){
	int num = 15;
	num = CLEAR_BIT(num,3);
	printf("%d",num);
}


