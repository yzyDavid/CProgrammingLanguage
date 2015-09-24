#include <stdio.h>

int main(void) {
	int rep;
	for (scanf("%d", &rep); rep > 0; rep--){
		char ch = getchar();
		switch(ch){
		case 'A' : puts("90-100");
			break;
		case 'B' : puts("80-89");
			break;
		case 'C' : puts("70-79");
			break;
		case 'D' : puts("60-69");
			break;
		case 'E' : puts("0-59");
			break;
		case '\n' :
			break;
		default : puts("Invalid input");
			break;
		}
	}
	return 0;
}
