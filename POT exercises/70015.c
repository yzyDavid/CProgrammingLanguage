#include <stdio.h>
#include <limits.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(void) {
	int rep;
	scanf("%d", &rep);
	int ri;
	for (ri = 0; ri < rep; ri++) {
		int n;
		scanf("%d", &n);
		int i;
		int num[11];
		int max = INT_MIN;
		int min = INT_MAX;
		int maxi = 0;
		int mini = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			if (num[i] > max) {
				max = num[i];
				maxi = i;
			}
			if (num[i] < min) {
				min = num[i];
				mini = i;
			}
		}
		if (maxi != 0) {
			swap(&num[maxi], &num[n - 1]);
		}
		swap(&num[mini], &num[0]);
		printf("After swap: ");
		for (i = 0; i < n; i++) {
			printf("%d ", num[i]);
		}
		puts("");
	}
	return 0;
}
