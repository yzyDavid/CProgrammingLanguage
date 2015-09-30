#include <stdio.h>

int main(void)
{
	char ch; 
	int count = 0, first = 1, blank = 1;
	while ((ch = getchar()) != '.') {
		if (ch == ' ' && first && !blank) {
			printf("%d", count); 
			count = 0; first = 0; blank = 1; 
		}
		else if (ch == ' ' && !first && !blank) {
			printf(" %d", count);
			count = 0; blank = 1; 
		}
		else if (ch == ' ') continue;
		else {
			count++; blank = 0;
		}
	}
	if (first && !blank) printf("%d", count);
	else if (!blank) printf(" %d", count);
	printf("\n");

	return 0;
}
