#include <stdio.h>

const char *pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(void)
{
	int first = 1; char ch;
	while ((ch = getchar()) != '\n') {
		if (first) first = 0;
		else printf(" ");
		if (ch == '-') printf("fu");
		else printf("%s", pinyin[ch - '0']);
	}
	printf("\n");

	return 0;
}
