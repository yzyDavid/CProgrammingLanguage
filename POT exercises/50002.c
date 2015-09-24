#include <stdio.h>

int sign_(int num);
int main(void) {
	int rep;
	scanf("%d", &rep);
	int i;
	for (i = 0; i < rep; ++i) {
		int num;
		scanf("%d", &num);
		printf("sign(%d) = %d\n", num, sign_(num));
	}
	return 0;
}

int sign_(int num) {
	return num == 0 ? 0 : (num > 0 ? 1 : -1);
}
