#include <stdio.h>

typedef long uint32;
typedef char uint8;


uint32 RisingEdgCounter(uint8 pinreading){
	static uint8 prevoius = 0;
	static uint32 count = 0;

	if ((pinreading == 1)& (prevoius == 0)){
		count++;
	}
	prevoius = pinreading;
	return count;
}

int main(){
	uint32 count = 0;
	count = RisingEdgCounter(1);

	count = RisingEdgCounter(0);

	/* raising edge the count should be equal 1 */
	count = RisingEdgCounter(1);

	count = RisingEdgCounter(1);

	count = RisingEdgCounter(0);

	/* raising edge the count should be equal 2 */
	count = RisingEdgCounter(1);

	count = RisingEdgCounter(0);

	/* raising edge the count should be equal 3 */
	count = RisingEdgCounter(1);

	printf("count = %d",count);

}


