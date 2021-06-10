#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char s[n + 3];
	gets(s);
	int res = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '+') res++;
		else res--;
		if (res < 0) res = 0;
	}
	printf("%d\n", res);
	return 0;
}
