#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101]; int n;
	gets(str);
	scanf("%d", &n);
	n %= strlen(str);
	for (int i = n; i < strlen(str); i++)
		putchar(str[i]);
	for (int i = 0; i < n; i++)
		putchar(str[i]);
	putchar('\n');
		
	return 0;
}
