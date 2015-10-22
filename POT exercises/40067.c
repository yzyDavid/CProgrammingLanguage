#include "stdio.h"
int main(void)
{
    int i, j, n;
    int repeat, ri; 
	
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=2*(n-i);j++)
				printf(" ");
			for(j=1;j<=2*i-1;j++)
				printf("* ");
			printf("\n");
		}
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=2*(n-i);j++)
				printf(" ");
			for(j=1;j<=2*i-1;j++)
				printf("* ");
			printf("\n");
		}
    }
}
