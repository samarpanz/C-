#include <stdio.h>
int main() {

    int n;
    printf("Enter n numbers to which u want to see the even numbers: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}