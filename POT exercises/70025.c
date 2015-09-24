#include <stdio.h>

int days_of_date(int yyyy, int mm, int dd, int* dom);
int main(void) {
	int rep, yyyy, mm, dd;
	int i;
	int days_of_month[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d", &rep);
	for (i = 0; i < rep; i++) {
		scanf("%d %d %d", &yyyy, &mm, &dd);
		printf("days of year: %d\n", days_of_date(yyyy, mm, dd, days_of_month));
	}
	return 0;
}

int days_of_date(int yyyy, int mm, int dd, int* days_of_month) {
	int days = 0;
	if (((yyyy % 4 == 0) && (yyyy % 100 != 0)) || (yyyy % 400 == 0)) {
		days++;
	}
	int i;
	for(i = 1; i < mm; i++) {
		days += days_of_month[i];
	}
	days += dd;
	return days;
}
