#include <stdio.h>

int main(void){
	int n = 152;
	int d1, d2, d3;

	scanf("%d", &n);
	d1 = n / 100;
	n -= d1 * 100;
	d2 = n / 10;
	n -= d2 * 10;
	d3 = n;
	n = d1 * 100 + d2 * 10 + d3;
	printf("整数%d的个位数字是%d, 十位数字是%d, 百位数字是%d\n", n, d3, d2, d1);
	return 0;
}
