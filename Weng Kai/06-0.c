#include <stdio.h>

int main(void)
{
	double f1, f2; int n; char ch;
	scanf("%lf%d %c%lf", &f1, &n, &ch, &f2);
	printf("%c %d %.2f %.2f\n", ch, n, f1, f2);

	return 0;
}
