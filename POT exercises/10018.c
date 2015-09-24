#include <stdio.h>
void reverse(int num);
int main(void){
	int repeat;
	int num;
	
	for (scanf("%d", &repeat); repeat > 0; repeat --){
		scanf("%d", &num);
		reverse(num);
	}
	
	return 0;
}

void reverse(int num){
	if (num == 0){
		printf("\n");
	}
	else{
		printf("%d", num % 10);
		reverse(num / 10);
	}
}
