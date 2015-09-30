#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	gets(str);
	char ch = getchar();
	int find = -1;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == ch) {
			find = i; break;
		}
	if (find == -1) printf("Not found\n");
	else {
		for (int i = find; i < strlen(str); i++)
			putchar(str[i]);
		putchar('\n');
	}

	return 0;
}
