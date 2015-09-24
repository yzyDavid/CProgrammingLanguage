#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion(char *color[], int n, int b);
int main(void){
	int i, b, n = 0;
	char *color[20], str[10];

	scanf("%s", str);
	while(str[0] != '#'){
		color[n] = (char *)malloc(sizeof(char) * 10);  
		memset(color[n], sizeof(char) * 10, 0);
		strcpy(color[n], str);
		n ++;
		scanf("%s", str);
	}
	for (b = 9; b >= 0; b--){
		insertion(color, n, b);
	}
	for(i = 0; i < n; i++){
		printf("%s  ", color[i]);
	}
	printf("\n");
	getchar();
	getchar();
	return 0;
}

void insertion(char *color[], int n, int b){
	char *temp;
	int i, j;
	char key;
	for (i = 1; i < n; i ++){
		j = i - 1;
		key = *(color[i] + b);
		temp = color[i];
		while (j >= 0 && key < *(color[j] + b)){
			color[j+1] = color[j];
			j --;
		}
		color[j + 1] = temp;
	}
	return;
}
	