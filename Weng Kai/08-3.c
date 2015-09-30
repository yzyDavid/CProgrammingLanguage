#include <stdio.h>

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);
	int i = 1;
	while (!num[i]) i++;
	printf("%d", i);
	num[i]--;
	for (i = 0; i < 10; i++) 
		while (num[i]) {
			printf("%d", i);
			num[i]--;
		}
	printf("\n");

	return 0;
}
