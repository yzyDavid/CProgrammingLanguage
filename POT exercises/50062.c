#include <stdio.h>

int fib(int n)
{
	if(n == 1 || n == 2)
	{
		return 1;
	}
	else return fib(n - 1)+fib(n - 2);
}
int main()
{
	int rep;
	int i;
	int l, r;
	int left, right;
	scanf("%d", &rep);
	while(rep--)
	{
		scanf("%d %d", &left, &right);
		for(l = 1; l < 10000; l++)
		{
			if(fib(l) >= left)
			{
				break;
			}
		}
		if (l == 0)
		{
			l = 1;
		}
		for (r = l; r <= 10000; r++)
		{
			if(fib(r) >right)
			{
				break;
			}
		}
		for(i = l; i < r; i++)
		{
			printf("%d ", fib(i));
		}
		printf("\b\n");
	}
	return 0;
}

