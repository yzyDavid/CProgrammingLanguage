#include <stdio.h>

int main(void)
{
	int numerator, denominator;
	scanf("%d/%d", &numerator, &denominator);
	int min = numerator < denominator ? numerator : denominator;
	for (int i = 2; i <= min; i++)
		while (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
		}
	printf("%d/%d\n", numerator, denominator);

	return 0;
}
