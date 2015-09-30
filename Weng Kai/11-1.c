#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char record[10][5][20];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 5; j++)
			scanf("%s", record[i][j]);
	
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int q; scanf("%d", &q);
		if (q >= n || q < 0) { printf("Not Found\n"); continue; }
		printf("%s %s %s %s %s\n", record[q][0], record[q][3], record[q][4], record[q][2], record[q][1]);
	}

	return 0;
}
