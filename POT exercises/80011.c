#include <stdio.h>

int main(void) {
	int num_list[20];
	int num_count, move;
	scanf("%d %d", &num_count, &move);
	int index;
	for (index = 0; index < num_count; index++) {
		scanf("%d", &num_list[index]);
	}
	int output_count = 0;
	index = num_count - move;
	printf("After move: ");
	while (output_count != num_count) {
		printf("%d ", num_list[index++]);
		if (index == num_count) {
			index = 0;
			
		}
		output_count++;
	}
	puts("");
	return 0;
}
