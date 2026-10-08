#include <stdio.h>

void checkEvenOrOdd(int number)
{
	if (number % 2 == 0)
		printf("%d is even.\n", number);
	else
		printf("%d is odd.\n", number);
}

void checkPositiveOrNegative(int number)
{
	if (number > 0)
		printf("%d is positive.\n", number);
	else if (number < 0)
		printf("%d is negative.\n", number);
	else
		printf("%d is zero.\n", number);
}

void findGreatestAndSmallest(int first, int second, int third)
{
	int greatest = first;
	int smallest = first;

	if (second > greatest)
		greatest = second;
	if (third > greatest)
		greatest = third;

	if (second < smallest)
		smallest = second;
	if (third < smallest)
		smallest = third;

	printf("Greatest number: %d\n", greatest);
	printf("Smallest number: %d\n", smallest);
}

int main(void)
{
	int number;
	int first;
	int second;
	int third;

	printf("Enter a number to check even or odd: ");
	scanf("%d", &number);
	checkEvenOrOdd(number);

	printf("Enter a number to check positive or negative: ");
	scanf("%d", &number);
	checkPositiveOrNegative(number);

	printf("Enter three numbers: ");
	scanf("%d %d %d", &first, &second, &third);
	findGreatestAndSmallest(first, second, third);

	return 0;
}
