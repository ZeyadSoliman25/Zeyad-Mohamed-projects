#include <stdio.h>

#define SUM(a,size,sum)\
{\
	int i = 0;\
	for (i=0;i<size;i++)\
	{\
		sum += a[i];\
	}\
}


int main(void){
	int array[5] = {0,1,2,3,4};
	int sum = 0;

	SUM(array,5,sum);

	printf("%d",sum);

}

