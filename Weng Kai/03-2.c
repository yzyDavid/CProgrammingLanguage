#include <stdio.h>

int main(void) 
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a != b && a != c) printf("A\n");
	else if (b != a && b != c) printf("B\n");
	else printf("C\n");

	return 0;
}
