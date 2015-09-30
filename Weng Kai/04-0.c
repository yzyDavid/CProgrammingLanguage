#include <stdio.h>

int main(void) 
{
	int a, counter = 0;
	scanf("%d", &a);
	for (int i = a; i < a + 4; i++)
		for (int j = a; j < a + 4; j++) if (i != j)
			for (int k = a; k < a + 4; k++)  if (i != k && j != k) {
				printf("%d%d%d", i, j, k);
				counter++;
				if (counter == 6) { printf("\n"); counter = 0; }
				else printf(" ");
			}

	return 0;
}
