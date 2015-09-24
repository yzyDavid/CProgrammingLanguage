#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int* prime, int length);
int main(void) {
	int lower = 0, upper = 0;
	int prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	scanf("%d %d", &lower, &upper);
	int count = 0;
	int num, j;
	for (num = lower; num <= upper; ++num) {
		if (num % 2 != 0) {
			continue;
		}
		for (j = 0; j < 25; ++j) {
			if (isPrime(num - prime[j], prime, 25)) {
				printf("%d=%d+%d ", num, prime[j], num - prime[j]);
				++count;
				if (count == 5) {
					printf("\n");
					count = 0;
				}
				break;
			}
		}
	}
	return 0;
}

bool isPrime(int num, int* prime, int length) {
	int i;
	for (i = 0; i < length; ++i) {
		if (prime[i] == num) {
			return true;
		}
	}
	return false;
}
