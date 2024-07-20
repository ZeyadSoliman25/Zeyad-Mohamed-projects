/*
 * q17.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int maximal_value (int l, int r);


int main(){
	int l = 0;
	int r = 0;
	int max_value = 0;
	printf("Enter two constraints: ");
	scanf("%d %d", &l, &r);
	max_value = maximal_value(l,r);
	printf("The max value of A xor B = %d", max_value);
}


int maximal_value(int l, int r){
	int max_value= 0;
	if (l>=1 && l<=r && r>=1 && r<=1000){
		for (int i = l; i <= r; i++){
			for (int j = l; j<= i; j++){
				if ((i^j) >= max_value){
					max_value = i^j;
				}
			}
		}
	}
	else{
		printf("Out of constraints.");
	}
	return max_value;
}
