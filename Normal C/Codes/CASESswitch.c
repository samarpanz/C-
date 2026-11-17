// The switch case statement in C is a multi-way branching control structure that tests an expression against multiple constant values, serving as a more efficient alternative to cascading if-else statements for discrete cases.  The expression must evaluate to an integral or character type (e.g., int, char), and the program jumps to the matching case label; if no match is found, it executes the optional default block.

#include <stdio.h>
int main() {
    int day;
    printf("Enter day number (1-7):\n");
    printf("1-Sunday, 2-Monday, 3-Tuesday, 4-Wednesday\n");
    printf("5-Thursday, 6-Friday, 7-Saturday\n");
    scanf("%d", &day);

    switch (day)
    {
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
        default:
            printf("Invalid input!\n");
    }
    return 0;
}