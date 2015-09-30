#include <stdio.h>
#include <string.h>

int main(void)
{
	int m, n, matrix[21][21], none = 1;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &matrix[i][j]);
	for (int i = 2; i < m; i++)
		for (int j = 2; j < n; j++)
			if (matrix[i][j] > matrix[i - 1][j] && matrix[i][j] > matrix[i + 1][j] &&
				matrix[i][j] > matrix[i][j - 1] && matrix[i][j] > matrix[i][j + 1]) {
					printf("%d %d %d\n", matrix[i][j], i, j);
					none = 0;
			}
	if (none) printf("None %d %d\n", m, n);

	return 0;
}
