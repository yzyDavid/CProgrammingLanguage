#include <stdio.h>

int main(void) {
	int rep;
	int ri;
	scanf("%d", &rep);
	for (ri = 0; ri < rep; ri++) {
		int n;
		scanf("%d", &n);
		int i;
		int num[10] = {0};
		for (i = 0; i < n; ++i) {
			scanf("%d", &num[i]);
		}
		i--;
		while (i >= 0) {
			printf("%d ", num[i--]);
		}
		puts("");
	}
	return 0;
}
