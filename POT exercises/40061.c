#include <stdio.h>
int main(void)
{
    int sum, x;
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
		sum=0;
		do
		{
			scanf("%d",&x);
			if(!x>0)
				break;
			if(0==x%2)
				sum+=x;
		}
		while(x>0);
        printf("The sum of the even numbers is %d.\n", sum);
    }
}
