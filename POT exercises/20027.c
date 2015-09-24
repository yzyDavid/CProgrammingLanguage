#include <stdio.h>

int main(void){
	int t1, t2;
	int h1, h2, m1, m2;
	int dh, dm;
	
	scanf("%d%d", &t1, &t2);
	h1 = t1 / 100;
	m1 = t1 - h1 * 100;
	h2 = t2 / 100;
	m2 = t2 - h2 * 100;
	if (m2 < m1){
		h2 --;
		m2 += 60;
	}	
	dh = h2 - h1;
	dm = m2 - m1;
	
	printf("The train journey time is %d hours %d minutes.\n", dh, dm);
	
	getchar();
	getchar();
	
	return 0;
}