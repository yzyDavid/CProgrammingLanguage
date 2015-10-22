#include "stdio.h"
int main(void)
{
	int i, digit, m, n, num, sum;
	int mul;
	int repeat, ri;

	scanf("%d",&repeat);
	for(ri = 1; ri <= repeat; ri++){
		scanf("%d%d", &m, &n);
		printf("result:\n");
		for(i=m;i<=n;i++)
		{
			sum=0;
			num=i;
			while(num/10!=0)
			{
				digit=num%10;
				sum+=digit*digit*digit;
				num/=10;
			}
			sum+=num*num*num;
			if(sum==i)
				printf("%d\n",i);
		}
	}
}
