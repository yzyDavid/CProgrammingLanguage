#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define diff ('Z' - 'A' + 1)
void convert(char *ch) {
	*ch = 'Z' - *ch + 'A';
}
int main(void) {
	int rep;
	scanf("%d", &rep);
	getchar();
	while (rep--) {
		char str[90];
		gets(str);
		unsigned i;
		for (i = 0; i < strlen(str); i++) {
			if (isupper(str[i])) {
				convert(&str[i]);
			}
		}
		printf("After replaced: %s\n", str);
	}
	return 0;
}
