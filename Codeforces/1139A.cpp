#include <stdio.h>
#include <string.h>

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n + 3];
	gets(s);
	int len = strlen(s);
	int res = 0;
	for (int i = 0; i < len; i++)
		if ((s[i] - '0') % 2 == 0) res += i + 1;
	printf("%d\n", res);
	return 0;
}
