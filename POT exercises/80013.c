#include <stdio.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int* list, int beg, int end) {
	if (beg < end) {
		int mid = beg;
		int i = beg;
		for (i = beg; i < end; i++) {
			if (list[i] < list[end]) {
				swap(&list[i], &list[mid]);
				mid++;
			}
		}
		swap(&list[end], &list[mid]);
		quick_sort(list, beg, mid - 1);
		quick_sort(list, mid + 1, end);
	}
}
int main(void) {
	int rep = 0;
	int list[100];
	int i;
	int n;
	scanf("%d", &rep);
	while (rep--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}
		quick_sort(list, 0, n - 1);
		printf("After sorted: ");
		for (i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		puts("");
	}
	return 0;
}
