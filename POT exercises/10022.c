#include <stdio.h>

int main(void){
	int repeat;
	int month;
	char *name[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
	
	for (scanf("%d", &repeat); repeat > 0; repeat --){
		scanf("%d", &month);
		if (month > 12 || month < 1){
			puts("Wrong input!");
		}
		else{
			puts(name[month]);
		}
	}
	return 0;
}
