#include <stdio.h>

int main(void) {
	int rep;
	scanf("%d", &rep);
	int i;
	for (i = 0; i < rep; ++i) {
		int num;
		int sum = 0;
		scanf("%d", &num);
		while (num >0) {
			if (num % 2 == 1) {
				sum += num;
			}
			scanf("%d", &num);
		}
		printf("The sum of the odd numbers is %d.\n", sum);
	}
	return 0;
}
