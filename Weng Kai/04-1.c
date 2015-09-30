#include <stdio.h>

int power(int base, int exp)
{
	int ans = 1;
	for (int i = 0; i < exp; i++) ans *= base;
	return ans;
}

int main(void) 
{
	int n, start = 1, end;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) start *= 10;
	end = start * 10 - 1;
	for (int i = start; i < end; i++) {
		int digit = i, total = 0;
		for (int j = 0; j < n; j++) {
			total += power(digit % 10, n);
			digit /= 10;
		}
		if (total == i) printf("%d\n", i);
	}

	return 0;
}
