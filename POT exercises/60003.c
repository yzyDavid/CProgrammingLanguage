#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	int rep;
	scanf("%d", &rep);
	getchar();
	int i;
	for (i = 0; i < rep; ++i) {
		char buffer[100];
		gets(buffer);
		int length = strlen(buffer);
		int j;
		int alpha = 0, space = 0, punct = 0, num = 0;
		for (j = 0; j < length; ++j) {
			if (isalpha(buffer[j])) {
				++alpha;
			}
			else if (isspace(buffer[j])) {
				++space;
			}
			else if (ispunct(buffer[j])) {
				++punct;
			}
			else if (isdigit(buffer[j])) {
				++num;
			}
			else {
				return -1;
			}
		}
		printf("letter = %d, blank = %d, digit = %d, other = %d\n", alpha, space, num, punct);
	}
	return 0;
}
