#include <stdio.h>
int main() {
	int total;
	scanf("%d", &total);
	getchar();
	while (total--) {
		double wag[3];
		char str[10];
		scanf("%s %lf %lf %lf", str, wag, wag + 1, wag + 2);
		getchar();
		printf("%5s 实发工资：%7.2f\n", str, wag[0] + wag[1] - wag[2]);
	}
	return 0;
}
