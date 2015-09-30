#include <stdio.h>
#include <math.h>

int main(void)
{
	int ans, n, t;
	scanf("%d%d", &ans, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t < 0) {
			printf("Game Over\n"); break;
		}
		else if (t == ans && i == 0) {
			printf("Bingo!\n"); break;
		}
		else if (t == ans && i < 3) {
			printf("Lucky You!\n"); break;
		}
		else if (t == ans) {
			printf("Good Guess!\n"); break;
		}
		//else if (i == n - 1) printf("Game Over\n");
		else if (t < ans) printf("Too small\n");
		else printf("Too big\n");
		if (i == n - 1) printf("Game Over\n");
	}

	return 0;
}
