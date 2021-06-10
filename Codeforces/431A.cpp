#include <stdio.h>
#include <string.h>

int main (){
	int a1, a2, a3, a4;
	scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
	getchar();
	char s[100005];
	gets(s);
	long long res = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		if (s[i] == '1') res += a1;
		else if (s[i] == '2') res += a2;
		else if (s[i] == '3') res += a3;
		else res += a4;
	}
	printf("%lld\n", res);
	return 0;
}
