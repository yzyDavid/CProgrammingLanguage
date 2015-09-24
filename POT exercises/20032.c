#include <stdio.h>

double func(double x);
int main(void){
	int rep;
	int x, i, sum;

	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%d", &x);
		sum = 0;
		for (i = x; i <= 100; i ++){
			sum += i;
		}
		printf("sum = %d\n", sum);
	}
	return 0;
}
