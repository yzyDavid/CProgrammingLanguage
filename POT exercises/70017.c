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
		int findNum;
		scanf("%d", &findNum);
		char flag = -1;
		for (i = 0; i < n; i++) {
			if (num[i] == findNum) {
				flag = i;
				break;
			}
		}
		if (flag != -1) {
			printf( "%d: a[%d]\n", findNum, flag);
		}
		else {
			printf( "%d: not found\n", findNum);
		}
	}
	return 0;
}
	