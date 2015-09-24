#include <stdio.h>
#include <string.h>
char* bigger(char* s1, char* s2);
int main(void) {
	char str[80], big[80];
	gets(big);
	int i = 0;
	for (i = 0; i < 4; i++) {
		gets(str);
		strcpy(big, bigger(big, str));
	}
	printf("Max is: %s\n", big);
}

char* bigger(char* s1, char* s2) {
	unsigned shortlen = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
	unsigned i;
	for (i = 0; i < shortlen; ++i) {
		if (s1[i] > s2[i]) {
			return s1;
		} else if (s1[i] < s2[i]) {
			return s2;
		}
	}
	return strlen(s1) > strlen(s2) ? s1 : s2;
}