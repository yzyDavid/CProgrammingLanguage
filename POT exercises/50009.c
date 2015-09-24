#include <stdio.h>

double sin_e(double e, double x, int n, int i);
double step(int n);
double pow_e(double x, int n);
int main(void) {
	int rep = 0;
	int i = 0;
	scanf("%d", &rep);
	for (i = 0; i < rep; ++i) {
		double e, x;
		scanf("%lf %lf", &e, &x);
		printf("sum = %lf\n", sin_e(e, x, 0, 1));
	}
	return 0;
}

double sin_e(double e, double x, int n, int i) {
	double tmp = pow_e(x, n) / step(n);
	if (tmp < e) {
		return tmp * i;
	}
	else {
		return tmp * i + sin_e(e, x, n + 2, -i);
	}
}

double step(int n) {
	if (n != 0) {
		if (n == 1) {
			return 1;
		}
		else {
			return n * step(n - 1);
		}
	}
	else {
		return 1;
	}
}

double pow_e(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return x * pow_e(x, n - 1);
	}
}