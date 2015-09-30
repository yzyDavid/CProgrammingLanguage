#include <stdio.h>

int main(void)
{
	int n;
	double numerator = 2.0, denominator = 1.0, ans = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ans += numerator / denominator;
		numerator += denominator;
		denominator = numerator - denominator;
	}
	printf("%.2f\n", ans);

	return 0;
}
