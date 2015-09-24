#include <stdio.h>
#include <math.h>

double fact(int upper);
int main(void) {
	int rep;
	scanf("%d", &rep);
	int i;
	for (i = 0; i < rep; ++i) {
		double x;
		scanf("%lf", &x);
		int upper = 1;
		double ans = 0;
		while (pow(x, (double)upper) / fact(upper) >= 0.00001) {
			ans += pow(x, (double)upper) / fact(upper);
			++upper;
		}
		printf("s = %.2lf\n", ans);
	}
	return 0;
}

double fact(int upper) {
	double ans = 1;
	do {
		ans *= upper;
		--upper;
	} while (upper > 1);
	return ans;
}
