#include <stdio.h>
int main() {

    int n, temp=2;
    printf("Enter the nth term to get nth even outputs: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
            printf("%d\n", temp*i);
    }
    return 0;
}