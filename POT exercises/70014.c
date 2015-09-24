#include <stdio.h>
#include <limits.h>

int main(void) {
	int rep;
	scanf("%d", &rep);
	int ri;
	for (ri = 0; ri < rep; ri++) {
		int n;
		scanf("%d", &n);
		int i;
		int max = INT_MIN;
		int maxi = 0;
		for (i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp > max) {
				max = tmp;
				maxi = i;
			}
		}
		printf("max = %d, index = %d\n", max, maxi);
	}
	return 0;
}
