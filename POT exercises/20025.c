#include <stdio.h>

double func(double x);
int main(void){
	int rep;
	double x;

	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%lf", &x);
		printf("f(%.1f) = %.1f\n", x, func(x));
	}
	return 0;
}

double func(double x){
	if (x != 10){
		return x;
	}
	else{
		return 1 / x;
	}
}
