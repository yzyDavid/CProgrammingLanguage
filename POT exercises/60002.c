#include <stdio.h>

int main(void) {
	int rep;
	scanf("%d", &rep);
	int i = 0;
	for (i = 0; i < rep; ++i) {
		int num10, num8, num16;
		scanf("%d %o %x", &num10, &num8, &num16);
		printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n", num10, num10, num10);
		printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n", num8, num8, num8);
		printf("The decimal is %d, the octal is %o, the hexadecimal is %x.\n", num16, num16, num16);
	}
	return 0;
}
	