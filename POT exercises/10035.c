#include <stdio.h>

int main(void){
	int list[30];
	int i, j;
	int l1, l2;
	l1 = 0;
	while(scanf("%d", &(list[l1])), list[l1] != -1)
		l1++;
	while(scanf("%d", &(list[l1])), list[l1] != -1)
		l1++;
	for (i = 1; i < l1; i++){
		for(j = 1; j < l1; j++){
			if(list[j-1] > list[j]){
				int tmp = list[j];
				list[j] = list[j-1];
				list[j-1] = tmp;
			}
		}
	}
	for (i = 0; i < l1; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}