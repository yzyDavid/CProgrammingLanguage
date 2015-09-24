#include <stdio.h>

int main(void){
	int list[30];
	int i;
	i = 0;
	while(scanf("%d", &(list[i])), list[i] != -1)
		i++;
	while(--i >= 0){
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}