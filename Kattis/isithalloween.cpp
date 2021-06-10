#include <stdio.h>
#include <string.h>

int main (){
	char s[10];
	scanf("%[^\n]", s);
	getchar();
	if (!strcmp(s, "OCT 31") || !strcmp(s, "DEC 25")) printf("yup\n");
	else printf("nope\n");
	return 0;
}
