#include <stdio.h>

int main(void){
	int rep;
	int i, l, r;
	
	scanf("%d", &rep);
	while(rep--){
		scanf("%d %d", &l, &r);
		printf("fahr  celsius\n");
		if (l < r){
			for (i = l; i <= r; i += 2){
				printf("%3.0f %6.1f\n", (double)i, 5 * ((double)i - 32) / 9);
			}
		}
	}
	return 0;
}
