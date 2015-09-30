#include <stdio.h>

int main(void) 
{
	int speed;
	scanf("%d", &speed);
	printf("Speed: %d - ", speed);
	if (speed > 60) printf("Speeding\n");
	else printf("OK\n");

	return 0;
}
