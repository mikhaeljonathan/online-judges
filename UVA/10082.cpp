#include <stdio.h>
#include <string.h>

int main () {
	char key[47] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	char input;
	while(scanf("%c", &input) != EOF){
		
		for (int i = 0; i < 47; i++){
			if (input == key[i]){
				printf("%c", key[i - 1]);
				break;
			} else if (input == ' '){
				printf(" ");
				break;
			} else if (input == '\n'){
				printf("\n");
				break;
			}
		}
		
	}
	
	return 0;
}
