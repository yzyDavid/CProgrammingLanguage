#include <stdio.h>

int main(void){
	int mat = 87, eng = 72, com = 93, ave;
	scanf("%d%d%d", &mat, &eng, &com);
	ave = (mat + eng + com) / 3;
	printf("math = %d, eng = %d, comp = %d, average = %d\n", mat, eng, com, ave);
	
	return 0;
}
