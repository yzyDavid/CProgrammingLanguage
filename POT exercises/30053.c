#include <stdio.h>

double price(double x);
int main(void){
	int rep = 0;
	for (scanf("%d", &rep); rep > 0; --rep){
		double x;
		scanf("%lf", &x);
		printf("f(%.2lf) = %.2lf\n", x, price(x));
	}
	return 0;
}

double price(double x){
	if (x < 0){
		return 0;
	}
	else if (x >= 0 && x <= 15){
		return (4*x/3);
	}
	else if (x > 15){
		return /*price(15) +*/ 2.5*(x/* -15 */)-10.5;
	}
}
