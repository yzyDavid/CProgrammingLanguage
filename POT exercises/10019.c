#include <stdio.h>

double func(double x, int n);
int main(void){
	int n;
	double x;
	
	scanf("%lf%d", &x, &n);
	printf("Root = %0.2lf\n", func(x, n));
	return 0;
}

double func(double x, int n){
	if (n == 1){
		return x;
	}
	else{
		return x * func(x, n - 1);
	}
}
