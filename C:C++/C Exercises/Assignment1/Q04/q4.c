/*
 * q4.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>
int main(){
	float radius = 0 ;
	float circumference = 0 ;
	float area = 0 ;
	printf("Enter the radius of the circle: ");
	scanf("%f", &radius);
	circumference = 2 * 3.14 * radius ;
	area = pow(radius,2) * 3.14 ;
	printf("The circumference of circle is: %f \n", circumference);
	printf("The area of circle is : %f \n", area);

}
