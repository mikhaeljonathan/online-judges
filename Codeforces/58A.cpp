#include <stdio.h>
#include <string.h>

bool test (char s[]){
	int len = strlen(s);
	char key[] = "hello";
	int keyindex = 0;
	for (int i = 0; i < len; i++){
		if (s[i] == key[keyindex]) keyindex++;
		if (keyindex == 5) return true;
	}
	return false;
}

int main (){
	char s[105];
	gets(s);
	int len = strlen(s);
	printf("%s\n", (test(s)) ? "YES" : "NO");
	return 0;
}
