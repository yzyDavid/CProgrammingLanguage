#include <stdio.h>

void get_char();
int main(void) {
	get_char();
	putchar('\n');
	return 0;
}

void get_char() {
	char s = getchar();
	if (s != '\n') {
		get_char();
		putchar(s);
	}
}