#include <stdio.h>
#include <string.h>

int main(void) {
	char str[80];
	int rep;
	scanf("%d", &rep);
	getchar();
	while (rep--) {
		gets(str);
		unsigned i;
		char flag = 1;
		for (i = 0; i < strlen(str)/2 - 1; i++) {
			if (str[i] != str[strlen(str)-1-i]) {
				printf("NO\n");
				flag = 0;
				break;
			}
		}
		if (flag) printf("YES\n");
	}
	return 0;
}
