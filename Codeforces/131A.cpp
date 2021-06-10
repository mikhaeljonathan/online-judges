#include <stdio.h>
#include <string.h>

bool caps(char *s, int len){
	for (int i = 1; i < len; i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			return false;
		}
	}
	return true;
}


int main () {
	char s[105];
	gets(s);
	int len = strlen(s);
	if (caps(s, len)){
		for (int i = 0; i < len; i++){
			if (s[i] >= 'A' && s[i] <= 'Z'){
				s[i] += 'a' - 'A';
			} else if (s[i] >= 'a' && s[i] <= 'z'){
				s[i] -= 'a' - 'A';
			}
		}
	}
	printf("%s\n", s);
	return 0;
} 
