#include <stdio.h>

int main(void)
{
	char ch, str[100][100];
	int count = 0, c = 0;
	while ((ch = getchar()) != '\n') {
		if (ch == ' ') {
			str[count][c] = '\0';
			count++; c = 0;
		}
		else 
			str[count][c++] = ch;
	}
	str[count][c] = '\0';
	for (int i = count; i > 0; i--)
		printf("%s ", str[i]);
	printf("%s\n", str[0]);

	return 0;
}
