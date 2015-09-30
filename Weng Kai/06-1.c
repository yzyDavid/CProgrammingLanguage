#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ans = 0; char ch;
	while (isdigit(ch = getchar()))
		ans = ans * 10 + ch - '0';
	for (;;) {
		if (ch == '=') {
			printf("%d\n", ans); break;
		}
		else if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			printf("ERROR\n"); break;
		}
		else {
			int t = 0; char digit;
			while (isdigit(digit = getchar()))
				t = t * 10 + digit - '0';
			if (ch == '+') ans += t;
			else if (ch == '-') ans -= t;
			else if (ch == '*') ans *= t;
			else if (ch == '/' && t) ans /= t;
			else { printf("ERROR\n"); break; }
			ch = digit;
		}
	} 

	return 0;
}
