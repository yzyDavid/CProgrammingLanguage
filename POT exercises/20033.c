#include <stdio.h>

int main(void){
	int rep;
	int m, n, i;
	double sum;
	
	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%d%d", &m, &n);
		sum = 0.0;
		for (i = m; i <= n; i ++){
			sum += 1 / (double)i;
		}
		printf("sum = %.3f\n", sum);
	}
	return 0;
}
