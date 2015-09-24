#include <stdio.h>
#include <string.h>

void outputwithout(char* str, char xcpt);
int main() {
	int rep;
	scanf("%d", &rep);
	getchar();
	while (rep--) {
		char str[80];
		gets(str);
		char xcpt = getchar();
		getchar();
		printf("result: ");
		outputwithout(str, xcpt);
		putchar('\n');
	}
	return 0;
}
void outputwithout(char* str, char xcpt) {
	char* tmp = str;
	while (*tmp != '\0') {
		if (*tmp != xcpt) {
			putchar(*tmp);
		}
		tmp++;
	}
}