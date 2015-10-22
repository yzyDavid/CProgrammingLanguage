#include <stdio.h>
int main(void)
{
	int factor, m, n, num, sum;
	int repeat, ri;
	int i;

	scanf("%d",&repeat);
	for(ri = 1; ri <= repeat; ri++){
		scanf("%d%d", &m, &n);
		printf("result:\n"); 
		for(i=m;i<=n;i++)
		{
			num=i;
			factor=1;
			sum=0;
			while(factor<=(i/2+1))
			{
				if(num%factor==0)
					sum+=factor;
				factor++;
			}
			if(sum==num)
			{
				factor=2;
				printf("%d = 1",num);
				while(factor<=(i/2+1))
				{
					if(num%factor==0)
						printf(" + %d",factor);
					factor++;
				}
				printf("\n");
			}
		}
	}
	return 0;
}
