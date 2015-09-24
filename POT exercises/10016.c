#include <stdio.h>

int main(void){
	int repeat;
	int n;
	char ans[100];
	int i;
	for (scanf("%d", &repeat); repeat > 0; repeat --){
		scanf("%d", &n);
		ans[0] = 0;
		i = 0;
		while (n > 1){
			ans[i] = n % 2;
			n /= 2;
			i ++;
		}
		if (n == 1){
			ans[i] = n;
		}
		else if (n == 0 && i != 0){
			i --;
		}
		while (i >= 0){
			printf("%d", ans[i]);
			i --;
		}
		printf("\n");
	}
	return 0;
}
