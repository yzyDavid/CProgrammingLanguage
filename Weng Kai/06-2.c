#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	while ((ch = getchar()) != '#') {
		if (isupper(ch)) putchar(tolower(ch));
		else if (islower(ch)) putchar(toupper(ch));
		else putchar(ch);
	}
	putchar('\n');

	return 0;
}
