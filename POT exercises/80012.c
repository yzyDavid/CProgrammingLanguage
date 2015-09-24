#include <stdio.h>

int main(void) {
	int rep;
	scanf("%d", &rep);
	while (rep--) {
		int num_count;
		scanf("%d", &num_count);
		int i;
		int list[10];
		for (i = 0; i < num_count; i++) {
			scanf("%d", &list[i]);
		}
		int scan;
		int not_found = 1;
		scanf("%d", &scan);
		for (i = 0; i < num_count; i++) {
			if (list[i] == scan) {
				printf("index = %d\n", i);
				not_found = 0;
				break;
			}
		}
		if (not_found) {
			printf("Not found\n");
		}
	}
	return 0;
}
