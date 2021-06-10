#include <stdio.h>
#include <string.h>

int main (){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		char s[105];
		scanf(" %s", s);
		for (int j = 0; j < strlen(s); j++){
			if (j % 2 == 0){
				printf("%c", s[j] - 32);
			} else {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
