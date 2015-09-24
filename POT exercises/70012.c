#include <stdio.h>

int main(void) {
	int rep;
	int n;
	scanf("%d", &rep);
	int k;
	for (k = 0; k < rep; k++) {
		scanf("%d", &n);
		int i;
		int sum = 0;
		for (i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("average = %.2lf\n", (double)sum / n);
	}
	return 0;
}
