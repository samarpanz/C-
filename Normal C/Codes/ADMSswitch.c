#include <stdio.h>
int main(){
	int a,b,c;
	
	printf("Enter two numbers and click what u want to do with it ");
	scanf("%d%d",&a,&b);
	
	printf("Enter what u want to do ");
	printf("1.Addition \n 2.Multiplication\n 3.Division\n 4.Modulus\n");
	
	scanf("%d",&c);
	
	switch(c){
		
		case 1:
			printf("The addition of two number is %d",a+b);
			break;
		case 2:
			printf("The Multiplication of two number is %d",a*b);
			break;
		case 3:
			printf("The Division of two number is %d",a/b);
			break;
		case 4:
			printf("The Modulus of two number is %d",a%b);
			break;
		default:
			printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
		
	}
	return 0;
}
