#include <stdio.h>

#define GET_BIT(REGISTER,BITNUMBER) ((REGISTER & (1<<BITNUMBER)) >> BITNUMBER)


int main(){
	int bit = 0;
	bit = GET_BIT(4,2);
	printf("%d",bit);

}
