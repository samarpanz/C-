#include <stdio.h>
int main(void)
{
	int subj1;
	int subj2;
	int subj3;
	int subj4;
	int subj5;
	double avg;
	double gpa;
    // double is used to store decimal values, which is necessary for calculating the average and GPA accurately.
    printf("Enter the marks for 5 subjects: ");
	scanf("%d %d %d %d %d", &subj1, &subj2, &subj3, &subj4, &subj5);

	avg = (subj1 + subj2 + subj3 + subj4 + subj5) / 5.0;

	if (avg >= 80){
		gpa = 4.0;
    }
	else if (avg>= 70){
		gpa = 3.0;
    }
	else if (avg >= 60){
		gpa = 2.0;
    }
	else if (avg >= 50){
        gpa = 1.0;
    }
	else{
		gpa = 0.0;
    }
	printf("Average marks: %.2f\nGPA: %.2f\n", avg, gpa);
    // %2f represents the number of decimal places to display in the output. In this case, it will display the average marks and GPA with two decimal places.

	return 0;
}
