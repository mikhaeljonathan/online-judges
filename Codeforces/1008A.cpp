#include <stdio.h>
#include <string.h>

bool vowel(char s){
	if (s == 'a' || s == 'i' || s == 'u' || s == 'e' || s== 'o') return true;
	return false;
}

bool test(char s[], int len){
	for (int i = 0; i < len; i++) if (s[i] != 'n' && !vowel(s[i]) && !vowel(s[i + 1])) return false;
	return true;
}

int main (){
	char s[105];
	gets(s);
	int len = strlen(s);
	s[len] = 'b';
	s[len + 1] = '\0';
	printf("%s\n", (test(s, len)) ? "YES" : "NO");
	return 0;
}
