#include <stdio.h>

int main(void)
{
	int n, x, t;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t == x) { 
			printf("%d\n", i); break; 
		}
		else if (i == n - 1) printf("Not Found\n");
	}

	return 0;
}
