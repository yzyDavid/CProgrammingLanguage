#include <stdio.h>

int ack(int m, int n);
int main(void){
	int m, n;
	int repeat;
	
	for (scanf("%d", &repeat); repeat > 0; repeat --){
		scanf("%d%d", &m, &n);
		printf("Ackerman(%d,%d)=%d\n", m, n, ack(m, n));
	}
	return 0;
}

int ack(int m, int n){
	if (m == 0) {
		return n + 1;
	}
	else if (n == 0){
		return ack(m - 1, 1);
	}
	else{
		return ack(m - 1, ack(m, n - 1));
	}
}
