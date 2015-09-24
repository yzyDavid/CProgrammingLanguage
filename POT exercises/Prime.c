#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
	int count = 0, current = 0;
	int num = 2;
	FILE* fpOutput;
	fpOutput = fopen("Prime.txt", "w");
	assert(fpOutput);
	printf("generate ___ prime(s): ");
	scanf("%d", &count);
	assert(count > 0);
	fprintf(fpOutput, "int primes[] = {\n    ");
	while (current < count) {
		int dest = sqrt(num);
		bool flag = true;
		for (int i = 2; i <= dest; ++i) {
			if (num % i == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			fprintf(fpOutput, "%d", num);
			++current;
			if(current != count) {
				fprintf(fpOutput,", ");
			}
			if(current % 10 == 0) {
				fprintf(fpOutput, "\n");
				if(current != count){
					fprintf(fpOutput, "    ");
				}
			}
		}
		++num;
		if(num == 1073741823){
			printf("out of bound error!!! stop\n");
			break;
		}
	}
	fprintf(fpOutput, "};");
	printf("primes have been written into Prime.txt\n");
	fclose(fpOutput);
	getchar();
	getchar();
	return 0;
}
