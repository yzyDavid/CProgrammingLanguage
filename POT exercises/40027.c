#include <stdio.h>

void atoi_out(int num);
int main(void) {
	int rep;
	scanf("%d", &rep);
	int i;
	for (i = 0; i < rep; ++i) {
		int num;
		scanf("%d", &num);
		num = num > 0 ? num : -num;
		atoi_out(num);
		puts("");
	}
	return 0;
}

void atoi_out(int num) {
	if (num / 10 == 0) {
		printf("%d ", num);
	}
	else {
		atoi_out(num / 10);
		printf("%d ", num % 10);
	}
}
