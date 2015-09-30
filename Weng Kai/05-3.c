#include <stdio.h>

int main(void)
{
	int a, n, tot = 0;
	scanf("%d%d", &a, &n);
	int t = a;
	for (int i = 0; i < n; i++) {
		tot += t;
		t = t * 10 + a;
	}
	printf("%d\n", tot);

	return 0;
}
