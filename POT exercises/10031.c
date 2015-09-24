#include <stdio.h>

int main(void) {
	char name[10];
	char label[5];
	int score;
	int i = 1;;
	
	while((label[0] = getchar()) != '0'){
		i = 1;
		while((label[i++] = getchar()) != ' ');
		scanf("%s%d", name, &score);
		while(getchar() != '\n')
			continue;
		i = 0;
		while(label[i] != ' '){
			putchar(label[i]);
			i++;
		}
		printf(" %s %d\n", name, score);
	}
	return 0;
}