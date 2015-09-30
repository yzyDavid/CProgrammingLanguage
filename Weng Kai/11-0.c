#include <stdio.h>

int main(void)
{
	double x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double x = x1 + x2, y = y1 + y2;
	if (x < 0 && x > -0.05) x = -x;
	if (y < 0 && y > -0.05) y = -y;
	printf("(%.1f, %.1f)\n", x, y);

	return 0;
}
