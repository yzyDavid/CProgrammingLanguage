#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
	for (int i = 2; i <= sqrt(x); i++) 
		if (x % i == 0) return 0;
	return 1;
}

int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	int count = 0, prime[100001];
	for (int i = 2; count < n; i++)
		if (isPrime(i)) prime[++count] = i;
	for (int i = m; i <= n; i++) {
		printf("%d", prime[i]);
		if ((i - m) % 10 == 9 || i == n) printf("\n");
		else printf(" ");
	}

	return 0;
}
