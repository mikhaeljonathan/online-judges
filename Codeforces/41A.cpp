#include <stdio.h>
#include <string.h>

int main (){
	char s[105];
	gets(s);
	char t[105];
	gets(t);
	
	char temp[105];
	int j = 0;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--, j++){
		temp[j] = s[i];
	}
	temp[len] = '\0';
	if (!strcmp(temp, t)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
