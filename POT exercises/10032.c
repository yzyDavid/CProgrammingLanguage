#include <stdio.h>

typedef struct {
	int label;
	char name[20];
	int score;
}student_t;

int main(void){
	student_t students[100];
	int i = 0;
	while(scanf("%d", &(students[i].label)), students[i].label != 0){
		getchar();
		scanf("%s %d", students[i].name, &(students[i].score));
		i++;
	}
	int limit;
	int j = 0;
	scanf("%d", &limit);
	for(j = 0; j < i; j++){
		if(students[j].score >= limit){
			printf("%d %s %d\n", students[j].label, students[j].name, students[j].score);
		}
	}
	return 0;
}