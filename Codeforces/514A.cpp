#include <stdio.h>
#include <string.h>

int main(){
	char x[50];
	gets(x);
	int len = strlen(x);
	for (int i = 0; i < len; i++){
		if (i == 0 && x[i] == '9'){
			printf("%c", x[i]);
		} else {
			if (x[i] > '4') printf("%d", '9' - x[i]);
			else printf("%c", x[i]);
		}
	}
	puts("");
	return 0;
}
