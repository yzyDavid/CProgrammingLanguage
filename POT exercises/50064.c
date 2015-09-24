#include <stdio.h>

int reverse(int in);
int main(void) {
	int rep;
	int i;
	scanf("%d", &rep);
	for (i = 0; i < rep; ++i) {
		int in;
		scanf("%d", &in);
		in < 0 ? putchar('-'), in = -in : 1;
		printf("%d\n", reverse(in));
	}
	return 0;
}

int reverse(int in) {
	if (in / 10 != 0) {
		int tmp = in, count = 1;
		do {
			tmp /= 10;
			count *= 10;
		} while (tmp >= 10);
		return tmp + 10 * reverse(in - tmp * count);
	}
	else {
		return in;
	}
}
