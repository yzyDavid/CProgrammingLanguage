#include <stdio.h>

double mypow(double x, int n);
int main(void){
	int n;
	int i;
	for (scanf("%d", &n), i = 0; i <= n; i ++){
		printf("pow(3,%d) = %.0lf\n", i, mypow((double)3, i));
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
