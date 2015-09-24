#include <stdio.h>

void bonce(double* height, double* distance, int times);
int main(void){
	int rep;
	
	for(scanf("%d", &rep); rep > 0; --rep){
		double height = 0, distance = 0;
		int times = 0;
		scanf("%lf%d", &height, &times);
		bonce(&height, &distance, times);
		printf("distance = %.1f, height = %.1f\n", distance, height);
	}
	return 0;
}

void bonce(double* height, double* distance, int times){
	if (times == 1){
		*distance += *height;
		*height /= 2;
	}
	else{
		*distance += *height;
		*height /= 2;
		*distance += *height;
		bonce(height, distance, times - 1);
	}
	return;
}
