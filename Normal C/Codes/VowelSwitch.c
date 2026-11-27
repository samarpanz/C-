#include <stdio.h>
int main(){
	char l;
	printf("Enter a letter to find out weather the number is vowel or not\t");
	scanf("%c",&l);
	
	switch(l){
		case 'a':
			printf("Vowel");
			break;
		case 'e':
			printf("Vowel");
			break;
		case 'i':
			printf("Vowel");
			break;
		case 'o':
			printf("Vowel");
			break;
		case 'u':
			printf("Vowel");
			break;
			
		default:
			printf("Consonent");
	}
	return 0;
}
