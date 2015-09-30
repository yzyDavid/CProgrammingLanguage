#include <stdio.h>

const char *pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(void)
{
	char ch; int tot = 0;
	while ((ch = getchar()) != '\n')
		tot += ch -'0';
	int digit[3];
	digit[2] = tot % 10;
	tot /= 10;
	digit[1] = tot % 10;
	tot /= 10;
	digit[0] = tot;
	if (digit[0])
		printf("%s %s %s\n", pinyin[digit[0]], pinyin[digit[1]], pinyin[digit[2]]);
	else if (digit[1]) 
		printf("%s %s\n", pinyin[digit[1]], pinyin[digit[2]]);
	else printf("%s\n", pinyin[digit[2]]);

	return 0;
}
