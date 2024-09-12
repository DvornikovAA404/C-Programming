#include <stdio.h>

int main()
{
	float a = 0.1;
	float b = 0.2;
	printf("|%d|\n", 555);
	printf("|%8d|\n", 555);
	printf("|%-8d|\n", 555);
	printf("\n");
	printf("Words: %8d\n", 59);
	printf("Letters: %6d\n", 1004);
	printf("Digits: %7d\n", 8);
	printf("\n");
	printf("a = %.6f; b = %.6f\n", a, b);
	printf("a + b = %.18f\n", a+b);
}
