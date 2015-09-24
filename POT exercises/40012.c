#include <stdio.h>
#include <math.h>

int main(void){
	int rep = 0;
	scanf("%d", &rep);
	while(rep--){
		double dest;
		double ans = 1;
		int a = 1;
		int flag = -1;
		scanf("%le", &dest);
		while(fabs(1.0 / a) >= dest){
			ans += flag * 1.0 / (a + 3);
			flag *= -1;
			a += 3;
		}
		printf("sum = %.6f\n", ans);
	}
	return 0;
}
