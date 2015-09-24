#include <stdio.h>

double p(int n, double x);
int main(void){
	int repeat;
	int n;
	double x;
	scanf("%d", &repeat);
	while(repeat --){
		scanf("%d%lf", &n, &x);
		printf("p(%d, %.2f)=%.2f\n", n, x, p(n, x));
	}
	return 0;
	
}

double p(int n, double x){
	if (n == 0){
		return 1;
	}
	else if (n == 1){
		return x;
	}
	else if (n > 1){
		return (((2 * n - 1) * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n);
	}
}
