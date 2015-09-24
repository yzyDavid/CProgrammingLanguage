#include <stdio.h>
#include <string.h>
unsigned int max_len(char str[][80], int n);
int main(void){
	int i, n;
	char s[10][80];
	
	for (scanf("%d", &n), i = 0; i < n; i ++){
		scanf("%s", s[i]);
	}
	printf("length=%u\n",max_len(s,n));
	return 0;
}

unsigned int max_len(char str[][80], int n){
	int i;
	unsigned int length = 0;
	
	for (i = 0; i < n; i ++){
		if (length < strlen(str[i])){
			length = strlen(str[i]);
		}
	}
	return length;
}
