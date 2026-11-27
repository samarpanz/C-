#include <stdio.h>
#define PI 3.14
float areaOfCircle(){
	float rad;
	printf("Enter the radius: ");
	scanf("%f",&rad);
	return PI*rad*rad;	
}
float areaOfRectangle(){
	float l,b;
	printf("Enter the length and width: ");
	scanf("%f%f",&l,&b);
	return l*b;
}
float areaOftriangle(){
	float b,h;
	printf("Enter the base and height: ");
	scanf("%f%f",&b,&h);
	return 0.5*b*h;
}
int main(){
	int c;
	printf("Enter: \n");
	printf("1. Area of Circle\n2. Area of rectangle\n3.Area of Triangle   ");
	scanf("%d",&c);
	switch(c){
		case 1:
			printf("The area is: %f",areaOfCircle());
			break;
		case 2:
			printf("The area is: %f",areaOfRectangle());
			break;
		case 3:
			printf("The area is: %f",areaOftriangle());
			break;
		default:
			printf("Invalid!");
			
	}
	return 0;
}
