#include <stdio.h>
int main(){
  int n,nth,i;

  printf("Enter n number");
  scanf("%d",&n);
  
  printf("Enter nth number");
  scanf("%d",&nth);

  for(i=0;i<=nth;i++){
    printf("%d X %d = %d \n",n,i,n*i)
  }

  return 0;
}
