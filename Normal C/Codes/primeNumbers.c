
#include <stdio.h>
int main() {
    int i,j,N,count;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Prime numbers from 1 to %d are:\n", N);
    for(i=2;i<=N;i++){
        count = 0;
        for(j=1;j<=i;j++){
            if (i%j==0){
                count++;
            }
        }
        if(count==2) {
            printf("%d\t", i);
        }
    }
    return 0;
}
