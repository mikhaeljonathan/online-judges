#include <stdio.h>
#include <string.h>

int main () {
	char x[305];
	scanf("%s", x);
	char now[3] = {'P','E','R'};
	int res = 0;
	for (int i = 0; i < strlen(x); i++){
		if (x[i] != now[i % 3]){
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
