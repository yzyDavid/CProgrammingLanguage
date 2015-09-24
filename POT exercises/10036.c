#include <stdio.h>

int main(void){
	int list[30];
	int i, j;
	i = 0;
	while(scanf("%d", &(list[i])), list[i] != -1)
		i++;
	j = 0;
	while(j <= i-1){
		if(list[j] % 2 != 0){
			printf("%d ", list[j]);
		}
		j++;
	}
	printf("\n");
	return 0;
}