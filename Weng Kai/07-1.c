#include <stdio.h>

int main(void)
{
	int n; scanf("%d", &n);
	while (n >= 100) {
		putchar('B');
		n -= 100;
	}
	while (n >= 10) {
		putchar('S');
		n -= 10;
	}
	for (int i = 1; i <= n; i++)
		printf("%d", i);
	printf("\n");

	return 0;
}
