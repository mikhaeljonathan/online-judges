#include <stdio.h>

int main () {
	char s[1005];
	gets(s);
	if (s[0] >= 'a' && s[0] <= 'z'){
		s[0] -= 'a' - 'A';
	}
	printf("%s\n", s);
	return 0;
}
