#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned long uint32;

uint32 FallingEdgCounter(uint8 pinreading){
	static uint8 previous = 0;
	static uint32 count = 0;

	if ((pinreading == 0) & (previous == 1)){
		count++;
	}
	previous = pinreading;
	return count;

}

int main(){
	uint32 count = 0;
	count = FallingEdgCounter(1);

	count = FallingEdgCounter(1);

	/* falling edge the count should be equal 1 */
	count = FallingEdgCounter(0);

	count = FallingEdgCounter(1);

	/* falling edge the count should be equal 2 */
	count = FallingEdgCounter(0);

	count = FallingEdgCounter(0);

	count = FallingEdgCounter(1);

	/* falling edge the count should be equal 3 */
	count = FallingEdgCounter(0);

	printf("count = %d",count);
}

