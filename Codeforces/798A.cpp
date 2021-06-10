#include <stdio.h>
#include <string.h>

int main () {
	char s[20];
	gets(s);
	int key = 0;
	int indexleft = 0;
	int indexright = strlen(s) - 1;
	while (indexleft <= indexright){
		if (s[indexleft] != s[indexright]){
			key++;
		}
		indexleft++;
		indexright--;
	}

	if (key == 1){
		puts("YES");
	} else if (key == 0 && strlen(s) % 2 == 1){
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
