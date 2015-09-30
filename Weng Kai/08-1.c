#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, frequency[10];
	memset(frequency, 0, sizeof(frequency));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		while (t > 0) {
			frequency[t % 10]++;
			t /= 10;
		}
	}
	int max = 0;
	for (int i = 0; i < 10; i++)
		if (frequency[i] > frequency[max]) max = i;
	printf("%d:", frequency[max]);
	for (int i = 0; i < 10; i++)
		if (frequency[i] == frequency[max])
			printf(" %d", i);
	printf("\n");

	return 0;
}
