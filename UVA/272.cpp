#include <stdio.h>

int main () {
	char x;
	int  key = 0;
	while (scanf("%c", &x) != EOF){
		if (x == '"' && key == 0){
			printf("``");
			if (key == 1){
				key = 0;
			} else {
				key++;
			}
		} else if (x == '"' && key == 1){
			if (key == 1){
				key = 0;
			} else {
				key++;
			}
			printf("''");
		}else {
			printf("%c", x);
		}
		
	}
	return 0;
}
