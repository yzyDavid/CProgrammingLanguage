#include <stdio.h>

int main(void) {
	int i, n;
	int maxI = 0;
	typedef struct student_t {
		int number;
		char name[20];
		int score[3];
		int sum;
	}student;
	student stu[10];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%d %s %d %d %d", &stu[i].number, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].sum = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		if (stu[i].sum > stu[maxI].sum) {
			maxI = i;
		}
	}

	printf("总分最高的学生是: %s，%d分\n", stu[maxI].name, stu[maxI].sum);
}
