#include <stdio.h>

typedef struct time_s{
	int hh, mm, ss;
}time_st;

void timenext(time_st *ptime, int n);

int main(void){
	int n;
	int i;
	time_st time;

	for (scanf("%d", &i); i > 0; i--){
		scanf("%d:%d:%d", &time.hh, &time.mm, &time.ss);
		scanf("%d", &n);
		timenext(&time, n);
		printf("time: %d:%d:%d\n", time.hh, time.mm, time.ss);
	}
	return 0;
}

void timenext(time_st *ptime, int n){
	/*
	if (n % 86400 == 0 && n != 0){
		return;
	}
	*/
	ptime->ss += n;
	ptime->mm += (ptime->ss / 60);
	ptime->ss %= 60;
	ptime->hh += (ptime->mm / 60);
	ptime->mm %= 60;
	if (ptime->hh / 24 != 0){
		ptime->hh %= 24;
		timenext(ptime, ptime->hh / 24 * 3600);
	}
	/*
	if (ptime->hh == 0 && ptime->mm == 0 && ptime->ss == 0 && n != 0){
		ptime->hh = 24;
	}
	*/
	return;
}
