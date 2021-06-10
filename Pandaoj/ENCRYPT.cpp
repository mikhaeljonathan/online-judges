#include <stdio.h>
#include <string.h>

int main () {
	char s[1005];
	gets(s);
	for (int i = 0; i < strlen(s); i++){
		if ((s[i] >= 65) && (s[i] <= 77)){
			printf("%c", s[i] + 13);
		} else if ((s[i] >= 78) && (s[i] <= 90)){
			printf("%c", s[i] - 13);
		} else if ((s[i] >= 97) && (s[i] <= 109)){
			printf("%c", s[i] + 13);
		} else if ((s[i] >= 109) && (s[i] <= 122)){
			printf("%c", s[i] - 13);
		} else {
			printf("%c", s[i]);
		}
	}
	printf("\n");
	return 0;
}
