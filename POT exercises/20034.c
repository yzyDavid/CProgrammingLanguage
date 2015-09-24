#include <stdio.h>

int main(void){
	int rep;
	int n, i;
	double sum;
	
	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%d", &n);
		sum = 0;
		for (i = 1; i <= 2 * n - 1; i = i + 2){
			sum += 1 / (double)i;
		}
		printf("sum = %.6lf\n", sum);
	}
	return 0;
}
