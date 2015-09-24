#include <stdio.h>

double mypow(double x, int n);
int main(void){
	int rep;
	double x;
	int n;
	
	for (scanf("%d", &rep); rep > 0; rep --){
		scanf("%lf%d", &x, &n);
		printf("%.2f\n", mypow(x, n));
	}
	return 0;
}

double mypow(double x, int n){
	int i;
	double ans = 1;
	
	for (i = 1; i <= n; i ++){
		ans *= x;
	}
	return ans;
}