#include <stdio.h>
#include <string.h>

void output(char slist[4][20])
{
	int i;
	for(i = 0; i < 4; i++)
	{
		int len = 0;
		while(slist[i][len])
		{
			len ++;
		}
		printf("%s", slist[i] + len - 2);
	}
}
int main()
{
	char slist[4][20];
	int i;
	for(i = 0; i < 4; i++)
	{
		scanf("%s", slist[i]);
	}
	output(slist);
	return 0;
}
