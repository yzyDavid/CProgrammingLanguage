#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void){
	double a, b, c;
	int rep;
	
	scanf("%d", &rep);
	while(rep--){
		scanf("%lf%lf%lf", &a, &b, &c);
		
		if 		(a == 0 && b == 0 && c == 0){
			printf("参数都为零，方程无意义!\n");
		}
		else if (a == 0 && b == 0 && c != 0){
			printf("a和b为0，c不为0，方程不成立\n");
		}
		else if (a == 0 && b != 0 && c != 0){
			printf("x = %0.2f\n", -c/b);
		}
		else if (b * b - 4 * a * c > FLT_EPSILON){
			printf("x1 = %0.2f\n", (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
			printf("x2 = %0.2f\n", (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
		}
		else{
			printf("x1 = %0.2f+%0.2fi\n", -b / (2 * a), sqrt(-b * b + 4 * a * c) / (2 * a));
			printf("x2 = %0.2f-%0.2fi\n", -b / (2 * a), sqrt(-b * b + 4 * a * c) / (2 * a));
		}
	}
	
	return 0;
}
