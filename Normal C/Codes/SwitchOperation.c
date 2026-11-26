#include <stdio.h>

void reverse_number(int num){
int original = num;
int rev,rem;
while(num>0){
rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
}
printf("The reverse is: %d",rev);
}

int main(){
  
int cases,number;
  
printf("Enter the operation you want to do: \n");
  
printf("1. Reverse the Number \n 2. Find the sum of digit \n 3. Count the total number of digits\n");
scanf("%d",&cases);
  
printf("Enter the number:");
scanf("%d",&number);
  
switch(cases){
case 1:
 reverse_number(number);
 break;
case 2:
 sum_digits(number);
 break;
default:
 printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
}
return 0;
}
