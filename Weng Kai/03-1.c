#include <stdio.h>

int main(void) 
{
	int day;
	scanf("%d", &day);
	if ((day - 1) % 5 < 3) printf("Fishing in day %d\n", day);
	else printf("Drying in day %d\n", day);

	return 0;
}
