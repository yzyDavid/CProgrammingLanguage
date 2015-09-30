#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
	if (x == 1) return 0;
	for (int i = 2; i <= sqrt(x); i++) 
		if (x % i == 0) return 0;
	return 1;
}

int main(void)
{
	int m, n, count = 0, total = 0;
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++)
		if (isPrime(i)) {
			count++;
			total += i;
		}
	printf("%d %d\n", count, total);

	return 0;
}
