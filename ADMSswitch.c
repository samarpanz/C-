// The switch case statement in C is a multi-way branching control structure that tests an expression against multiple constant values, serving as a more efficient alternative to cascading if-else statements for discrete cases.  The expression must evaluate to an integral or character type (e.g., int, char), and the program jumps to the matching case label; if no match is found, it executes the optional default block.
#include <stdio.h>
int main(void)
{
	double firstNumber, secondNumber;
	int choice;

    // double is used to store decimal values, which is necessary for performing arithmetic operations accurately.

	printf("Enter two numbers: ");
	if (scanf("%lf %lf", &firstNumber, &secondNumber) != 2) {
		printf("Invalid number input.\n");
		return 1;
	}
    
    // %lf is used to read double values from the user input. The program checks if the input is valid by verifying that two numbers were successfully read; if not, it prints an error message and exits with a non-zero status code.

	printf("\nChoose an operation:\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("Enter your choice: ");
	if (scanf("%d", &choice) != 1) {
		printf("Invalid menu choice.\n");
		return 1;
	}

	switch (choice) {
		case 1:
			printf("Result: %g\n", firstNumber + secondNumber);
			break;
		case 2:
			printf("Result: %g\n", firstNumber - secondNumber);
			break;
		case 3:
			printf("Result: %g\n", firstNumber * secondNumber);
			break;
		case 4:
			if (secondNumber == 0) {
				printf("Error: division by zero is not allowed.\n");
			} else {
				printf("Result: %g\n", firstNumber / secondNumber);
			}
			break;
		default:
			printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
	}

	return 0;
}
