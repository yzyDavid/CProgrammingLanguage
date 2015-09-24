#include <stdio.h>

int fib(int n);
int main(void){
	int repeat;
	int n;
	
	for (scanf("%d", &repeat); repeat > 0; repeat --){
		scanf("%d", &n);
		printf("fib(%d)=%ld\n",n,fib(n));
	}
	
	return 0;
}

int fib(int n){
	if (n == 0) {
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	else{
		return (fib(n - 2) + fib(n - 1));
	}
}
