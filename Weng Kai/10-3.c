#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	gets(str);
	for (int i = strlen(str) - 1; i >= 0; i--)
		putchar(str[i]);
	printf("\n");

	return 0;
}
