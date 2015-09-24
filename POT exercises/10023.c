#include <stdio.h>
#include <string.h>

int main(void){
	int rep;
	char flag;
	int i;
	char *date[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char str[80];
	
	for (scanf("%d", &rep); rep > 0; rep --){
		getchar();
	
		scanf("%s", str);
		flag = 0;
		for (i = 0; i < 7; i ++){
			if (strcmp(str, date[i]) == 0){
				printf("%d\n", i + 1);
				flag = 1;
			}
		}
		if (flag == 0){
			printf("-1\n");
		}
	}
	return 0;
}
