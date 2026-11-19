#include <stdio.h>
void even(){
    int i = 2;

    while (i <= 100){
        printf("%d ", i);
        i = i + 2;
    }
}

void multiple(){
    int i = 1, n;

    printf("Enter N: ");
    scanf("%d", &n);

    while (i <= n){
        printf("%d ", i * 5);
        i++;
    }
}

void square(){
    int i = 1, n;

    printf("Enter N: ");
    scanf("%d", &n);

    while (i <= n)
    {
        printf("%d ", i * i);
        i++;
    }
}

void fraction(){
    int i = 2;

    while (i <= 100){
        printf("1/%d ", i);
        i = i + 2;
    }
}

int main(){

    int c;
    do{
        printf("\n\n1. Even numbers from 2 to 100");
        printf("\n2. Multiples of 5 up to N terms");
        printf("\n3. Squares up to N terms");
        printf("\n4. Fractions from 1/2 to 1/100");

        printf("\nEnter your choice: ");
        scanf("%d", &c);

        if (c == 1){
            even();
        }
        else if (c == 2){
            multiple();
        }
        else if (c == 3){
            square();
        }
        else if (c == 4){
            fraction();
        }
        else{
            printf("Invalid choice!");
        }} 
    while (c!= 0);

    return 0;
}