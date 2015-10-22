#include "stdio.h"
int main(void)
{
	int count, f1, f2, f5, money;
	int repeat, ri;


	scanf("%d", &repeat);
	for(ri = 1; ri <= repeat; ri++){
		scanf("%d", &money);
		count=0;
		for(f5=money/5;f5>0;f5--)
		{
			for(f2=money/2;f2>0;f2--)
			{
				for(f1=money;f1>0;f1--)
				{
					if((f1+f2*2+f5*5)==money)
						printf("fen5:%d,fen2:%d,fen1:%d,total:%d\n",f5, f2, f1, f5+f2+f1),count++;
				}
			}
		}
		printf("count = %d\n", count);
	}
}
