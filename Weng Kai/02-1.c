#include <stdio.h>

int main(void) 
{
	int cm, inch, foot;
	scanf("%d", &cm);
	inch = (int)(cm * 0.3937);
	foot = inch / 12;
	inch %= 12;
	printf("%d %d\n", foot, inch);

	return 0;
}
