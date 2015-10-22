#include "stdio.h"
int main(void)
{
	int i, j, n;
	int repeat, ri;
	double e, product;

	scanf("%d", &repeat);
	for(ri = 1; ri <= repeat; ri++)
	{
		e=1;
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			product=1;
			for(j=1;j<=i;j++)
			{
				product*=j;
			}
			e+=1.0/product;
		}
		printf("e = %0.4f\n", e);
	}
}
