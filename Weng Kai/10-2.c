#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[100], s2[100];
	gets(s1); gets(s2);
	char *find;
	while (find = strstr(s1, s2))
		for (int i = find - s1 + strlen(s2); i <= strlen(s1); i++)
			s1[i - strlen(s2)] = s1[i];
	printf("%s\n", s1);


	return 0;
}
