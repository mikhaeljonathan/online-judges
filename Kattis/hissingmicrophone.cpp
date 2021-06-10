#include <stdio.h>
#include <string.h>

bool check (char s[]){
	int len = strlen(s);
	for (int i = 0; i < len - 1; i++) if (s[i] == 's' && s[i + 1] == 's') return true;
	return false;
}

int main (){
	char s[50];
	scanf("%[^\n]", s);
	printf("%s\n", check(s) ? "hiss" : "no hiss");
	return 0;
}
