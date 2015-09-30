#include <stdio.h>

int main(void) 
{
	int currentTime, laterTime, minutes;
	scanf("%d%d", &currentTime, &minutes);
	laterTime = currentTime % 100 + minutes;
	if (laterTime < 0) {
		int hours = 0;
		while (laterTime < 0) {
			hours++;
			laterTime += 60;
		} 
		laterTime += (currentTime / 100 - hours) * 100;
	}
	else if (laterTime >= 60) {
		int hours = 0;
		while (laterTime >= 60) {
			hours++;
			laterTime -= 60;
		}
		laterTime += (currentTime / 100 + hours) * 100;
	}
	else laterTime += currentTime / 100 * 100;
	//printf("%04d\n", laterTime);
	printf("%d\n", laterTime);


	return 0;
}
