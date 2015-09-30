#include <stdio.h>

int main(void) 
{
	int num, ans;
	scanf("%d", &num);
	ans = num / 100;
	num %= 100;
	ans += num / 10 * 10;
	ans += num % 10 * 100;
	printf("%d\n", ans);

	return 0;
}
