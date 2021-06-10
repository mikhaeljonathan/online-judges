#include <stdio.h>
#include <string.h>

int main (){
	char in[15];
	int cases = 1;
	while (scanf("%s", in) && strcmp(in, "#")){
		printf("Case %d: ", cases++);
		if (!strcmp(in, "HELLO")) puts("ENGLISH");
		else if (!strcmp(in, "HOLA")) puts("SPANISH");
		else if (!strcmp(in, "HALLO")) puts("GERMAN");
		else if (!strcmp(in, "BONJOUR")) puts("FRENCH");
		else if (!strcmp(in, "CIAO")) puts("ITALIAN");
		else if (!strcmp(in, "ZDRAVSTVUJTE")) puts("RUSSIAN");
		else puts("UNKNOWN");
	}
	return 0;
}
