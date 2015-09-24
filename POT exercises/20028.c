#include <stdio.h>

int main(void){
	int num;
	int d[4];
	int i;
	
	scanf("%d", &num);
	
	d[0] = num / 1000;
	num -= d[0] * 1000;
	d[1] = num / 100;
	num -= d[1] * 100;
	d[2] = num / 10;
	num -= d[2] * 10;
	d[3] = num;
	
	for (i = 0; i < 4; i++){
		d[i] += 9;
		d[i] %= 10;
	}
	printf("The encrypted number is %d%d%d%d\n", d[2], d[3], d[0], d[1]);
	
	return 0;
}
