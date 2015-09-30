#include <stdio.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int product = i * j;
			printf("%d*%d=%d", j, i, product);
			if (product >= 10) printf("  ");
			else printf("   ");
		}
		printf("\n");
	}

	return 0;
}
