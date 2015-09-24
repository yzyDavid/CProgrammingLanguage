#include <stdio.h>

int main(void){
	int i;

	for (i = 1; i < 100; i++){
		if (i * i <= 999){
			printf("%d ", i * i);
		}
	}
	getchar();
	return 0;
}
