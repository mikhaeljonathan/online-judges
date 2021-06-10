#include <stdio.h>
#include <string.h>

int main (){
	char s[55];
	gets(s);
	int len = strlen(s);
	int a = 0;
	for (int i = 0; i < len; i++) if (s[i] == 'a') a++;
	int nota = len - a;
	if (a <= nota) len = a * 2 - 1;
	printf("%d\n", len);
	return 0;
}
