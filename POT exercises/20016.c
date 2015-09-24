#include <stdio.h>

int main(void){
	int x = 3;
	int y;
	
	scanf("%d", &x);
	
	y = x * x;
	
	printf("%d = %d * %d\n", y, x, x);
	printf("%d * %d = %d\n", x, x, y);
	
	return 0;
}