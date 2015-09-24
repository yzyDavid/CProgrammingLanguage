#include <stdio.h>

int main(void){
	int rep;
	int n, i;
	int index;
	double sum, add;
	
	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%d", &n);
		sum = 1;
		add = (double)4;
		index = -1;
		for (i = 2; i <= n; i ++){
			sum += 1 / add * index;
			add += 3;
			index *= -1;
		}
		printf("sum = %.3lf\n", sum);
	}
	return 0;
}
