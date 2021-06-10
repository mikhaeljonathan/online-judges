#include <stdio.h>
#include <string.h>

int endPo(char s[], int len){
	if (s[len - 1] == 'o' && s[len - 2] == 'p') return 1;
	return 0;
}

int endMnida(char s[], int len){
	if (s[len - 1] == 'a' && s[len - 2] == 'd' && s[len - 3] == 'i' && s[len - 4] == 'n' && s[len - 5] == 'm') return 1;
	return 0;
}

int main (){
	int t;
	scanf("%d", &t); getchar();
	while (t--){
		char s[1005];
		gets(s);
		int len = strlen(s);
		if (endPo(s, len)) puts("FILIPINO");
		else if (endMnida(s, len)) puts("KOREAN");
		else puts("JAPANESE");
	}
	return 0;
}
