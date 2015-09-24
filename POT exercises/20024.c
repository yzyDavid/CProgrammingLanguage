#include <stdio.h>
#include <math.h>

double func(double x);
int main(void){
	int rep;
	double x;

	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%lf", &x);
		printf("f(%.2lf) = %.2lf\n", x, func(x));
	}
	return 0;
}

double func(double x){
	if (x >= 0){
		return sqrt(x);
	}
	else{
		return pow(x + 1, 2.0) + 2 * x + 1 / x;
	}
}
