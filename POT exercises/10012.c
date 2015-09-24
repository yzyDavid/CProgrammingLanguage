#include <stdio.h>
#include <math.h>

int main(void){
	int repeat;
	int num;
	int list[] = {121, 144, 225, 400, 441, 484, 676, 900, 99999};
	int i;
	scanf("%d", &repeat);
	while(repeat--){
		scanf("%d", &num);
		
		i = 0;
		while (list[i] < num){
			i ++;
		}
		printf("count=%d\n", i);
	}
	return 0;
}