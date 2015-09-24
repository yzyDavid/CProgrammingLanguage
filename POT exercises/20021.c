#include <stdio.h>

double func(double x);
int main(void){
	int rep;
	double x;

	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%lf", &x);
		
		printf("f(%.2lf) = %.1f\n", x, func(x));
	}

	return 0;
}

double func(double x){
	if (x == 0){
		return 0;
	}
	else{
		return 1/x;
	}
}
