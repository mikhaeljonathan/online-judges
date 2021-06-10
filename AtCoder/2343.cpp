#include <stdio.h>

int main () {
	char a, b;
	scanf("%c %c", &a, &b);
	bool temp = a == 'H';
	bool temp2 = b == 'H';
	
	if (temp ^ temp2){
		puts("D");
	} else {
		puts("H");
	}
	return 0;
}
