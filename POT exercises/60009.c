#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SKIPSPACE while(getchar() != '\n') continue
int main(void) {
	unsigned rep;
	scanf("%d", &rep);
	SKIPSPACE;
	for (unsigned i = 0; i < rep; ++i) {
		char string[100] = "";
		int count = 0;
		gets(string);
		size_t length = strlen(string);
		for (size_t i = 0; i < length; ++i) {
			if (isalpha(string[i]) || ispunct(string[i])) {
				++count;
				do {
					++i;
				} while (!isspace(string[i]) && i < length);
			}
			else if (isspace(string[i])) {
				continue;
			}
			else {
				continue;
			}
		}
		printf("%d", count);
	}
	return 0;
}